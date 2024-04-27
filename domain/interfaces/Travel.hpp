#ifndef TRAVEL_HPP
#define TRAVEL_HPP

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
    unsigned int _code;
    /**
     * The starting point of the travel.
     */
    std::string _origin;
    /**
     * The intended arrival point for the travel.
     */
    std::string _destination;
    /**
     * The travel's status.
     */
    TravelStatus _status = TravelStatus::PLANNED;

public:
    Travel(unsigned int code);
    Travel(unsigned int code, const std::string &origin, const std::string &destination);
    ~Travel();

    unsigned int getCode(void);

    std::string getOrigin(void);
    std::string getDestination(void);
    TravelStatus getStatus(void);
    void setStatus(TravelStatus newStatus);
};

#endif
