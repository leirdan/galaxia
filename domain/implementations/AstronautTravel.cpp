#include "../interfaces/AstronautTravel.hpp"

AstronautTravel::AstronautTravel() {}
AstronautTravel::~AstronautTravel() {}

AstronautTravel::AstronautTravel(unsigned int idAstronaut, unsigned int idTravel)
{
  _idAstronaut = idAstronaut;
  _idTravel = idTravel;
}

AstronautTravel::AstronautTravel(Astronaut *astronaut, Travel *travel)
{
  _idAstronaut = astronaut->getId();
  _idTravel = travel->getCode();
  _travelInfo = travel;
  _astronautInfo = astronaut;
}

bool AstronautTravel::operator==(const AstronautTravel &at) const
{
  return (this->_idAstronaut == at._idAstronaut && this->_idTravel == at._idTravel);
}

unsigned int AstronautTravel::getAstronautId(void)
{
  return _idAstronaut;
}

unsigned int AstronautTravel::getTravelId(void)
{
  return _idTravel;
}

Astronaut *AstronautTravel::getAstronautInfo(void)
{
  return _astronautInfo;
}

Travel *AstronautTravel::getTravelInfo(void)
{
  return _travelInfo;
}
