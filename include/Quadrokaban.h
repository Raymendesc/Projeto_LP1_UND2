#ifndef QUADROKANBAN_H
#define QUADROKANBAN_H

#include <vector>
#include "Tarefa.h"

class QuadroKanban {
public:
    QuadroKanban();
    ~QuadroKanban();

    void adicionarTarefa(Tarefa tarefa);
    void adicionarTarefa(std::string nome);
    void adicionarTarefa(std::string nome, std::string descricao);
    void removerTarefa(Tarefa tarefa);
    void removerTarefa(int indice);
    void classificarTarefas();

private:
    std::vector<Tarefa> tarefas;
};

#endif

