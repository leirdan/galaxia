#ifndef TRAVELSERVICE_HPP
#define TRAVELSERVICE_HPP

#include <list>
#include <string>
#include "../domain/interfaces/Travel.hpp"
#include "../domain/interfaces/Astronaut.hpp"

class TravelService
{
private:
    std::list<Travel> *_travelsData;

public:
    TravelService();
    ~TravelService();
    std::list<Travel> *getTravelsData(void);

    Travel *createTravel(const std::string &origin, const std::string &destination);
    Travel *searchByCode(unsigned int code);
    bool addAstronaut(Travel *travel, Astronaut *astronaut);
};

#endif