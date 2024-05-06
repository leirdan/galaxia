#ifndef ASTRONAUTSERVICE_HPP
#define ASTRONAUTSERVICE_HPP

#include "../domain/interfaces/Astronaut.hpp"
#include <list>

class AstronautService
{
private:
  std::list<Astronaut> *_astronautsData;

public:
  AstronautService();
  ~AstronautService();

  std::list<Astronaut> *getAstronautsData(void);

  std::list<Astronaut *> *getAstronautsByStatus(AstronautStatus status);

  Astronaut *createAstronaut(const std::string &name, const std::string &cpf, int age);

  Astronaut *searchByCpf(const std::string &cpf);
};

#endif