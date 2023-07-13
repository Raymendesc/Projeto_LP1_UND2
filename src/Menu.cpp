#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <fstream>
#include <ctime>
#include <sstream>
#include "Menu.h"

Menu::Menu() {}

void Menu::run() {
    int opcao;

    do {
        exibirMenu();
        std::cout << "Escolha uma opção: ";
        std::cin >> opcao;

        switch (opcao) {
            case 1:
                adicionarTarefa();
                break;
            case 2:
                exibirQuadroKanban();
                break;
            case 3:
                moverTarefa();
                break;
            case 4:
                encontrarTarefa();
                break;
            case 5:
                ordenarTarefas();
                break;
            case 0:
                std::cout << "Encerrando o programa..." << std::endl;
                break;
            default:
                std::cout << "Opção inválida!" << std::endl;
                break;
        }

        std::cout << std::endl;
    } while (opcao != 0);
}

void Menu::exibirMenu() const {
  /**
     * @brief Exibe as opções do menu na saída padrão.
     */
    std::cout << "===== Menu =====" << std::endl;
    std::cout << "1. Adicionar Tarefa" << std::endl;
    std::cout << "2. Exibir Quadro Kanban" << std::endl;
    std::cout << "3. Mover Tarefa" << std::endl;
    std::cout << "4. Encontrar Tarefa" << std::endl;
    std::cout << "5. Ordenar Tarefas" << std::endl;
    std::cout << "0. Sair" << std::endl;
}

void Menu::adicionarTarefa() {
  /**
     * @brief Adiciona uma nova tarefa ao quadro kanban.
     */
    std::string descricao, dataEntrega;
    int tipoTarefa;

    std::cout << "Digite a descrição da tarefa: ";
    std::cin.ignore();
    std::getline(std::cin, descricao);
    std::cout << "Digite a data de entrega da tarefa: ";
    std::getline(std::cin, dataEntrega);
    std::cout << "Digite o tipo da tarefa (1 - Básica, 2 - Importante, 3 - Urgente): ";
    std::cin >> tipoTarefa;

    Tarefa* tarefa = nullptr;

    switch (tipoTarefa) {
        case 1:
            tarefa = new TarefaBasica(descricao, dataEntrega);
            break;
        case 2:
            tarefa = new TarefaImportante(descricao, dataEntrega);
            break;
        case 3:
            tarefa = new TarefaUrgente(descricao, dataEntrega);
            break;
        default:
            std::cout << "Tipo de tarefa inválido!" << std::endl;
            return;
    }

    kanban.adicionarTarefa(tarefa);
    std::cout << "Tarefa adicionada com sucesso!" << std::endl;
}

void Menu::exibirQuadroKanban() const {
  /**
     * @brief Exibe o quadro kanban na saída padrão.
     */
    kanban.exibirQuadroKanban();
}

void Menu::moverTarefa() {
  /**
     * @brief Move uma tarefa para um novo status.
     */
    std::string descricao;
    std::cout << "Digite a descrição da tarefa: ";
    std::cin.ignore();
    std::getline(std::cin, descricao);

    Tarefa* tarefa = kanban.encontrarTarefa(descricao);

    if (tarefa != nullptr) {
        std::string novoStatus;
        std::cout << "Digite o novo status da tarefa (Backlog, Em Análise, Fazendo, Testando, Entregue): ";
        std::getline(std::cin, novoStatus);

        kanban.moverTarefa(tarefa, novoStatus);
        std::cout << "Tarefa movida com sucesso!" << std::endl;
    }
    else {
        std::cout << "Tarefa não encontrada!" << std::endl;
    }
}

void Menu::encontrarTarefa() {
  /**
     * @brief Encontra uma tarefa pelo seu nome/descrição.
     */
    std::string descricao;
    std::cout << "Digite a descrição da tarefa: ";
    std::cin.ignore();
    std::getline(std::cin, descricao);

    Tarefa* tarefa = kanban.encontrarTarefa(descricao);
    exibirTarefa(tarefa); 
}

void Menu::ordenarTarefas() {
  /**
     * @brief Ordena as tarefas do quadro kanban.
     */
    std::vector<Tarefa*> tarefas;

    for (const auto& listaTarefas : kanban.getQuadroKanban()) {
        for (const auto& tarefa : listaTarefas.second) {
            tarefas.push_back(tarefa);
        }
    }

    int tipoOrdenacao;
    std::cout << "Escolha o tipo de ordenação (1 - Por Data de Entrega, 2 - Por Ordem Alfabética da Descrição, 3 - Por Prioridade): ";
    std::cin >> tipoOrdenacao;

    kanban.ordenarTarefas(tarefas, tipoOrdenacao);

    std::cout << "Tarefas ordenadas:" << std::endl;
    for (const auto& tarefa : tarefas) {
        exibirTarefa(tarefa); 
    }
}

void Menu::exibirTarefa(Tarefa* tarefa) const {
    if (tarefa != nullptr) {
        std::cout << "Tarefa encontrada: " << tarefa->getTipo() << ": " << tarefa->getDescricao() << " (Data de Entrega: " << tarefa->getDataEntrega() << ")" << std::endl;
    }
    else {
        std::cout << "Tarefa não encontrada!" << std::endl;
    }
}
