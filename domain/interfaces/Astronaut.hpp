#ifndef ASTRONAUT_HPP
#define ASTRONAUT_HPP

#include <list>
#include <string>
#include "../classes/ReadonlyTravel.hpp"

/**
 * Represents an astronaut.
 */
class Astronaut
{
private:
	int _id, _age;
	std::string _name;
	std::string _cpf;
	std::list<ReadonlyTravel> _travels;
	bool _isOnOngoingTravel;

public:
	Astronaut();
	Astronaut(int id, const std::string &name, int age, const std::string &cpf);
	Astronaut(const std::string &name, int age, const std::string &cpf);
	~Astronaut();

	int getId(void);

	int getAge(void);
	void setAge(int a);

	std::string getName(void);
	void setName(const std::string &n);

	std::string getCpf(void);
	void setCpf(const std::string &c);

	bool getOnOngoingTravel(void);
	void setOnOngoingTravel(bool v);

	std::list<ReadonlyTravel> getTravelsList(void);
};
#endif
