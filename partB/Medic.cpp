#include "Auxiliaries.h"
#include "Exceptions.h"
#include "Character.h"
#include "Medic.h"
#include <vector>

#define MEDIC_MOVEMENT_RANGE 5
#define MEDIC_RELOAD_AMOUNT 3
#define MEDIC_ATTACK_COST 1

namespace mtm
{
    Medic::Medic(units_t health, units_t ammo, units_t range, units_t power, Team team)
        : Character(health, ammo, range, power, MEDIC_MOVEMENT_RANGE, MEDIC_RELOAD_AMOUNT, MEDIC_ATTACK_COST, team) {}

    std::shared_ptr<Character> Medic::clone() const
    {
        std::shared_ptr<Character> ptr(new Medic(*this));
        return ptr;
    }

    void Medic::attack(std::vector<std::vector<std::shared_ptr<Character>>> &board,
                       const GridPoint &src_coordinates, const GridPoint &dst_coordinates)
    {
        attackInRange(src_coordinates, dst_coordinates);
        if (ammo <= 0)
        {
            throw OutOfAmmo();
        }
        if (src_coordinates.row == dst_coordinates.row && src_coordinates.col == dst_coordinates.col)
        {
            throw IllegalTarget();
        }

        std::shared_ptr<Character> target = board.at(dst_coordinates.row).at(dst_coordinates.col);
        if (!target)
        {
            throw IllegalTarget();
        }

        if (target->takeDamage(target->isEnemy(team) ? power : -power))
        {
            target.reset();
        }

        ammo -= attack_cost;
    }
    CharacterType getType()
    {
        return CharacterType::MEDIC;
    }
}