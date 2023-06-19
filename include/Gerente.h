#ifndef GERENTE_H
#define GERENTE_H

#include <string>
#include <vector>
#include "Funcionario.h"

class Gerente : public Funcionario {
public:
    Gerente(std::string nome) : Funcionario(nome) {}

    void distribuirTarefa(Tarefa tarefa, std::vector<Funcionario*> funcionarios) {
        for (Funcionario* funcionario : funcionarios) {
            funcionario->adicionarTarefa(tarefa);
        }
    }
};

#endif
