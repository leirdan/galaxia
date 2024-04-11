#include <list>
#include <string>
#include <chrono>
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
};