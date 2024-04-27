#ifndef TRAVELSERVICE_HPP
#define TRAVELSERVICE_HPP

#include <list>
#include <string>
#include "../domain/interfaces/Travel.hpp"

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
};

#endif