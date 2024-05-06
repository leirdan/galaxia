#include <iostream>
#include <list>
#include "../domain/interfaces/Astronaut.hpp"
#include "../domain/interfaces/Travel.hpp"
#include "AstronautService.hpp"
#include "TravelService.hpp"
#include "Handler.hpp"
#include "../utils/random.h"

Handler::Handler() {}
Handler::~Handler() {}

bool checkCpfInput(const std::string &cpf)
{
  for (char c : cpf)
  {
    if (std::isalpha(c))
      return false;
  }

  return true;
}

void readCpf(std::string &cpf)
{
  bool validCpf = false;
  while (true)
  {
    std::cout << "Digite o CPF do astronauta: ";
    std::getline(std::cin, cpf);
    validCpf = checkCpfInput(cpf);
    if (validCpf)
      break;
    else
      std::cout << "CPF inválido, digite novamente!\n";
  }
}

Astronaut *Handler::handleCreateAstronaut()
{
  std::string name, cpf;
  int age;

  std::cout << "Você escolheu 'Cadastrar Astronauta'. \n";
  std::cout << "Digite o nome do astronauta: ";
  std::cin.ignore();
  std::getline(std::cin, name);

  // TODO: deal with duplicated cpf

  readCpf(cpf);

  std::cout << "Digite a idade do astronauta: ";
  std::cin >> age;

  auto result = this->_astronautService->createAstronaut(name, cpf, age);

  if (result == nullptr)
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

Travel *Handler::handleCreateTravel()
{
  std::string origin, destination;

  std::cout << "Você escolheu 'Cadastrar vôo'. \n";
  std::cout << "Ponto de partida (opcional): ";
  std::cin.ignore();
  std::getline(std::cin, origin);

  std::cout << "Destino (opcional): ";
  std::getline(std::cin, destination);

  auto result = this->_travelService->createTravel(origin, destination);

  if (result == nullptr)
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

void Handler::handleAddAstronautToTravel()
{
  std::string cpf;
  unsigned int travelCode;

  std::cout << "Você escolheu 'Adicionar astronauta em vôo'. \n";
  std::cin.ignore();

  readCpf(cpf);

  auto selectedAstronaut = this->_astronautService->searchByCpf(cpf);

  if (selectedAstronaut == nullptr)
  {
    std::cout << "O astronauta com CPF " << cpf << " não existe. \n";
    return;
  }
  else if (selectedAstronaut->getStatus() == AstronautStatus::DEAD)
  {
    std::cout << "O astronauta com CPF " << cpf << " está morto. \n";
    return;
  }

  std::cout << "Digite o código do vôo: ";
  std::cin >> travelCode;

  auto selectedTravel = this->_travelService->searchByCode(travelCode);
  if (selectedTravel == nullptr)
  {
    std::cout << "Não existe vôo planejado com esse código. \n";
    std::cin.ignore();
    return;
  }
  else if (selectedTravel->getStatus() != TravelStatus::PLANNED)
  {
    std::cout << "Este vôo não aceita mais novos astronautas. \n";
    std::cin.ignore();
    return;
  }
  else if (this->_astronautTravelService->findAstronautScheduledForTravel(selectedTravel, cpf) != nullptr)
  {
    std::cout << "Este astronauta já está participando do vôo! \n";
    std::cin.ignore();
    return;
  }

  bool ok = this->_astronautTravelService->addAstronautToTravel(selectedTravel, selectedAstronaut);

  if (ok)
    std::cout << "Astronauta " << selectedAstronaut->getName() << " cadastrado no vôo de código " << selectedTravel->getCode() << "! \n";
  else
    std::cout << "Não foi possível cadastrar o astronauta no vôo. Lamentamos o ocorrido.\n";

  std::cin.ignore();
  return;
}

void Handler::handleDisplayTravels()
{
  auto travels = this->_travelService->getTravelsData();

  if (travels->size() == 0)
  {
    std::cout << "Não há vôos cadastrados.\n";
    std::cin.ignore();
    return;
  }

  for (auto t = travels->begin(); t != travels->end(); t++)
  {
    auto astronautsOnTravel = this->_astronautTravelService->getAstronautsOnTravel(t->getCode());

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
      status = "Finalizado com sucesso.";
      break;
    case EXPLODED:
      status = "Finalizado com falha: explodiu.";
      break;
    default:
      status = "Indefinido.";
      break;
    }

    std::cout << "-> Vôo " << t->getCode() << ": \n";
    std::cout << "	- Origem: " << t->getOrigin() << "\n";
    std::cout << "	- Destino: " << t->getDestination() << "\n";
    std::cout << "	- Status: " << status << "\n";
    std::cin.ignore();

    if (astronautsOnTravel == nullptr || astronautsOnTravel->size() == 0)
    {
      std::cout << "	- Sem passageiros. \n";
      std::cin.ignore();
      continue;
    }

    std::cout << "	- Lista de passageiros: ";

    for (auto it = astronautsOnTravel->begin(); it != astronautsOnTravel->end(); it++)
    {
      Astronaut *ptr = *it;
      std::cout << ptr->getName() << ", " << "CPF " << ptr->getCpf() << "; ";
    }
    // TODO: fix the output
    std::cout << "\n";
    std::cin.ignore();
  }
}

void Handler::handleDisplayAstronauts()
{
  std::cin.ignore();
  std::cout << "Você escolheu 'Listar Astronautas'. \n";

  std::cout << "=======================\n";
  std::cout << "ASTRONAUTAS DISPONÍVEIS\n";
  std::cout << "=======================\n";

  printAstronauts(AstronautStatus::AVAILABLE);

  std::cout << "=======================\n";
  std::cout << " ASTRONAUTAS EM MISSÃO \n";
  std::cout << "=======================\n";

  printAstronauts(AstronautStatus::ONGOINGTRAVEL);

  std::cout << "=======================\n";
  std::cout << " ASTRONAUTAS FALECIDOS \n";
  std::cout << "=======================\n";

  printAstronauts(AstronautStatus::DEAD);

  return;
}

void Handler::printAstronauts(AstronautStatus status)
{
  auto astronauts = this->_astronautService->getAstronautsByStatus(status);

  if (astronauts == nullptr)
  {
    std::cout << "Nenhum. \n";
    return;
  }

  for (auto a = astronauts->begin(); a != astronauts->end(); a++)
  {
    auto astronaut = *a;
    std::cout << "* Astronauta " << astronaut->getName() << "\n"
      << "  - Id: " << astronaut->getId() << "\n"
      << "  - Idade: " << astronaut->getAge() << "\n"
      << "  - CPF: " << astronaut->getCpf() << "\n"
      << "  - Status: " << astronaut->getStatusToString() << "\n";

    if (astronaut->getStatus() == AstronautStatus::DEAD)
    {
      std::cout << "  - Vôos: ";

      auto travelsByAstronaut = this->_astronautTravelService->getTravelsByAstronaut(astronaut);

      if (travelsByAstronaut == nullptr)
        std::cout << "nenhum. \n";
      else
      {
        for (auto t = travelsByAstronaut->begin(); t != travelsByAstronaut->end(); t++)
        {
          auto travel = *t;
          std::cout << travel->getCode() << "; ";
        }
        std::cout << "\n";
      }
    }
    std::cout << "----------------------\n";
  }
}

void Handler::handleRemoveAstronautToTravel()
{
  std::string cpf;
  unsigned int travelCode;
  std::cout << "Você escolheu 'Remover Astronauta de um Vôo'. \n";
  std::cout << "Digite o CPF do astronauta: ";
  std::cin >> cpf;

  auto selectedAstronaut = this->_astronautService->searchByCpf(cpf);

  if (selectedAstronaut == nullptr)
  {
    std::cout << "O astronauta com CPF " << cpf << " não existe. \n";
    std::cin.ignore();
    return;
  }

  std::cout << "Digite o código do vôo: ";
  std::cin >> travelCode;

  auto selectedTravel = this->_travelService->searchByCode(travelCode);

  if (selectedTravel == nullptr)
  {
    std::cout << "Não existe vôo com esse código. \n";
    std::cin.ignore();
    return;
  }
  else if (selectedTravel->getStatus() != TravelStatus::PLANNED)
  {
    std::cout << "Este vôo não aceita mais alterações. \n";
    std::cin.ignore();
    return;
  }
  else if (this->_astronautTravelService->findAstronautScheduledForTravel(selectedTravel, cpf) == nullptr)
  {
    std::cout << "Este astronauta não está participando do vôo. \n";
    std::cin.ignore();
    return;
  }

  auto ok = this->_astronautTravelService->removeAstronautOnTravel(selectedTravel->getCode(), selectedAstronaut->getId());

  if (ok)
  {
    std::cout << "Astronauta " << selectedAstronaut->getName() << " removido do vôo " << selectedTravel->getCode() << ".\n";
    std::cin.ignore();
  }
  else
  {
    std::cout << "Não foi possível remover o astronauta do vôo. Lamentamos o ocorrido. \n";
    std::cin.ignore();
  }
  return;
}

void Handler::handleLaunchTravel()
{
  unsigned int travelCode;

  std::cout << "Você escolheu a opção 'Lançar vôo'. \n";
  std::cout << "Digite o código do vôo: ";
  std::cin >> travelCode;

  auto selectedTravel = this->_travelService->searchByCode(travelCode);

  std::list<Astronaut *> *astronautsOnTravel = nullptr;

  if (selectedTravel != nullptr)
    astronautsOnTravel = this->_astronautTravelService->getAstronautsOnTravel(selectedTravel->getCode());

  if (selectedTravel == nullptr)
  {
    std::cout << "Não existe nenhum vôo cadastrado com esse código. \n";
    std::cin.ignore();
    return;
  }
  else if (selectedTravel->getStatus() != TravelStatus::PLANNED)
  {
    std::cout << "O vôo escolhido não está disponível para lançamento. \n";
    std::cin.ignore();
    return;
  }
  else if (astronautsOnTravel == nullptr || astronautsOnTravel->size() < 1)
  {
    std::cout << "O vôo não tem passageiros. \n";
    std::cin.ignore();
    return;
  }

  bool isAllAstronautsAvailable = true;
  for (auto a = astronautsOnTravel->begin(); a != astronautsOnTravel->end(); a++)
  {
    auto astronaut = *a;
    if (astronaut->getStatus() != AVAILABLE)
    {
      isAllAstronautsAvailable = false;
      break;
    }
  }

  if (!isAllAstronautsAvailable)
  {
    std::cout << "Certifique-se de que todos os astronautas estejam disponíveis.\n";
    std::cin.ignore();
    return;
  }

  for (auto a = astronautsOnTravel->begin(); a != astronautsOnTravel->end(); a++)
  {
    auto astronaut = *a;
    astronaut->setStatus(ONGOINGTRAVEL);
  }

  selectedTravel->setStatus(TravelStatus::ONGOING);

  delete astronautsOnTravel;

  std::cout << "Vôo " << selectedTravel->getCode() << " com destino a " << selectedTravel->getDestination() << " lançado! \n";
  std::cin.ignore();
  return;
}

void Handler::handleCheckOnGoingTravel()
{
  std::cout << "Você escolheu a opção 'Verificar vôo'. \n";

  unsigned int travelCode;
  auto allTravels = this->_travelService->getTravelsData();

  auto onGoingTravels = this->_astronautTravelService->getOnGoingTravels(allTravels);

  if (onGoingTravels == nullptr || onGoingTravels->size() == 0)
  {
    std::cout << "Nenhum vôo foi lançado. \n";
    std::cin.ignore();
    return;
  }

  std::cout << "Estes são os códigos dos vôos já lançados: \n";

  for (auto t = onGoingTravels->begin(); t != onGoingTravels->end(); t++)
  {
    auto travel = *t;
    std::cout << "* " << travel->getCode() << ": " << travel->getOrigin() << " -> " << travel->getDestination() << "\n";
  }

  std::cout << "Digite o código de qual vôo você deseja analisar: ";
  std::cin >> travelCode;

  auto selectedTravel = this->_travelService->searchByCode(travelCode);

  if (selectedTravel == nullptr || selectedTravel->getStatus() != TravelStatus::ONGOING)
  {
    std::cout << "Não existe um vôo lançado com esse código. \n";
    std::cin.ignore();
    return;
  }

  int chance = generateNumberOnInterval(1, 100);

  auto astronautsOnTravel = this->_astronautTravelService->getAstronautsOnTravel(selectedTravel->getCode());

  // Exploded
  if (chance >= 1 && chance < 70)
  {
    selectedTravel->setStatus(EXPLODED);

    for (auto a = astronautsOnTravel->begin(); a != astronautsOnTravel->end(); a++)
    {
      auto *astronaut = *a;
      astronaut->setStatus(DEAD);
    }

    std::cout << "Oops... a nave sofreu algum acidente em sua missão. Não houve sobreviventes. \n";
    std::cin.ignore();
    return;
  }
  // Alright
  else if (chance >= 70 && chance <= 100)
  {
    selectedTravel->setStatus(COMPLETED);

    for (auto a = astronautsOnTravel->begin(); a != astronautsOnTravel->end(); a++)
    {
      auto *astronaut = *a;
      astronaut->setStatus(AVAILABLE);
    }

    auto message = selectedTravel->getDestination().compare("Indefinido")
                       ? "A nave pousou com sucesso em seu destino. "
                       : "A nave pousou com sucesso em " + selectedTravel->getDestination() + ". ";

    std::cout << message << "Os astronautas já estão de volta e prontos para outra missão! \n";
    std::cin.ignore();
    return;
  }
  else
  {
    std::cout << "Ocorreu um erro no processamento dos dados. \n";
    std::cin.ignore();
    return;
  }
}
