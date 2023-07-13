#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <fstream>
#include <ctime>
#include <sstream>
#include "Tarefa.h"

/**
 * @brief Construtor da classe Tarefa.
 * @param descricao A descrição da tarefa.
 * @param dataEntrega A data de entrega da tarefa.
 */
Tarefa::Tarefa(const std::string& descricao, const std::string& dataEntrega) : descricao(descricao), dataEntrega(dataEntrega) {}

/**
 * @brief Obtém a descrição da tarefa.
 * @return A descrição da tarefa.
 */
std::string Tarefa::getDescricao() const {
    return descricao;
}

/**
 * @brief Obtém a data de entrega da tarefa.
 * @return A data de entrega da tarefa.
 */
std::string Tarefa::getDataEntrega() const {
    return dataEntrega;
}

