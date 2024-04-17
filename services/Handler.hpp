#ifndef HANDLER_HPP
#define HANDLER_HPP

#include <list>
#include "../domain/interfaces/Astronaut.hpp"
#include "../domain/interfaces/Travel.hpp"
#include "AstronautService.hpp"
#include "TravelService.hpp"

class Handler
{
private:
    AstronautService *_astronautService = new AstronautService();
    TravelService *_travelService = new TravelService();

public:
    void handleDisplayTravels();
    Astronaut *handleCreateAstronaut();
    Travel *handleCreateTravel();
    void handleAddAstronautToTravel();
    void handleRemoveAstronautToTravel();
};

#endif