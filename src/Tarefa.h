/**
 * @file Tarefa.h
 *
 * @brief Este arquivo contém a declaração da classe Tarefa, que representa uma tarefa com descrição e data de entrega.
 */
#ifndef TAREFA_H
#define TAREFA_H

#include <string>

/**
 * @brief Classe base que representa uma tarefa.
 */
class Tarefa {
public:
    /**
     * @brief Construtor da classe Tarefa.
     * @param descricao A descrição da tarefa.
     * @param dataEntrega A data de entrega da tarefa.
     */
    Tarefa(const std::string& descricao, const std::string& dataEntrega);

    /**
     * @brief Destrutor virtual da classe Tarefa.
     */
    virtual ~Tarefa() {}

    /**
     * @brief Obtém a descrição da tarefa.
     * @return A descrição da tarefa.
     */
    std::string getDescricao() const;

    /**
     * @brief Obtém a data de entrega da tarefa.
     * @return A data de entrega da tarefa.
     */
    std::string getDataEntrega() const;

    /**
     * @brief Obtém o tipo da tarefa.
     * @return O tipo da tarefa.
     * @note Esta é uma função virtual pura a ser implementada pelas classes derivadas.
     */
    virtual std::string getTipo() const = 0;

    /**
     * @brief Atualiza o status da tarefa.
     * @param novoStatus O novo status da tarefa.
     * @note Esta é uma função virtual pura a ser implementada pelas classes derivadas.
     */
    virtual void atualizarStatus(const std::string& novoStatus) = 0;

private:
    std::string descricao; /**< A descrição da tarefa. */
    std::string dataEntrega; /**< A data de entrega da tarefa. */
};

#endif
