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
    std::cout << "MENU DE OPERAÇÕES\n";
    showOptions();

    std::cin >> choice;

    switch (choice)
    {
    case 0: 
      break;
    case 1:
      handler->handleDisplayAstronauts();
      redirect();
      break;
    case 2:
      handler->handleCreateAstronaut();
      redirect();
      break;
    case 3:
      handler->handleDisplayTravels();
      redirect();
      break;
    case 4:
      handler->handleCreateTravel();
      redirect();
      break;
    case 5:
      handler->handleAddAstronautToTravel();
      redirect();
      break;
    case 6:
      handler->handleRemoveAstronautToTravel();
      redirect();
      break;
    case 7:
      handler->handleLaunchTravel();
      redirect();
      break;
    case 8:
      handler->handleCheckOnGoingTravel();
      redirect();
      break;
    default:
      system("clear");
      break;
    }
  }

  delete handler;

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
  std::cout << "1 - Listar astronautas;	\n";
  std::cout << "2 - Cadastrar astronauta;	\n";
  std::cout << "3 - Listar voos;	\n";
  std::cout << "4 - Cadastrar vôo;	\n";
  std::cout << "5 - Adicionar astronauta a vôo;	\n";
  std::cout << "6 - Remover astronauta de vôo;	\n";
  std::cout << "7 - Lançar vôo;	\n";
  std::cout << "8 - Verificar vôo;	\n";
}
