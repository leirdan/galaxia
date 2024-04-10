#include <iostream>
#include <chrono>
#include <list>
#include <ctime>
#include "domain/interfaces/Astronaut.hpp"
#include "services/AstronautService.hpp"

void showOptions();
void handleRequest(int choice);
Astronaut *handleCreateAstronaut(AstronautService *service);

int main()
{
	auto astronautsDb = std::list<Astronaut>();
	auto astronautService = new AstronautService(astronautsDb);

	int choice = 5;

	std::cout << "Bem vindo/a ao GALAXIA! \n";

	while (choice != 0)
	{
		std::cout << "Qual operação deseja realizar? \n";
		showOptions();

		std::cin >> choice;

		switch (choice)
		{
		case 1:
			handleCreateAstronaut(astronautService);

			break;
		default:
			break;
		}
	}

	delete astronautService;
	delete &astronautsDb;

	std::cout << "Volte sempre! \n";

	return 0;
}

void showOptions()
{
	std::cout << "0 - Sair do GALAXIA;	\n";
	std::cout << "1 - Cadastrar Astronauta;	\n";
}

Astronaut *handleCreateAstronaut(AstronautService *service)
{
	std::string n, c;
	int a;

	std::cout << "Você escolheu 'Cadastrar Astronauta'. \n";
	std::cout << "Nome do astronauta: ";
	std::cin.ignore();
	std::getline(std::cin, n);
	std::cout << "CPF: ";
	std::getline(std::cin, c);
	std::cout << "Idade: ";
	std::cin >> a;

	auto result = service->createAstronaut(n, c, a);

	if (result == NULL)
	{
		std::cout << "Não foi possível criar o astronauta. \n";
	}
	else
	{
		std::cout << "Novo astronauta incluído! Seu nome e Id são: " << result->getName() << ", " << result->getId() << std::endl;
	}
	return result;
}