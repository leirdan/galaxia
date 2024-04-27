#include "ReadonlyTravel.hpp"

ReadonlyTravel::ReadonlyTravel(){};
ReadonlyTravel::~ReadonlyTravel(){};
ReadonlyTravel::ReadonlyTravel(unsigned int code)
{
    _code = code;
}

unsigned int ReadonlyTravel::getCode(void)
{
    return _code;
}