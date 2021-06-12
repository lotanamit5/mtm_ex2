#include "Game.h"
#include "Character.h"
#include "Soldier.h"
#include "Sniper.h"
#include "Medic.h"
#include "Exceptions.h"
#include <vector>

#define SOLDIER_CHAR 's'
#define MEDIC_CHAR 'm'
#define SNIPER_CHAR 'n'

namespace mtm
{
    Game::Game(int height, int width)
        : height(height), width(width)
    {
        board = std::vector<std::vector<std::shared_ptr<Character>>>(height, std::vector<std::shared_ptr<Character>>(width, nullptr));
    }
    Game::Game(const Game &other)
        : height(other.height), width(other.width)
    {
        board = std::vector<std::vector<std::shared_ptr<Character>>>(height, std::vector<std::shared_ptr<Character>>(width, nullptr));
        std::shared_ptr<Character> current_character;
        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                current_character = other.board[i][j];
                if (current_character)
                {
                    std::shared_ptr<Character> character_copy = current_character->clone();
                    board[i][j] = character_copy;
                }
            }
        }
    }
    bool Game::cellIsEmpty(const GridPoint &coordinates)
    {
        return board[coordinates.row][coordinates.col] == nullptr;
    }

    void Game::checkCellInBoard(const GridPoint &coordinates)
    {
        if (coordinates.row < 0 || coordinates.row >= height || coordinates.col < 0 || coordinates.col >= width)
        {
            throw IllegalCell();
        }
    }

    void Game::checkCellOccupied(const GridPoint &coordinates)
    {
        if (!cellIsEmpty(coordinates))
        {
            throw CellOccupied();
        }
    }
    void Game::checkcellIsntEmpty(const GridPoint &coordinates)
    {
        if (cellIsEmpty(coordinates))
        {
            throw CellEmpty();
        }
    }
    void Game::addCharacter(const GridPoint &coordinates, std::shared_ptr<Character> character)
    {
        checkCellInBoard(coordinates);
        checkCellOccupied(coordinates);
        board[coordinates.row][coordinates.col] = character;
    }

    static std::shared_ptr<Character> makeCharacter(CharacterType type, Team team,
                                                    units_t health, units_t ammo, units_t range, units_t power)
    {
        std::shared_ptr<Character> character;
        switch (type)
        {
        case (CharacterType::SOLDIER):
            character = std::make_shared<Character>(Soldier(health, ammo, range, power, team));
            break;
        case (CharacterType::SNIPER):
            character = std::make_shared<Character>(Sniper(health, ammo, range, power, team));
            break;
        case (CharacterType::MEDIC):
            character = std::make_shared<Character>(Medic(health, ammo, range, power, team));
            break;
        default:
            throw illegalArgument();
            break;
        }
        return character;
    }

    void Game::move(const GridPoint &src_coordinates, const GridPoint &dst_coordinates)
    {
        checkCellInBoard(src_coordinates);
        checkCellInBoard(dst_coordinates);
        checkcellIsntEmpty(src_coordinates);
        std::shared_ptr<Character> tmp_character = board[src_coordinates.row][src_coordinates.col];
        if (!tmp_character->legalMove(GridPoint::distance(src_coordinates, dst_coordinates)))
        {
            throw MoveTooFar();
        }
        checkCellOccupied(dst_coordinates);

        board[src_coordinates.row][src_coordinates.col] = nullptr;
        board[dst_coordinates.row][dst_coordinates.col] = tmp_character;
    }

    void Game::attack(const GridPoint &src_coordinates, const GridPoint &dst_coordinates)
    {
        checkCellInBoard(src_coordinates);
        checkCellInBoard(dst_coordinates);
        checkcellIsntEmpty(src_coordinates);

        std::shared_ptr<Character> character = board[src_coordinates.row][src_coordinates.col];
        character->attack(board, src_coordinates, dst_coordinates);
    }
    void Game::reload(const GridPoint &coordinates)
    {
        checkCellInBoard(coordinates);
        checkcellIsntEmpty(coordinates);

        std::shared_ptr<Character> character = board[coordinates.row][coordinates.col];
        character->reload();
    }
    bool Game::isOver(Team *winningTeam) const
    {
        Team first_found;
        for (std::vector<std::shared_ptr<Character>> row : board)
        {
            for (std::shared_ptr<Character> character : row)
            {
                if (!first_found && character)
                {
                    first_found = character->isEnemy(Team::CROSSFITTERS) ? Team::POWERLIFTERS : Team::CROSSFITTERS;
                }
                else if (first_found && character && character->isEnemy(first_found))
                {
                    return false;
                }
            }
        }
        if (first_found)
        {
            if (winningTeam)
            {
                *winningTeam = first_found;
            }
            return true;
        }
        else
        {
            return false;
        }
    }

    std::string Game::toString() const
    {
        std::string output = "";
        char current;
        for (std::vector<std::shared_ptr<Character>> row : board)
        {
            for (std::shared_ptr<Character> character : row)
            {
                switch (character->getType())
                {
                case CharacterType::SOLDIER:
                    current = SOLDIER_CHAR;
                    break;
                case CharacterType::SNIPER:
                    current = SNIPER_CHAR;
                    break;
                case CharacterType::MEDIC:
                    current = MEDIC_CHAR;
                    break;
                default:
                    break;
                }
                if (character->isEnemy(Team::CROSSFITTERS))
                {
                    current = toupper(current);
                }
                output.push_back(current);
            }
        }
        return output;
    }

    std::ostream &operator<<(std::ostream &os, const Game &game)
    {
        std::string out = game.toString();
        printGameBoard(os, &out.at(0), &out.at(out.length()), game.width);
        return os;
    }

}