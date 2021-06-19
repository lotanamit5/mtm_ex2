#include "Exceptions.h"
#include <string>

namespace mtm
{
    Exception::Exception()
    {
        _msg = "A game related error has occurred: ";
        _msg.append(typeid(this).name());
    }
    const char *Exception::what() const noexcept
    {
        return _msg.c_str();
    }
    // const char *Exception::what() const
    // {
    //     char *error;
    //     std::string err = (std::string) return err;
    // }
}