#include <iostream>
#include <list>
#include "../domain/interfaces/Astronaut.hpp"
#include "../domain/interfaces/Travel.hpp"
#include "AstronautService.hpp"
#include "TravelService.hpp"
#include "Handler.hpp"

Astronaut *Handler::handleCreateAstronaut()
{
    std::string name, cpf;
    int age;

    std::cout << "Você escolheu 'Cadastrar Astronauta'. \n";
    std::cout << "Nome do astronauta: ";
    std::cin.ignore();
    std::getline(std::cin, name);
    std::cout << "CPF: ";
    std::getline(std::cin, cpf);
    std::cout << "Idade: ";
    std::cin >> age;

    auto result = this->_astronautService->createAstronaut(name, cpf, age);

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

void Handler::handleAddAstronautToTravel()
{
    std::string cpf;
    unsigned int travelCode;

    std::cout << "Você escolheu 'Adicionar astronauta em vôo'. \n";
    std::cout << "Digite o CPF do astronauta: ";
    std::cin.ignore();
    std::getline(std::cin, cpf);

    auto selectedAstronaut = this->_astronautService->searchByCpf(cpf);

    if (selectedAstronaut == nullptr)
    {
        std::cout << "O astronauta com CPF " << cpf << " não existe. \n";
    }
    else
    {
        std::cout << "Digite o código do vôo que deseja adicionar o astronauta: ";
        std::cin >> travelCode;
        std::cin.ignore();

        auto selectedTravel = this->_travelService->searchByCode(travelCode);
        if (selectedTravel == nullptr)
        {
            std::cout << "Não existe vôo planejado com esse código. :( \n";
        }
        else if (selectedTravel->getStatus() != TravelStatus::PLANNED)
        {
            std::cout << "Este vôo não aceita mais novos astronautas.";
        }
        else
        {
            bool ok = this->_travelService->addAstronaut(selectedTravel, selectedAstronaut);

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
    else if (this->_travelService->findAstronautScheduledForTravel(selectedTravel, cpf) == nullptr)
    {
        std::cout << "Este astronauta não está participando do vôo. \n";
        std::cin.ignore();
        return;
    }

    auto ok = this->_travelService->removeAstronaut(selectedTravel, selectedAstronaut);

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