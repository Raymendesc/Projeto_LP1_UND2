#ifndef AVALIADOR_H
#define AVALIADOR_H

#include <string>
#include "Funcionario.h"

class Avaliador : public Funcionario {
public:
    Avaliador(std::string nome) : Funcionario(nome) {}

    bool avaliarTarefa(Tarefa tarefa) {
    if (tarefa.getStatus() == "completa") {
        return true;
    } else {
        return false;
    }
}

};
      
#endif
