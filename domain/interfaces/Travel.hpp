#ifndef TRAVEL_HPP
#define TRAVEL_HPP

#include <list>
#include <chrono>
#include "../../enums/TravelStatus.cpp"

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
     * This list contains the identifiers from astronauts who will go on this trip.
     */
    std::list<int> _astronautsScheduledForTravel;
    /**
     * The planned date from the launch.
     */
    std::chrono::system_clock::time_point _launchDate;
    /**
     * The travel's status.
     */
    TravelStatus status;

public:
    Travel();
    ~Travel();
    int getCode(void);
    std::list<int> getAstronautsScheduledForTravel(void);
    std::chrono::system_clock::time_point getLaunchDate(void);
};

#endif