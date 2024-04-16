#include <iostream>
#include <cstdio>
#include <list>
#include "domain/interfaces/Astronaut.hpp"
#include "domain/interfaces/Travel.hpp"
#include "services/AstronautService.hpp"
#include "services/TravelService.hpp"

void redirect();
void showOptions();

class Handler
{
public:
	static Astronaut *handleCreateAstronaut(AstronautService *service);
	static Travel *handleCreateTravel(TravelService *service);
	static void handleAddAstronautToTravel(TravelService *travelService, AstronautService *AstronautService);
	static void handleShowTravels(TravelService *service);
};

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
			Handler::handleCreateAstronaut(astronautService);
			redirect();
			break;
		case 2:
			Handler::handleCreateTravel(travelService);
			redirect();
			break;
		case 3:
			Handler::handleAddAstronautToTravel(travelService, astronautService);
			redirect();
			break;
		case 4:
			Handler::handleShowTravels(travelService);
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
	std::cout << "1 - Cadastrar astronauta;	\n";
	std::cout << "2 - Cadastrar vôo;	\n";
	std::cout << "3 - Adicionar astronauta a vôo;	\n";
	std::cout << "4 - Listar voos planejados;	\n";
}

Astronaut *Handler::handleCreateAstronaut(AstronautService *service)
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
		std::cout << "Novo astronauta " << result->getName() << " incluído!\n";
	}

	std::cin.ignore();
	return result;
}

Travel *Handler::handleCreateTravel(TravelService *service)
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

void Handler::handleAddAstronautToTravel(TravelService *travelServ, AstronautService *astroServ)
{
	std::string cpf;
	unsigned int travelCode;

	std::cout << "Você escolheu 'Adicionar astronauta em vôo'. \n";
	std::cout << "Digite o CPF do astronauta: ";
	std::cin.ignore();
	std::getline(std::cin, cpf);

	auto selectedAstronaut = astroServ->searchByCpf(cpf);

	if (selectedAstronaut == NULL)
	{
		std::cout << "O astronauta com CPF " << cpf << " não existe. \n";
	}
	else
	{
		std::cout << "Digite o código do vôo que deseja adicionar o astronauta: ";
		std::cin >> travelCode;
		std::cin.ignore();

		auto selectedTravel = travelServ->searchByCode(travelCode);
		if (selectedTravel == NULL)
		{
			std::cout << "Não existe vôo planejado com esse código. :( \n";
		}
		else
		{
			bool ok = travelServ->addAstronaut(selectedTravel, selectedAstronaut);

			if (ok)
			{
				std::cout << "Astronauta " << selectedAstronaut->getName() << " cadastrado no vôo de código " << selectedTravel->getCode() << "! \n";
			}
			else
			{
				std::cout << "Não foi possível cadastrar o astronauta no vôo. Lamentamos o ocorrido.\n";
			}
		}
	}
}

void Handler::handleShowTravels(TravelService *service)
{
	auto travels = service->getTravelsData();

	if (travels->size() == 0)
	{
		std::cout << "Não há vôos cadastrados.\n";
		std::cin.ignore();
		return;
	}

	for (auto t = travels->begin(); t != travels->end(); t++)
	{
		auto astronautsOnTravel = t->getAstronautsScheduledForTravel();

		auto travelStatus = t->getStatus();
		std::string status;
		switch (travelStatus)
		{
		case PLANNED:
			status = "Em planejamento.";
			break;
		case ONGOING:
			status = "Lançado.";
			break;
		case COMPLETED:
			status = "Completado com sucesso.";
			break;
		case EXPLODED:
			status = "Explodido.";
			break;
		default:
			status = "Indefinido.";
			break;
		}

		std::cout << "-> Vôo " << t->getCode() << ": \n";
		std::cout << "	- Origem: " << t->getOrigin() << "\n";
		std::cout << "	- Destino: " << t->getDestination() << "\n";
		std::cout << "	- Status: " << status << "\n";

		if (astronautsOnTravel->size() == 0)
		{
			std::cout << "	- Sem passageiros. \n";
			std::cin.ignore();
			continue;
		}

		std::cout << "	- Lista de passageiros: ";
		for (auto a = astronautsOnTravel->begin(); a != astronautsOnTravel->end(); a++)
		{
			std::cout << a->getName();
			std::cout << "; ";
		}
		std::cout << "\n";
		std::cin.ignore();
	}
}