#ifndef READONLYASTRONAUT_HPP
#define READONLYASTRONAUT_HPP

#include <string>

/**
 * Represents the general read-only data of an astronaut, with the purpose to create lists on Travel class.
 */
class ReadonlyAstronaut
{
private:
    unsigned int _id;
    unsigned int _age;
    std::string _name, _cpf;

public:
    ReadonlyAstronaut();
    ReadonlyAstronaut(unsigned int id, const std::string &name, const std::string &cpf, unsigned int age);
    ~ReadonlyAstronaut();
    unsigned int getId(void);
    std::string getName(void);
    std::string getCpf(void);
    bool operator==(const ReadonlyAstronaut &a1) const;
};

#endif