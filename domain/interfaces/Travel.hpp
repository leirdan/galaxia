#ifndef TRAVEL_HPP
#define TRAVEL_HPP

#include <list>
#include <string>
#include "../classes/ReadonlyAstronaut.hpp"
#include "../../enums/TravelStatus.hpp"

/**
 * Represents the planned travels.
 */
class Travel
{
private:
    /**
     * Code from travel.
     */
    int _code;
    /**
     * The starting point of the travel.
     */
    std::string _origin;
    /**
     * The intended arrival point for the travel.
     */
    std::string _destination;
    /**
     * This list contains the identifiers from astronauts who will go on this trip.
     */
    std::list<ReadonlyAstronaut>
        _astronautsScheduledForTravel;
    /**
     * The travel's status.
     */
    TravelStatus _status = TravelStatus::PLANNED;

public:
    Travel(int code);
    Travel(int code, const std::string &origin, const std::string &destination);
    ~Travel();

    int getCode(void);

    std::string getOrigin(void);
    std::string getDestination(void);

    std::list<ReadonlyAstronaut> *getAstronautsScheduledForTravel(void);
    bool setNewAstronautForTravel(ReadonlyAstronaut *astronaut);
};

#endif