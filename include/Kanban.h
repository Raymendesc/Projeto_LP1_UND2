/**
 * @file Kanban.h
 *
 * @brief Este arquivo contém a definição da classe Kanban, que representa o quadro Kanban com as tarefas.
 */
#ifndef KANBAN_H
#define KANBAN_H

#include "Tarefa.h"
#include "TarefaBasica.h"
#include "TarefaImportante.h"
#include "TarefaUrgente.h"

#include <map>
#include <vector>

/**
 * @brief Classe que representa um Kanban.
 * 
 * Kanban é responsável por gerenciar um quadro Kanban com tarefas.
 */
class Kanban {
public:
    /**
     * @brief Construtor da classe Kanban.
     */
    Kanban();

    /**
     * @brief Adiciona uma tarefa ao quadro Kanban.
     * @param tarefa Um ponteiro para a tarefa a ser adicionada.
     */
    void adicionarTarefa(Tarefa* tarefa);

    /**
     * @brief Exibe o quadro Kanban na saída padrão.
     */
    void exibirQuadroKanban() const;

    /**
     * @brief Move uma tarefa para um novo status no quadro Kanban.
     * @param tarefa Um ponteiro para a tarefa a ser movida.
     * @param novoStatus O novo status da tarefa.
     */
    void moverTarefa(Tarefa* tarefa, const std::string& novoStatus);

    /**
     * @brief Encontra uma tarefa com base na sua descrição.
     * @param descricao A descrição da tarefa a ser encontrada.
     * @return Um ponteiro para a tarefa encontrada, ou nullptr se não encontrada.
     */
    Tarefa* encontrarTarefa(const std::string& descricao);

    /**
     * @brief Ordena um vetor de tarefas de acordo com um tipo de ordenação especificado.
     * @param tarefas O vetor de tarefas a ser ordenado.
     * @param tipoOrdenacao O tipo de ordenação (1 - Data de Entrega, 2 - Ordem Alfabética, 3 - Prioridade).
     */
    void ordenarTarefas(std::vector<Tarefa*>& tarefas, int tipoOrdenacao);

    /**
     * @brief Obtém o quadro Kanban.
     * @return Um mapa contendo o quadro Kanban com os status e suas respectivas tarefas.
     */
    const std::map<std::string, std::vector<Tarefa*>>& getQuadroKanban() const;

private:
    /**
     * @brief Realiza o merge de duas partes de um vetor de tarefas durante o merge sort por data de entrega.
     * @param tarefas O vetor de tarefas a ser ordenado.
     * @param inicio O índice de início da primeira parte.
     * @param meio O índice de fim da primeira parte e início da segunda parte.
     * @param fim O índice de fim da segunda parte.
     */
    void merge(std::vector<Tarefa*>& tarefas, int inicio, int meio, int fim);

    /**
     * @brief Aplica o merge sort por data de entrega no vetor de tarefas.
     * @param tarefas O vetor de tarefas a ser ordenado.
     * @param inicio O índice de início do vetor.
     * @param fim O índice de fim do vetor.
     */
    void mergeSortPorDataEntrega(std::vector<Tarefa*>& tarefas, int inicio, int fim);

    /**
     * @brief Aplica o quick sort por ordem alfabética no vetor de tarefas.
     * @param tarefas O vetor de tarefas a ser ordenado.
     * @param inicio O índice de início do vetor.
     * @param fim O índice de fim do vetor.
     */
    void quickSortPorOrdemAlfabetica(std::vector<Tarefa*>& tarefas, int inicio, int fim);

    /**
     * @brief Realiza a partição do vetor de tarefas durante o quick sort por ordem alfabética.
     * @param tarefas O vetor de tarefas a ser ordenado.
     * @param inicio O índice de início da partição.
     * @param fim O índice de fim da partição.
     * @return O índice do pivô após a partição.
     */
    int particionarPorOrdemAlfabetica(std::vector<Tarefa*>& tarefas, int inicio, int fim);

    /**
     * @brief Realiza o heapify no vetor de tarefas durante o heap sort por prioridade.
     * @param tarefas O vetor de tarefas a ser ordenado.
     * @param tamanhoHeap O tamanho do heap.
     * @param indiceRaiz O índice da raiz do heap.
     */
    void heapify(std::vector<Tarefa*>& tarefas, int tamanhoHeap, int indiceRaiz);

    /**
     * @brief Aplica o heap sort por prioridade no vetor de tarefas.
     * @param tarefas O vetor de tarefas a ser ordenado.
     */
    void heapSortPorPrioridade(std::vector<Tarefa*>& tarefas);

    /**
     * @brief Compara duas datas de entrega.
     * @param data1 A primeira data de entrega.
     * @param data2 A segunda data de entrega.
     * @return true se a data1 é anterior à data2, false caso contrário.
     */
    bool compararDataEntrega(const std::string& data1, const std::string& data2);

private:
    std::map<std::string, std::vector<Tarefa*>> quadroKanban; /**< O quadro Kanban com os status e suas respectivas tarefas. */
};

#endif
