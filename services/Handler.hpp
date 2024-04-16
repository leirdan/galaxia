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
    Astronaut *handleCreateAstronaut();
    Travel *handleCreateTravel();
    void handleAddAstronautToTravel();
    void handleShowTravels();
};