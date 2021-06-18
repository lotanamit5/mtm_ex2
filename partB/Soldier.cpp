#include "Auxiliaries.h"
#include "Exceptions.h"
#include "Character.h"
#include "Soldier.h"

#include <memory>
#include <map>
#include <vector>
#include <iterator>
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

    void Soldier::attack(std::map<GridPoint,std::shared_ptr<Character>> &board,
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

        std::shared_ptr<Character> target = board.at(dst_coordinates);
        if (target && target->isEnemy(team))
        {
            if (target->takeDamage(power))
            {
                board.erase(dst_coordinates);
            }
        }
        std::vector<GridPoint> kills;
        for (std::map<GridPoint,std::shared_ptr<Character>>::iterator itr = board.begin(); itr != board.end(); ++itr)
        {
            if (GridPoint::distance(dst_coordinates, itr->first) <= (int)ceil((double)range / 3.0))
            {
               target = itr->second;
                if (target && target->isEnemy(team))
                {
                    if (target->takeDamage((int)ceil((double)power / 2.0)))
                    {
                        kills.push_back(itr->first);
                    }
                }
            }
        }
        for (GridPoint target : kills)
        {
            board.erase(target);
        }
        ammo -= attack_cost;
    }
    CharacterType Soldier::getType()
    {
        return CharacterType::SOLDIER;
    }
}