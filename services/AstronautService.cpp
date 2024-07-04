#include <iostream>
#include "AstronautService.hpp"
#include "../domain/interfaces/Astronaut.hpp"

AstronautService::AstronautService()
{
  _astronautsData = new std::list<Astronaut>();
};

AstronautService::~AstronautService()
{
  delete _astronautsData;
};

std::list<Astronaut> *AstronautService::getAstronautsData()
{
  return _astronautsData;
}

std::list<Astronaut *> *AstronautService::getAstronautsByStatus(AstronautStatus status)
{
  auto astronautsPointers = new std::list<Astronaut *>();
  for (auto a = _astronautsData->begin(); a != _astronautsData->end(); a++)
  {
    if (a->getStatus() == status)
    {
      auto astronaut = &(*a);
      astronautsPointers->push_back(astronaut);
    }
  }

  return astronautsPointers->size() >= 1 ? astronautsPointers : nullptr;
}

Astronaut *AstronautService::createAstronaut(const std::string &name, const std::string &cpf, int age)
{
  if (name.empty() || age < 0)
  {
    std::cout << "Entradas inválidas, tente novamente." << std::endl;
    return nullptr;
  }

  if (searchByCpf(cpf) != nullptr) 
  { 
    std::cout << "Já existe um astronauta com este mesmo CPF.\n";
    return nullptr;
  }

  auto newAstro = new Astronaut(_astronautsData->size() + 1, name, age, cpf);

  _astronautsData->push_back(*newAstro);

  return newAstro;
};

Astronaut *AstronautService::searchByCpf(const std::string &cpf)
{
  auto v = this->getAstronautsData();
  for (auto k = v->begin(); k != v->end(); k++)
  {
    if (k->getCpf() == cpf)
    {
      return &(*k);
    }
    continue;
  }

  return nullptr;
}
