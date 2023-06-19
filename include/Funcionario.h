#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#include <string>
#include <vector>
#include "Tarefa.h"

class Funcionario {
public:
    Funcionario(std::string nome) : nome(nome) {}

    std::string getNome() {
        return nome;
    }

    void adicionarTarefa(Tarefa tarefa) {
        tarefas.push_back(tarefa);
    }

    std::vector<Tarefa> getTarefas() {
        return tarefas;
    }

private:
    std::string nome;
    std::vector<Tarefa> tarefas;
};

#endif
