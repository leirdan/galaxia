#include <iostream>
#include "AstronautService.hpp"
#include "../domain/interfaces/Astronaut.hpp"

AstronautService::AstronautService()
{
    _astronautsData = new std::list<Astronaut>();
};

AstronautService::~AstronautService(){};

Astronaut *AstronautService::createAstronaut(const std::string &name, const std::string &cpf, int age)
{
    if (name.empty() || age < 0)
    {
        std::cout << "Entradas inválidas, tente novamente." << std::endl;
        return NULL;
    }

    auto newAstro = new Astronaut(_astronautsData->size() + 1, name, age, cpf);

    _astronautsData->push_back(*newAstro);

    return newAstro;
};