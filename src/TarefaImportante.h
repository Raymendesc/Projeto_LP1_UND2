/**
 * @file TarefaImportante.h
 *
 * @brief Este arquivo contém a definição da classe TarefaImportante, que representa uma tarefa importante derivada da classe Tarefa.
 */
#ifndef TAREFAIMPORTANTE_H
#define TAREFAIMPORTANTE_H

#include "Tarefa.h"

/**
 * @brief Classe que representa uma tarefa importante.
 * 
 * TarefaImportante é uma classe derivada da classe base Tarefa.
 */
class TarefaImportante : public Tarefa {
public:
    /**
     * @brief Construtor da classe TarefaImportante.
     * @param descricao A descrição da tarefa importante.
     * @param dataEntrega A data de entrega da tarefa importante.
     */
    TarefaImportante(const std::string& descricao, const std::string& dataEntrega);

    /**
     * @brief Obtém o tipo da tarefa.
     * @return O tipo da tarefa, que é "Tarefa Importante".
     */
    std::string getTipo() const override;

    /**
     * @brief Atualiza o status da tarefa importante.
     * @param novoStatus O novo status da tarefa importante.
     * @note Esta função exibe o novo status da tarefa importante.
     */
    void atualizarStatus(const std::string& novoStatus) override;
};

#endif
