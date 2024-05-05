#include <list>
#include "TravelService.hpp"

TravelService::TravelService()
{
  _travelsData = new std::list<Travel>();
};

TravelService::~TravelService()
{
  delete _travelsData;
};

std::list<Travel> *TravelService::getTravelsData()
{
  return _travelsData;
}

Travel *TravelService::createTravel(const std::string &origin, const std::string &destination)
{
  Travel *travel;
  if (origin.empty() && destination.empty())
  {
    travel = new Travel(_travelsData->size() + 1, "Indefinido", "Indefinido");
  }
  else
  {
    travel = new Travel(_travelsData->size() + 1, origin, destination);
  }

  _travelsData->push_back(*travel);

  return travel;
};

Travel *TravelService::searchByCode(unsigned int code)
{
  auto v = this->getTravelsData();

  for (auto k = v->begin(); k != v->end(); k++)
  {
    if (k->getCode() == code)
    {
      return &(*k);
    }
  }

  return nullptr;
}