#include <iostream>
#include <cstdio>
#include <chrono>
#include <list>
#include <ctime>
#include "domain/interfaces/Astronaut.hpp"
#include "domain/interfaces/Travel.hpp"
#include "services/AstronautService.hpp"
#include "services/TravelService.hpp"

void redirect();
void showOptions();
void handleRequest(int choice);
Astronaut *handleCreateAstronaut(AstronautService *service);
Travel *handleCreateTravel(TravelService *service);

int main()
{
	system("clear");

	auto astronautService = new AstronautService();

	auto travelService = new TravelService();

	int choice = 1;

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
			redirect();
			break;
		case 2:
			handleCreateTravel(travelService);
			redirect();
			break;
		default:
			break;
		}
	}

	delete astronautService;
	delete travelService;

	std::cout << "Volte sempre! \n";

	return 0;
}

void redirect()
{
	std::cout << "Pressione ENTER para continuar... ";
	getchar();
	system("clear");
}

void showOptions()
{
	std::cout << "0 - Sair do GALAXIA;	\n";
	std::cout << "1 - Cadastrar Astronauta;	\n";
	std::cout << "2 - Cadastrar vôo;	\n";
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

	std::cin.ignore();
	return result;
}

Travel *handleCreateTravel(TravelService *service)
{
	std::string o, d;

	std::cout << "Você escolheu 'Cadastrar vôo'. \n";
	std::cout << "Ponto de partida (opcional): ";
	std::cin.ignore();
	std::getline(std::cin, o);

	std::cout << "Destino (opcional): ";
	std::getline(std::cin, d);

	auto result = service->createTravel(o, d);

	if (result == NULL)
	{
		std::cout << "Não foi possível criar o vôo.\n";
	}
	else
	{
		std::cout << "Vôo com código " << result->getCode() << " foi criado";
		if (!result->getOrigin().empty() && !result->getDestination().empty())
		{
			std::cout << " com ponto de partida em " << result->getOrigin() << " e destino em " << result->getDestination();
		}
		std::cout << "!\n";
	}

	return result;
}