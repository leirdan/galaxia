#include <string>
#include "../interfaces/Travel.hpp"

Travel::Travel(unsigned int code)
{
  _code = code;
  _status = TravelStatus::PLANNED;
}

Travel::Travel(unsigned int code, const std::string &origin, const std::string &destination)
{
  _code = code;
  _origin = origin;
  _destination = destination;
  _status = TravelStatus::PLANNED;
}

Travel::~Travel(){};

unsigned int Travel::getCode()
{
  return _code;
}

std::string Travel::getOrigin()
{
  return _origin;
}

std::string Travel::getDestination()
{
  return _destination;
}

TravelStatus Travel::getStatus()
{
  return _status;
}

void Travel::setStatus(TravelStatus newStatus)
{
  _status = newStatus;
}

bool Travel::operator!=(const TravelStatus &stat) const
{
  return (static_cast<int>(this->_status) != static_cast<int>(stat));
}