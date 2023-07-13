/**
 * @file TarefaUrgente.cpp
 *
 * @brief Este arquivo contém a implementação dos métodos da classe TarefaUrgente.
 */
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <fstream>
#include <ctime>
#include <sstream>
#include "TarefaUrgente.h"

/**
 * @brief Construtor da classe TarefaUrgente.
 * @param descricao A descrição da tarefa urgente.
 * @param dataEntrega A data de entrega da tarefa urgente.
 */
TarefaUrgente::TarefaUrgente(const std::string& descricao, const std::string& dataEntrega) : Tarefa(descricao, dataEntrega) {}

/**
 * @brief Obtém o tipo da tarefa urgente.
 * @return O tipo da tarefa, que é "Tarefa Urgente".
 */
std::string TarefaUrgente::getTipo() const {
    return "Tarefa Urgente";
}

/**
 * @brief Atualiza o status da tarefa urgente.
 * @param novoStatus O novo status da tarefa urgente.
 * @note Esta função exibe o novo status da tarefa urgente.
 */
void TarefaUrgente::atualizarStatus(const std::string& novoStatus) {
    std::cout << "Atualizando status da Tarefa Urgente para: " << novoStatus << std::endl;
}
