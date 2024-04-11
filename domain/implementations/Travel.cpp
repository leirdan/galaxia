#include "../interfaces/Travel.hpp"

Travel::Travel(int code)
{
	_code = code;
}

Travel::Travel(int code, const std::string &origin, const std::string &destination)
{
	_code = code;
	_origin = origin;
	_destination = destination;
}

Travel::~Travel(){};

int Travel::getCode()
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

std::list<int> Travel::getAstronautsScheduledForTravel()
{
	return _astronautsScheduledForTravel;
}