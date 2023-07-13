/**
 * @file TarefaUrgente.h
 *
 * @brief Este arquivo contém a definição da classe TarefaUrgente, que representa uma tarefa urgente derivada da classe Tarefa.
 */
#ifndef TAREFAURGENTE_H
#define TAREFAURGENTE_H

#include "Tarefa.h"

/**
 * @brief Classe que representa uma tarefa urgente.
 * 
 * TarefaUrgente é uma classe derivada da classe base Tarefa.
 */
class TarefaUrgente : public Tarefa {
public:
    /**
     * @brief Construtor da classe TarefaUrgente.
     * @param descricao A descrição da tarefa urgente.
     * @param dataEntrega A data de entrega da tarefa urgente.
     */
    TarefaUrgente(const std::string& descricao, const std::string& dataEntrega);

    /**
     * @brief Obtém o tipo da tarefa.
     * @return O tipo da tarefa, que é "Tarefa Urgente".
     */
    std::string getTipo() const override;

    /**
     * @brief Atualiza o status da tarefa urgente.
     * @param novoStatus O novo status da tarefa urgente.
     * @note Esta função exibe o novo status da tarefa urgente.
     */
    void atualizarStatus(const std::string& novoStatus) override;
};

#endif

