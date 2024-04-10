#include "AstronautService.hpp"
#include "../domain/interfaces/Astronaut.hpp"
#include <iostream>

AstronautService::AstronautService(std::list<Astronaut> list) : _dbAstronauts(list){};
AstronautService::~AstronautService(){};

Astronaut *AstronautService::createAstronaut(const std::string &name, const std::string &cpf, int age)
{
    if (name.empty() || age < 0)
    {
        std::cout << "Entradas inválidas, tente novamente." << std::endl;
        return NULL;
    }

    auto newAstro = new Astronaut(_dbAstronauts.size() + 1, name, age, cpf);

    _dbAstronauts.push_back(*newAstro);

    return newAstro;
};