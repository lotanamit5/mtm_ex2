#ifndef MTM_EXCEPTIONS_H
#define MTM_EXCEPTIONS_H

#include <exception>
#include <string>
namespace mtm
{
    class Exception : public std::exception
    {
    public:
        Exception();
        virtual ~Exception() noexcept = default;
        virtual const char *what() const noexcept;
        std::string _msg;
    };

    class illegalArgument : public Exception
    {
    };
    class IllegalCell : public Exception
    {
    };
    class CellEmpty : public Exception
    {
    };
    class MoveTooFar : public Exception
    {
    };
    class CellOccupied : public Exception
    {
    };
    class OutOfRange : public Exception
    {
    };
    class OutOfAmmo : public Exception
    {
    };
    class IllegalTarget : public Exception
    {
    };
}
#endif