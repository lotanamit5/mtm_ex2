#ifndef SOLDIER_H
#define SOLDIER_H

#include "Auxiliaries.h"
#include "Character.h"

#include <memory>
#include <map>

namespace mtm
{
    class Soldier : public Character
    {
    public:
        Soldier(units_t health, units_t ammo, units_t range, units_t power, Team team);
        Soldier(const Soldier &) = default;
        Soldier() = delete;
        ~Soldier() = default;

        std::shared_ptr<Character> clone() const override;
        void attack(std::map<GridPoint, std::shared_ptr<Character>, classcomp> &board,
                    const GridPoint &src_coordinates, const GridPoint &dst_coordinates) override;
        CharacterType getType() override;

        // void legalAttack(std::vector<std::vector<std::shared_ptr<Character>>> &board,
        //                  const GridPoint &src_coordinates, const GridPoint &dst_coordinates) override;
    };
}
#endif