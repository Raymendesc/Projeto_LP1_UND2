/**
 * @file TarefaImportante.cpp
 *
 * @brief Este arquivo contém a implementação dos métodos da classe TarefaImportante.
 */
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <fstream>
#include <ctime>
#include <sstream>
#include "TarefaImportante.h"

/**
 * @brief Construtor da classe TarefaImportante.
 * @param descricao A descrição da tarefa importante.
 * @param dataEntrega A data de entrega da tarefa importante.
 */
TarefaImportante::TarefaImportante(const std::string& descricao, const std::string& dataEntrega) : Tarefa(descricao, dataEntrega) {}

/**
 * @brief Obtém o tipo da tarefa importante.
 * @return O tipo da tarefa, que é "Tarefa Importante".
 */
std::string TarefaImportante::getTipo() const {
    return "Tarefa Importante";
}

/**
 * @brief Atualiza o status da tarefa importante.
 * @param novoStatus O novo status da tarefa importante.
 * @note Esta função exibe o novo status da tarefa importante.
 */
void TarefaImportante::atualizarStatus(const std::string& novoStatus) {
    std::cout << "Atualizando status da Tarefa Importante para: " << novoStatus << std::endl;
}
