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

std::string ReadonlyAstronaut::getCpf(void)
{
    return _cpf;
}

unsigned int ReadonlyAstronaut::getId(void)
{
    return _id;
}

bool ReadonlyAstronaut::operator==(const ReadonlyAstronaut &a1) const
{
    return (this->_id == a1._id);
}