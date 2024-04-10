#include "../domain/interfaces/Astronaut.hpp"
#include <list>

// TODO: Verify if it's easily to have a astronautList field in this class.

class AstronautService
{
private:
    std::list<Astronaut> &_dbAstronauts;

public:
    AstronautService(std::list<Astronaut> list);
    ~AstronautService();
    Astronaut *createAstronaut(const std::string &name, const std::string &cpf, int age);
};