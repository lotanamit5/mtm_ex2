#ifndef SNIPER_H
#define SNIPER_H

#include "Auxiliaries.h"
#include "Character.h"

#include <memory>
#include <vector>

namespace mtm
{
    class Sniper : public Character
    {
        int shots_fired;

    public:
        Sniper(units_t health, units_t ammo, units_t range, units_t power, Team team);
        Sniper(const Sniper &) = default;
        Sniper() = delete;
        ~Sniper() = default;

        std::shared_ptr<Character> clone() const override;
        void attackInRange(const GridPoint &src_coordinates, const GridPoint &dst_coordinates) override;
        void attack(std::vector<std::vector<std::shared_ptr<Character>>> &board,
                    const GridPoint &src_coordinates, const GridPoint &dst_coordinates) override;
        CharacterType getType() override;
    };
}
#endif