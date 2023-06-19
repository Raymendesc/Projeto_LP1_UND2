#ifndef DESENVOLVEDOR_H
#define DESENVOLVEDOR_H

#include <string>
#include "Funcionario.h"

class Desenvolvedor : public Funcionario {
public:
    Desenvolvedor(std::string nome) : Funcionario(nome) {}

    void realizarTarefa(Tarefa tarefa) {
    tarefa.setStatus();
    
  }

};

#endif
