#ifndef ASTRONAUTTRAVELSERVICE_HPP
#define ASTRONAUTTRAVELSERVICE_HPP

#include "../domain/interfaces/AstronautTravel.hpp"
#include <list>

class AstronautTravelService
{
private:
  std::list<AstronautTravel> *_astronautTravelData = new std::list<AstronautTravel>;

public:
  std::list<AstronautTravel> *getAstronautTravelData(void);
  bool addAstronautToTravel(Travel *travel, Astronaut *astronaut);
  Astronaut *findAstronautScheduledForTravel(Travel *travel, const std::string &cpf);
  std::list<Astronaut *> * getAstronautsOnTravel(unsigned int travelCode);
  bool removeAstronautOnTravel(unsigned int travelCode, unsigned int astronautId);
};

#endif