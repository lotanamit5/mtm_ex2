#include "Auxiliaries.h"
#include "Exceptions.h"
#include "Character.h"
#include "Sniper.h"
#include <vector>
#include <cmath>

#define MEDIC_MOVEMENT_RANGE 4
#define MEDIC_RELOAD_AMOUNT 2
#define MEDIC_ATTACK_COST 1

namespace mtm
{
    Sniper::Sniper(units_t health, units_t ammo, units_t range, units_t power, Team team)
        : Character(health, ammo, range, power, MEDIC_MOVEMENT_RANGE, MEDIC_RELOAD_AMOUNT, MEDIC_ATTACK_COST, team), shots_fired(0) {}

    std::shared_ptr<Character> Sniper::clone() const
    {
        std::shared_ptr<Character> ptr(new Sniper(*this));
        return ptr;
    }
    void Sniper::attackInRange(const GridPoint &src_coordinates, const GridPoint &dst_coordinates)
    {
        Character::attackInRange(src_coordinates, dst_coordinates);
        if (GridPoint::distance(dst_coordinates, src_coordinates) < (int)ceil((double)range / 2.0))
        {
            throw OutOfRange();
        }
    }
    void Sniper::attack(std::vector<std::vector<std::shared_ptr<Character>>> &board,
                        const GridPoint &src_coordinates, const GridPoint &dst_coordinates)
    {
        attackInRange(src_coordinates, dst_coordinates);
        if (ammo <= 0)
        {
            throw OutOfAmmo();
        }

        std::shared_ptr<Character> target = board.at(dst_coordinates.row).at(dst_coordinates.col);
        if (!target)
        {
            throw IllegalTarget();
        }

        std::shared_ptr<Character> target = board.at(dst_coordinates.row).at(dst_coordinates.col);
        if (target && target->isEnemy(team))
        {
            shots_fired++;
            if (target->takeDamage(shots_fired % 3 ? power : 2 * power))
            {
                target.reset();
            }
        }
        else
        {
            throw IllegalTarget();
        }
        ammo -= attack_cost;
    }
    CharacterType getType()
    {
        return CharacterType::SNIPER;
    }
}