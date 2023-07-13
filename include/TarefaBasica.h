/**
 * @file TarefaBasica.h
 *
 * @brief Este arquivo contém a definição da classe TarefaBasica, que representa uma tarefa básica derivada da classe Tarefa.
 */
#ifndef TAREFABASICA_H
#define TAREFABASICA_H

#include "Tarefa.h"

/**
 * @brief Classe que representa uma tarefa básica.
 * 
 * TarefaBasica é uma classe derivada da classe base Tarefa.
 */
class TarefaBasica : public Tarefa {
public:
    /**
     * @brief Construtor da classe TarefaBasica.
     * @param descricao A descrição da tarefa básica.
     * @param dataEntrega A data de entrega da tarefa básica.
     */
    TarefaBasica(const std::string& descricao, const std::string& dataEntrega);

    /**
     * @brief Obtém o tipo da tarefa.
     * @return O tipo da tarefa, que é "Tarefa Básica".
     */
    std::string getTipo() const override;

    /**
     * @brief Atualiza o status da tarefa básica.
     * @param novoStatus O novo status da tarefa básica.
     * @note Esta função exibe o novo status da tarefa básica.
     */
    void atualizarStatus(const std::string& novoStatus) override;
};

#endif

