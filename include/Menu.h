/**
 * @file Menu.h
 *
 * @brief Este arquivo contém a declaração da classe Menu, responsável por gerenciar as opções do programa.
 */
#ifndef MENU_H
#define MENU_H

#include "Kanban.h"

class Menu {
public:
    /**
     * Construtor da classe Menu.
     */
    Menu();

    /**
     * Executa o menu principal.
     */
    void run();

private:
    /**
     * Exibe o menu principal.
     */
    void exibirMenu() const;

    /**
     * Adiciona uma nova tarefa ao quadro Kanban.
     */
    void adicionarTarefa();

    /**
     * Exibe o quadro Kanban.
     */
    void exibirQuadroKanban() const;

    /**
     * Move uma tarefa para um novo status.
     */
    void moverTarefa();

    /**
     * Procura uma tarefa pelo nome.
     */
    void encontrarTarefa();

    /**
     * Ordena as tarefas do quadro Kanban.
     */
    void ordenarTarefas();

    /**
     * Exibe os detalhes de uma tarefa.
     *
     * @param tarefa Ponteiro para a tarefa a ser exibida.
     */
    void exibirTarefa(Tarefa* tarefa) const;
    
private:
    Kanban kanban;
};

#endif
