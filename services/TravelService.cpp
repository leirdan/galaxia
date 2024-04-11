#include <list>
#include "TravelService.hpp"
#include "../domain/interfaces/Travel.hpp"

TravelService::TravelService()
{
    _travelsData = new std::list<Travel>();
};

TravelService::~TravelService(){};

std::list<Travel> *TravelService::getTravelsData()
{
    return _travelsData;
}

Travel *TravelService::createTravel(const std::string &origin, const std::string &destination)
{
    Travel *travel;
    if (origin.empty() && destination.empty())
    {
        travel = new Travel(_travelsData->size() + 1);
    }
    else
    {
        travel = new Travel(_travelsData->size() + 1, origin, destination);
    }

    _travelsData->push_back(*travel);

    return travel;
};