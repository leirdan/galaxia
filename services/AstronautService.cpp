#include <iostream>
#include "AstronautService.hpp"
#include "../domain/interfaces/Astronaut.hpp"

AstronautService::AstronautService()
{
    _astronautsData = new std::list<Astronaut>();
};

AstronautService::~AstronautService(){};

std::list<Astronaut> *AstronautService::getAstronautsData()
{
    return _astronautsData;
}

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