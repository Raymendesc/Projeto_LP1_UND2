/**
 * @file TarefaBasica.cpp
 *
 * @brief Este arquivo contém a implementação dos métodos da classe TarefaBasica.
 */
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <fstream>
#include <ctime>
#include <sstream>
#include "TarefaBasica.h"

/**
 * @brief Construtor da classe TarefaBasica.
 * @param descricao A descrição da tarefa básica.
 * @param dataEntrega A data de entrega da tarefa básica.
 */
TarefaBasica::TarefaBasica(const std::string& descricao, const std::string& dataEntrega) : Tarefa(descricao, dataEntrega) {}

/**
 * @brief Obtém o tipo da tarefa básica.
 * @return O tipo da tarefa, que é "Tarefa Básica".
 */
std::string TarefaBasica::getTipo() const {
    return "Tarefa Básica";
}

/**
 * @brief Atualiza o status da tarefa básica.
 * @param novoStatus O novo status da tarefa básica.
 * @note Esta função exibe o novo status da tarefa básica.
 */
void TarefaBasica::atualizarStatus(const std::string& novoStatus) {
    std::cout << "Atualizando status da Tarefa Básica para: " << novoStatus << std::endl;
}
