#include "Exceptions.h"
#include <string>

namespace mtm
{
    Exception::Exception(std::string name)
    {
        std::string msg_s = "A game related error has occurred: " + name;
        msg = new char[msg_s.length() + 1];
        //msg.append(typeid(this).name());
    }
    const char *Exception::what() const noexcept
    {
        return msg;
    }

    illegalArgument::illegalArgument() : Exception("IllegalArgument"){}
    IllegalCell::IllegalCell() : Exception("IllegalCell"){}
    CellEmpty::CellEmpty() : Exception("CellEmpty"){}
    MoveTooFar::MoveTooFar() : Exception("MoveTooFar"){}
    CellOccupied::CellOccupied() : Exception("CellOccupied"){}
    OutOfRange::OutOfRange() : Exception("OutOfRange"){}
    OutOfAmmo::OutOfAmmo() : Exception("OutOfAmmo"){}
    IllegalTarget::IllegalTarget() : Exception("IllegalTarget"){}
}