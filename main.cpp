#include <iostream>
#include <cstdio>
#include "services/Handler.hpp"

void redirect();
void showOptions();

int main()
{
  system("clear");

	int choice = 1;

	std::cout << "Bem vindo/a ao GALAXIA! \n";

	auto handler = new Handler();

	while (choice != 0)
	{
		std::cout << "Qual operação deseja realizar? \n";
		showOptions();

		std::cin >> choice;

		switch (choice)
		{
		case 1:
			handler->handleCreateAstronaut();
			redirect();
			break;
		case 2:
			handler->handleCreateTravel();
			redirect();
			break;
		case 3:
			handler->handleAddAstronautToTravel();
			redirect();
			break;
		case 4:
			handler->handleDisplayTravels();
			redirect();
			break;
		case 5:
			handler->handleRemoveAstronautToTravel();
			redirect();
			break;
		case 6:
			handler->handleLaunchTravel();
			redirect();
			break;
		default:
			delete handler;
			break;
		}
	}

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
	std::cout << "5 - Remover astronauta de vôo;	\n";
	std::cout << "6 - Lançar vôo;	\n";
}
