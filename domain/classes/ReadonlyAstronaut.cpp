#include <string>
#include "ReadonlyAstronaut.hpp"

ReadonlyAstronaut::ReadonlyAstronaut(){};
ReadonlyAstronaut::~ReadonlyAstronaut(){};
ReadonlyAstronaut::ReadonlyAstronaut(unsigned int id, const std::string &name, const std::string &cpf, unsigned int age)
{
    _id = id;
    _name = name;
    _cpf = cpf;
    _age = age;
}

std::string ReadonlyAstronaut::getName(void)
{
    return _name;
}