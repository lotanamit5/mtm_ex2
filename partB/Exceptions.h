#ifndef MTM_EXCEPTIONS_H
#define MTM_EXCEPTIONS_H

#include <exception>
#include <string>
namespace mtm
{
    class Exception : public std::exception
    {
    public:
        Exception(std::string name);
        virtual ~Exception() noexcept = default;
        virtual const char *what() const noexcept;
        char *msg;
    };

    class illegalArgument : public Exception
    {
    public:
        explicit illegalArgument();
    };
    class IllegalCell : public Exception
    {
    public:
        explicit IllegalCell();
    };
    class CellEmpty : public Exception
    {
    public:
        explicit CellEmpty();
    };
    class MoveTooFar : public Exception
    {
    public:
        explicit MoveTooFar();
    };
    class CellOccupied : public Exception
    {
    public:
        explicit CellOccupied();
    };
    class OutOfRange : public Exception
    {
    public:
        explicit OutOfRange();
    };
    class OutOfAmmo : public Exception
    {
    public:
        explicit OutOfAmmo();
    };
    class IllegalTarget : public Exception
    {
    public:
        explicit IllegalTarget();
    };
}
#endif