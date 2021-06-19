#ifndef CHARACTER_H
#define CHARACTER_H

#include <map>
#include <memory>

#include "Auxiliaries.h"

namespace mtm
{
    struct classcomp
    {
        bool operator()(const GridPoint &g1, const GridPoint &g2) const
        {
            return (g1.row == g2.row) ? g1.col < g2.col : g1.row < g2.row;
        }
    };

    class Character
    {
    protected:
        units_t health, ammo, range, power;
        units_t movement_range, reload_amount, attack_cost;
        Team team;

    public:
        Character(units_t health, units_t ammo, units_t range, units_t power,
                  units_t movement_range, units_t reload_amount, units_t attack_cost, Team team);
        Character(const Character &);
        Character() = delete;
        Character &operator=(const Character &) = default;
        virtual ~Character() = default;

        virtual std::shared_ptr<Character> clone() const = 0;
        virtual void attack(std::map<GridPoint, std::shared_ptr<Character>, classcomp> &board, const GridPoint &src_coordinates, const GridPoint &dst_coordinates) = 0;
        virtual void attackInRange(const GridPoint &src_coordinates, const GridPoint &dst_coordinates);
        virtual CharacterType getType() = 0;
        void reload();
        bool isEnemy(Team team);
        bool takeDamage(int damage);
        bool legalMove(int length);

        friend class Game;
    };
}
#endif