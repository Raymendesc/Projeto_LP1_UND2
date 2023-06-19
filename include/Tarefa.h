#ifndef TAREFA_H
#define TAREFA_H

#include <string>

class Tarefa {
public:
    Tarefa(std::string nome) : nome(nome) {}
    Tarefa(std::string nome, std::string descricao) : nome(nome), descricao(descricao) {}
    Tarefa(std::string nome, std::string descricao, int prioridade, std::string dataAgendada, std::string status)
        : nome(nome), descricao(descricao), prioridade(prioridade), dataAgendada(dataAgendada), status(status) {}
    ~Tarefa();

    std::string getNome();
    void setNome(std::string nome);
    std::string getDescricao();
    void setDescricao(std::string descricao);
    int getPrioridade();
    void setPrioridade(int prioridade);
    std::string getDataAgendada();
    void setDataAgendada(std::string dataAgendada);
    std::string getStatus();
    void setStatus(std::string status);

private:
    std::string nome;
    std::string descricao;
    int prioridade;
    std::string dataAgendada;
    std::string status;
};

#endif


