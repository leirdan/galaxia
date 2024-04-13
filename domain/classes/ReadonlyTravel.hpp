#ifndef READONLYTRAVEL_HPP
#define READONLYTRAVEL_HPP

#include "../../enums/TravelStatus.hpp"

class ReadonlyTravel
{
private:
    unsigned int _code;
    TravelStatus _status;

public:
    ReadonlyTravel();
    ReadonlyTravel(unsigned int code);
    ~ReadonlyTravel();
};

#endif