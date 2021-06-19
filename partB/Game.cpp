#include "Exceptions.h"
#include "Auxiliaries.h"
#include "Game.h"
#include "Character.h"
#include "Soldier.h"
#include "Sniper.h"
#include "Medic.h"

#include <memory>
#include <map>
#include <iterator>

#define SOLDIER_CHAR 's'
#define MEDIC_CHAR 'm'
#define SNIPER_CHAR 'n'
#define EMPTY_CHAR ' '

namespace mtm
{

    Game::Game(int height, int width)
        : height(height), width(width), board(std::map<GridPoint, std::shared_ptr<Character>, classcomp>())
    {
    }
    Game::Game(const Game &other)
        : height(other.height), width(other.width), board(std::map<GridPoint, std::shared_ptr<Character>, classcomp>())
    {
        std::shared_ptr<Character> current_character, character_copy;
        for (std::map<GridPoint, std::shared_ptr<Character>, classcomp>::const_iterator itr = other.board.begin();
             itr != other.board.end(); ++itr)
        {
            current_character = itr->second;
            if (current_character)
            {
                character_copy = current_character->clone();
                this->board[itr->first] = character_copy; //I realy hope that works
            }
        }
    }
    Game &Game::operator=(const Game &other)
    {
        this->height = other.height;
        this->height = other.width;
        board = std::map<GridPoint, std::shared_ptr<Character>, classcomp>();
        std::shared_ptr<Character> current_character, character_copy;
        for (std::map<GridPoint, std::shared_ptr<Character>, classcomp>::const_iterator itr = other.board.begin();
             itr != other.board.end(); ++itr)
        {
            current_character = other.board.at(itr->first);
            if (current_character)
            {
                character_copy = current_character->clone();
                board[itr->first] = character_copy;
            }
        }
        this->board = board;
        return *this;
    }

    bool Game::cellIsEmpty(const GridPoint &coordinates)
    {
        board.find(coordinates);
        bool res;
        try
        {
            res = board[coordinates] != nullptr;
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }

        std::cout << "board cords: " << board[coordinates] << std::endl;
        std::cout << "returning: " << board[coordinates] == nullptr << std::endl;
        return board[coordinates] == nullptr;
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
        board[coordinates] = character;
    }

    std::shared_ptr<Character> Game::makeCharacter(CharacterType type, Team team,
                                                   units_t health, units_t ammo, units_t range, units_t power)
    {
        std::shared_ptr<Character> character;
        switch (type)
        {
        case (CharacterType::SOLDIER):
            character = std::shared_ptr<Character>(new Soldier(health, ammo, range, power, team));
            break;
        case (CharacterType::SNIPER):
            character = std::shared_ptr<Character>(new Sniper(health, ammo, range, power, team));
            break;
        case (CharacterType::MEDIC):
            character = std::shared_ptr<Character>(new Medic(health, ammo, range, power, team));
            break;
        default:
            throw illegalArgument();
            break;
        }
        return character;
    }

    void Game::move(const GridPoint &src_coordinates, const GridPoint &dst_coordinates)
    {
        std::cout << "HII" << std::endl;
        checkCellInBoard(src_coordinates);
        checkCellInBoard(dst_coordinates);
        checkcellIsntEmpty(src_coordinates);

        std::shared_ptr<Character> tmp_character = board.at(src_coordinates);
        std::cout << "found character" << std::endl;

        if (!tmp_character->legalMove(GridPoint::distance(src_coordinates, dst_coordinates)))
        {
            throw MoveTooFar();
        }

        checkCellOccupied(dst_coordinates);
        board.erase(src_coordinates);
        board[dst_coordinates] = tmp_character;
    }

    void Game::attack(const GridPoint &src_coordinates, const GridPoint &dst_coordinates)
    {
        checkCellInBoard(src_coordinates);
        checkCellInBoard(dst_coordinates);
        checkcellIsntEmpty(src_coordinates);

        std::shared_ptr<Character> character = board.at(src_coordinates);
        character->attack(board, src_coordinates, dst_coordinates);
    }
    void Game::reload(const GridPoint &coordinates)
    {
        checkCellInBoard(coordinates);
        checkcellIsntEmpty(coordinates);

        std::shared_ptr<Character> character = board.at(coordinates);
        character->reload();
    }
    bool Game::isOver(Team *winningTeam) const
    {
        Team first_found;
        std::shared_ptr<Character> character;
        for (std::map<GridPoint, std::shared_ptr<Character>, classcomp>::const_iterator itr = board.begin();
             itr != board.end(); ++itr)
        {
            character = itr->second;
            if (!first_found && character)
            {
                first_found = character->isEnemy(Team::CROSSFITTERS) ? Team::POWERLIFTERS : Team::CROSSFITTERS;
            }
            else if (first_found && character && character->isEnemy(first_found))
            {
                return false;
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
        std::shared_ptr<Character> character;
        for (int i = 0; i < height; ++i)
        {
            for (int j = 0; j < width; ++j)
            {
                try
                {
                    character = board.at(GridPoint(i, j));
                    switch (character->getType())
                    {
                    case (CharacterType::SOLDIER):
                        current = SOLDIER_CHAR;
                        break;
                    case (CharacterType::SNIPER):
                        current = SNIPER_CHAR;
                        break;
                    case (CharacterType::MEDIC):
                        current = MEDIC_CHAR;
                        break;
                    default:
                        break;
                    }

                    if (character->isEnemy(Team::POWERLIFTERS))
                    {
                        current = toupper(current);
                    }
                }
                catch (const std::out_of_range &e)
                {
                    current = EMPTY_CHAR;
                }
                output.push_back(current);
            }
        }
        return output;
    }

    std::ostream &operator<<(std::ostream &os, const Game &game)
    {
        std::string out = game.toString();
        printGameBoard(os, &*out.begin(), &*out.end(), game.width);
        return os;
    }
}