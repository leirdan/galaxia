#include "../interfaces/Travel.hpp"

Travel::Travel(int code)
{
	_code = code;
	_status = TravelStatus::PLANNED;
}

Travel::Travel(int code, const std::string &origin, const std::string &destination)
{
	_code = code;
	_origin = origin;
	_destination = destination;
	_status = TravelStatus::PLANNED;
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

std::list<ReadonlyAstronaut> *Travel::getAstronautsScheduledForTravel()
{
	return &_astronautsScheduledForTravel;
}

bool Travel::setNewAstronautForTravel(ReadonlyAstronaut *astronaut)
{
	try
	{
		auto v = this->getAstronautsScheduledForTravel();

		v->push_back(*astronaut);

		return true;
	}
	catch (std::exception)
	{
		return false;
	}
}