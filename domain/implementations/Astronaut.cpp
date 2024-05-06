#include <string>
#include "../interfaces/Astronaut.hpp"

Astronaut::Astronaut(){};

Astronaut::Astronaut(unsigned int id, const std::string &name, unsigned int age, const std::string &cpf)
{
  _id = id;
  _name = name;
  _cpf = cpf;
  _age = age;
};

Astronaut::Astronaut(const std::string &name, unsigned int age, const std::string &cpf)
{
  _name = name;
  _cpf = cpf;
  _age = age;
};

Astronaut::~Astronaut(){};

unsigned int Astronaut::getId(void)
{
  return _id;
}

std::string Astronaut::getName(void)
{
  return _name;
}

unsigned int Astronaut::getAge(void)
{
  return _age;
}

std::string Astronaut::getCpf(void)
{
  return _cpf;
}

AstronautStatus Astronaut::getStatus(void)
{
  return _status;
}

std::string Astronaut::getStatusToString(void)
{
  std::string status;

  switch (_status)
  {
  case AVAILABLE:
    status = "Disponível.";
    break;
  case DEAD:
    status = "Falecido.";
    break;
  case ONGOINGTRAVEL:
    status = "Em missão.";
    break;
  default:
    status = "Indefinido.";
    break;
  }

  return status;
}

void Astronaut::setName(const std::string &n)
{
  _name = n;
}

void Astronaut::setAge(unsigned int a)
{
  // TODO: add validation to 'a'
  _age = a;
}

void Astronaut::setCpf(const std::string &c)
{
  // TODO: add validation
  _cpf = c;
}

void Astronaut::setStatus(AstronautStatus newStatus)
{
  _status = newStatus;
}
