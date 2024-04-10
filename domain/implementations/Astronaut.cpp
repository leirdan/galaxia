#include <string>
#include "../interfaces/Astronaut.hpp"

Astronaut::Astronaut(){};

Astronaut::Astronaut(int id, const std::string &name, int age, const std::string &cpf)
{
    _id = id;
    _name = name;
    _cpf = cpf;
    _age = age;
};

Astronaut::Astronaut(const std::string &name, int age, const std::string &cpf)
{
    _name = name;
    _cpf = cpf;
    _age = age;
};

Astronaut::~Astronaut(){};

int Astronaut::getId(void)
{
    return _id;
}

std::string Astronaut::getName(void)
{
    return _name;
}

int Astronaut::getAge(void)
{
    return _age;
}

std::string Astronaut::getCpf(void)
{
    return _cpf;
}

void Astronaut::setName(const std::string &n)
{
    _name = n;
}

void Astronaut::setAge(int a)
{
    // TODO: add validation to 'a'
    _age = a;
}

void Astronaut::setCpf(const std::string &c)
{
    // TODO: add validation
    _cpf = c;
}
