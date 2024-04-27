#ifndef ASTRONAUT_HPP
#define ASTRONAUT_HPP

#include <string>
#include "../classes/ReadonlyTravel.hpp"
#include "../../enums/AstronautStatus.hpp"

/**
 * Represents an astronaut.
 */
class Astronaut
{
private:
	unsigned int _id, _age;
	std::string _name;
	std::string _cpf;
	AstronautStatus _status = AVAILABLE;

public:
	Astronaut();
	Astronaut(unsigned int id, const std::string &name, unsigned int age, const std::string &cpf);
	Astronaut(const std::string &name, unsigned int age, const std::string &cpf);
	~Astronaut();

	unsigned int getId(void);

	unsigned int getAge(void);
	void setAge(unsigned int a);

	std::string getName(void);
	void setName(const std::string &n);

	std::string getCpf(void);
	void setCpf(const std::string &c);

	AstronautStatus getStatus(void);
	void setStatus(AstronautStatus newStatus);
};
#endif
