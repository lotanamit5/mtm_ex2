#ifndef MEDIC_H
#define MEDIC_H

#include "Auxiliaries.h"
#include "Character.h"

#include <memory>
#include <vector>

namespace mtm
{
    class Medic : public Character
    {
    public:
        Medic(units_t health, units_t ammo, units_t range, units_t power, Team team);
        Medic(const Medic &) = default;
        Medic() = delete;
        ~Medic() = default;

        std::shared_ptr<Character> clone() const override;
        void attack(std::vector<std::vector<std::shared_ptr<Character>>> &board,
                    const GridPoint &src_coordinates, const GridPoint &dst_coordinates) override;
        CharacterType getType() override;
    };
}
#endif