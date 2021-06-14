#include "Auxiliaries.h"
#include "Exceptions.h"
#include "Character.h"
#include "Soldier.h"

#include <memory>
#include <vector>
#include <cmath>

#define SOLDIER_MOVEMENT_RANGE 3
#define SOLDIER_RELOAD_AMOUNT 5
#define SOLDIER_ATTACK_COST 1

namespace mtm
{
    Soldier::Soldier(units_t health, units_t ammo, units_t range, units_t power, Team team)
        : Character(health, ammo, range, power, SOLDIER_MOVEMENT_RANGE, SOLDIER_RELOAD_AMOUNT, SOLDIER_ATTACK_COST, team) {}

    std::shared_ptr<Character> Soldier::clone() const
    {
        std::shared_ptr<Character> ptr(new Soldier(*this));
        return ptr;
    }

    void Soldier::attack(std::vector<std::vector<std::shared_ptr<Character>>> &board,
                         const GridPoint &src_coordinates, const GridPoint &dst_coordinates)
    {
        attackInRange(src_coordinates, dst_coordinates);
        if (ammo <= 0)
        {
            throw OutOfAmmo();
        }
        if (src_coordinates.row != dst_coordinates.row && src_coordinates.col != dst_coordinates.col)
        {
            throw IllegalTarget();
        }

        std::shared_ptr<Character> target = board.at(dst_coordinates.row).at(dst_coordinates.col);
        if (target && target->isEnemy(team))
        {
            if (target->takeDamage(power))
            {
                target.reset();
            }
        }
        int r = 0, c = 0;
        for (std::vector<std::shared_ptr<Character>> row : board)
        {
            for (std::shared_ptr<Character> character : row)
            {
                GridPoint current_cell(r, c);
                if (GridPoint::distance(dst_coordinates, current_cell) <= (int)ceil((double)range / 3.0))
                {
                    std::shared_ptr<Character> target = board.at(r).at(c);
                    if (target && target->isEnemy(team))
                    {
                        if (target->takeDamage((int)ceil((double)power / 2.0)))
                        {
                            target.reset();
                        }
                    }
                }
                c++;
            }
            r++;
        }
        ammo -= attack_cost;
    }
    CharacterType Soldier::getType() 
    {
        return CharacterType::SOLDIER;
    }
}