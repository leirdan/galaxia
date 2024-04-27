#ifndef ASTRONAUTTRAVEL_HPP
#define ASTRONAUTTRAVEL_HPP

#include "Astronaut.hpp"
#include "Travel.hpp"

class AstronautTravel
{
private:
  unsigned int _idAstronaut, _idTravel;
  Travel *_travelInfo;
  Astronaut *_astronautInfo;

public:
  AstronautTravel();
  AstronautTravel(unsigned int idAstronaut, unsigned int idTravel);
  AstronautTravel(Astronaut *astronaut, Travel *travel);
  ~AstronautTravel();
  bool operator==(const AstronautTravel &at) const;
  unsigned int getAstronautId(void);
  unsigned int getTravelId(void);
  Astronaut *getAstronautInfo(void);
  Travel *getTravelInfo(void);
};

#endif
