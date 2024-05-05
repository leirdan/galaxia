#include "AstronautTravelService.hpp"

AstronautTravelService::AstronautTravelService() {}
AstronautTravelService::~AstronautTravelService()
{
  delete _astronautTravelData;
}

std::list<AstronautTravel> *AstronautTravelService::getAstronautTravelData(void)
{
  return _astronautTravelData;
}

bool AstronautTravelService::addAstronautToTravel(Travel *travel, Astronaut *astronaut)
{
  try
  {
    auto object = new AstronautTravel(astronaut, travel);
    _astronautTravelData->push_back(*object);
    return true;
  }
  catch (...)
  {
    return false;
  }
}

Astronaut *AstronautTravelService::findAstronautScheduledForTravel(Travel *travel, const std::string &cpf)
{
  auto data = this->getAstronautTravelData();

  for (auto k = data->begin(); k != data->end(); k++)
  {
    if (k->getAstronautInfo()->getCpf() == cpf && k->getTravelId() == travel->getCode())
    {
      return &(*k->getAstronautInfo());
    }
  }

  return nullptr;
}

std::list<Astronaut *> *AstronautTravelService::getAstronautsOnTravel(unsigned int travelCode)
{
  auto data = this->getAstronautTravelData();

  auto astronautsPointers = new std::list<Astronaut *>();

  for (auto k = data->begin(); k != data->end(); k++)
  {
    if (k->getTravelId() == travelCode)
    {
      astronautsPointers->push_back(k->getAstronautInfo());
    }
  }

  return astronautsPointers->size() >= 1 ? astronautsPointers : nullptr;
}

bool AstronautTravelService::removeAstronautOnTravel(unsigned int travelCode, unsigned int astronautId)
{
  try
  {
    for (auto k = _astronautTravelData->begin(); k != _astronautTravelData->end(); k++)
    {
      if (k->getAstronautId() == astronautId && k->getTravelId() == travelCode)
      {
        _astronautTravelData->remove(*k);
        return true;
      }
    }
    return false;
  }
  catch (std::exception)
  {
    return false;
  }
}

std::list<Travel *> *AstronautTravelService::getOnGoingTravels(std::list<Travel> *travelsData)
{
  auto travelsPointers = new std::list<Travel *>();
  for (auto t = travelsData->begin(); t != travelsData->end(); t++)
  {
    if (t->getStatus() == TravelStatus::ONGOING)
    {
      auto travel = &(*t);
      travelsPointers->push_back(travel);
    }
  }

  return travelsPointers->size() == 0 ? nullptr : travelsPointers;
}