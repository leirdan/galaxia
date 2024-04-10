#include <chrono>
#include "../interfaces/Travel.hpp"

Travel::Travel()
{
	_code++;
}

int Travel::getCode()
{
	return _code;
}

std::list<int> Travel::getAstronautsScheduledForTravel()
{
	return _astronautsScheduledForTravel;
}

std::chrono::system_clock::time_point Travel::getLaunchDate()
{
	return _launchDate;
}