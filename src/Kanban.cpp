#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <fstream>
#include <ctime>
#include <sstream>
#include "Kanban.h"

/**
 * @brief Construtor da classe Kanban.
 * 
 * Inicializa o quadro Kanban com as colunas padrão: Backlog, Em Análise, Fazendo, Testando e Entregue.
 */
Kanban::Kanban() {
    quadroKanban = {
        {"Backlog", std::vector<Tarefa*>()},
        {"Em Análise", std::vector<Tarefa*>()},
        {"Fazendo", std::vector<Tarefa*>()},
        {"Testando", std::vector<Tarefa*>()},
        {"Entregue", std::vector<Tarefa*>()}
    };
}

/**
 * @brief Adiciona uma tarefa ao quadro Kanban.
 * 
 * @param tarefa Ponteiro para a tarefa a ser adicionada.
 */
void Kanban::adicionarTarefa(Tarefa* tarefa) {
    quadroKanban["Backlog"].push_back(tarefa);
    std::ofstream arquivo;
    arquivo.open("tarefas.txt", std::ios::app);
    if (arquivo.is_open()) {
        std::string texto = tarefa->getDescricao() + "," + tarefa->getTipo() + "," + tarefa->getDataEntrega() + "\n";
        arquivo << texto;
        arquivo.close(); // Fechar o arquivo após escrever nele
    }
    else {
        std::cout << "Erro ao abrir!";
    }
}

/**
 * @brief Exibe o quadro Kanban com as tarefas em cada coluna.
 */
void Kanban::exibirQuadroKanban() const {
    std::cout << "===== Quadro Kanban =====" << std::endl;

    std::cout << "Backlog:" << std::endl;
    for (const auto& tarefa : quadroKanban.at("Backlog")) {
        std::cout << "- " << tarefa->getTipo() << ": " << tarefa->getDescricao() << " (Data de Entrega: " << tarefa->getDataEntrega() << ")" << std::endl;
    }

    std::cout << "Em Análise:" << std::endl;
    for (const auto& tarefa : quadroKanban.at("Em Análise")) {
        std::cout << "- " << tarefa->getTipo() << ": " << tarefa->getDescricao() << " (Data de Entrega: " << tarefa->getDataEntrega() << ")" << std::endl;
    }

    for (const auto& status : {"Fazendo", "Testando", "Entregue"}) {
        std::cout << status << ":" << std::endl;
        for (const auto& tarefa : quadroKanban.at(status)) {
            std::cout << "- " << tarefa->getTipo() << ": " << tarefa->getDescricao() << " (Data de Entrega: " << tarefa->getDataEntrega() << ")" << std::endl;
        }
    }
}

/**
 * @brief Move uma tarefa para uma nova coluna do quadro Kanban.
 * 
 * @param tarefa Ponteiro para a tarefa a ser movida.
 * @param novoStatus Novo status/coluna da tarefa.
 */
void Kanban::moverTarefa(Tarefa* tarefa, const std::string& novoStatus) {
    if (quadroKanban.find(novoStatus) != quadroKanban.end()) {
        for (auto& listaTarefas : quadroKanban) {
            auto& listaTarefasAtual = listaTarefas.second;
            auto it = std::find(listaTarefasAtual.begin(), listaTarefasAtual.end(), tarefa);
            if (it != listaTarefasAtual.end()) {
                listaTarefasAtual.erase(it);
                quadroKanban[novoStatus].push_back(tarefa);
                tarefa->atualizarStatus(novoStatus);
                return;
            }
        }
    }
    else {
        std::cout << "Status inválido!" << std::endl;
    }
}

/**
 * @brief Encontra uma tarefa com base na descrição.
 * 
 * @param descricao Descrição da tarefa a ser encontrada.
 * @return Ponteiro para a tarefa encontrada. Retorna nullptr se a tarefa não for encontrada.
 */
Tarefa* Kanban::encontrarTarefa(const std::string& descricao) {
    for (auto& listaTarefas : quadroKanban) {
        for (auto& tarefa : listaTarefas.second) {
            if (tarefa->getDescricao() == descricao) {
                return tarefa;
            }
        }
    }
    return nullptr;
}

/**
 * @brief Realiza a operação de merge em um vetor de tarefas, utilizado no algoritmo Merge Sort.
 * 
 * @param tarefas Vetor de tarefas a ser ordenado.
 * @param inicio Índice de início do trecho a ser mesclado.
 * @param meio Índice de meio do trecho a ser mesclado.
 * @param fim Índice de fim do trecho a ser mesclado.
 */
void Kanban::merge(std::vector<Tarefa*>& tarefas, int inicio, int meio, int fim) {
    int tamanhoEsquerda = meio - inicio + 1;
    int tamanhoDireita = fim - meio;

    std::vector<Tarefa*> tarefasEsquerda(tamanhoEsquerda);
    std::vector<Tarefa*> tarefasDireita(tamanhoDireita);

    for (int i = 0; i < tamanhoEsquerda; i++) {
        tarefasEsquerda[i] = tarefas[inicio + i];
    }

    for (int j = 0; j < tamanhoDireita; j++) {
        tarefasDireita[j] = tarefas[meio + 1 + j];
    }

    int indiceEsquerda = 0;
    int indiceDireita = 0;
    int indiceMerged = inicio;

    while (indiceEsquerda < tamanhoEsquerda && indiceDireita < tamanhoDireita) {
        if (compararDataEntrega(tarefasEsquerda[indiceEsquerda]->getDataEntrega(), tarefasDireita[indiceDireita]->getDataEntrega())) {
            tarefas[indiceMerged] = tarefasEsquerda[indiceEsquerda];
            indiceEsquerda++;
        }
        else {
            tarefas[indiceMerged] = tarefasDireita[indiceDireita];
            indiceDireita++;
        }
        indiceMerged++;
    }

    while (indiceEsquerda < tamanhoEsquerda) {
        tarefas[indiceMerged] = tarefasEsquerda[indiceEsquerda];
        indiceEsquerda++;
        indiceMerged++;
    }

    while (indiceDireita < tamanhoDireita) {
        tarefas[indiceMerged] = tarefasDireita[indiceDireita];
        indiceDireita++;
        indiceMerged++;
    }
}

/**
 * @brief Realiza o algoritmo de Merge Sort para ordenar um vetor de tarefas por data de entrega.
 * 
 * @param tarefas Vetor de tarefas a ser ordenado.
 * @param inicio Índice de início da parte do vetor a ser ordenada.
 * @param fim Índice de fim da parte do vetor a ser ordenada.
 */
void Kanban::mergeSortPorDataEntrega(std::vector<Tarefa*>& tarefas, int inicio, int fim) {
    if (inicio < fim) {
        int meio = inicio + (fim - inicio) / 2;
        mergeSortPorDataEntrega(tarefas, inicio, meio);
        mergeSortPorDataEntrega(tarefas, meio + 1, fim);
        merge(tarefas, inicio, meio, fim);
    }
}

/**
 * @brief Realiza o algoritmo de Quick Sort para ordenar um vetor de tarefas por ordem alfabética da descrição.
 * 
 * @param tarefas Vetor de tarefas a ser ordenado.
 * @param inicio Índice de início da parte do vetor a ser ordenada.
 * @param fim Índice de fim da parte do vetor a ser ordenada.
 */
void Kanban::quickSortPorOrdemAlfabetica(std::vector<Tarefa*>& tarefas, int inicio, int fim) {
    if (inicio < fim) {
        int pivo = particionarPorOrdemAlfabetica(tarefas, inicio, fim);
        quickSortPorOrdemAlfabetica(tarefas, inicio, pivo - 1);
        quickSortPorOrdemAlfabetica(tarefas, pivo + 1, fim);
    }
}

/**
 * @brief Particiona um vetor de tarefas para o algoritmo de Quick Sort, por ordem alfabética da descrição.
 * 
 * @param tarefas Vetor de tarefas a ser particionado.
 * @param inicio Índice de início da parte do vetor a ser particionada.
 * @param fim Índice de fim da parte do vetor a ser particionada.
 * @return Índice do pivô após a partição.
 */
int Kanban::particionarPorOrdemAlfabetica(std::vector<Tarefa*>& tarefas, int inicio, int fim) {
    std::string pivo = tarefas[fim]->getDescricao();
    int i = inicio - 1;

    for (int j = inicio; j <= fim - 1; j++) {
        if (tarefas[j]->getDescricao() < pivo) {
            i++;
            std::swap(tarefas[i], tarefas[j]);
        }
    }

    std::swap(tarefas[i + 1], tarefas[fim]);
    return i + 1;
}

/**
 * @brief Executa a operação de heapify em um vetor de tarefas, utilizado no algoritmo de Heap Sort.
 * 
 * @param tarefas Vetor de tarefas a ser transformado em heap.
 * @param tamanhoHeap Tamanho atual do heap.
 * @param indiceRaiz Índice da raiz do heap.
 */
void Kanban::heapify(std::vector<Tarefa*>& tarefas, int tamanhoHeap, int indiceRaiz) {
    int indiceMaior = indiceRaiz;
    int indiceEsquerda = 2 * indiceRaiz + 1;
    int indiceDireita = 2 * indiceRaiz + 2;

    if (indiceEsquerda < tamanhoHeap && tarefas[indiceEsquerda]->getTipo() < tarefas[indiceMaior]->getTipo()) {
        indiceMaior = indiceEsquerda;
    }

    if (indiceDireita < tamanhoHeap && tarefas[indiceDireita]->getTipo() < tarefas[indiceMaior]->getTipo()) {
        indiceMaior = indiceDireita;
    }

    if (indiceMaior != indiceRaiz) {
        std::swap(tarefas[indiceRaiz], tarefas[indiceMaior]);
        heapify(tarefas, tamanhoHeap, indiceMaior);
    }
}

/**
 * @brief Realiza o algoritmo de Heap Sort para ordenar um vetor de tarefas por prioridade.
 * 
 * @param tarefas Vetor de tarefas a ser ordenado.
 */
void Kanban::heapSortPorPrioridade(std::vector<Tarefa*>& tarefas) {
    int tamanhoHeap = tarefas.size();

    // Construir o heap máximo
    for (int i = tamanhoHeap / 2 - 1; i >= 0; i--) {
        heapify(tarefas, tamanhoHeap, i);
    }

    // Extrair os elementos do heap um por um
    for (int i = tamanhoHeap - 1; i > 0; i--) {
        std::swap(tarefas[0], tarefas[i]);
        heapify(tarefas, i, 0);
    }
}

/**
 * @brief Ordena um vetor de tarefas de acordo com o tipo de ordenação especificado.
 * 
 * @param tarefas Vetor de tarefas a ser ordenado.
 * @param tipoOrdenacao Tipo de ordenação: 1 para ordenar por data de entrega, 2 por ordem alfabética da descrição, 3 por prioridade.
 */
void Kanban::ordenarTarefas(std::vector<Tarefa*>& tarefas, int tipoOrdenacao) {
    switch (tipoOrdenacao) {
        case 1:
            mergeSortPorDataEntrega(tarefas, 0, tarefas.size() - 1);
            break;
        case 2:
            quickSortPorOrdemAlfabetica(tarefas, 0, tarefas.size() - 1);
            break;
        case 3:
            heapSortPorPrioridade(tarefas);
            break;
        default:
            std::cout << "Opção inválida!" << std::endl;
            break;
    }
}

/**
 * @brief Obtém o quadro Kanban atual.
 * 
 * @return Mapa contendo o quadro Kanban com as colunas e suas respectivas listas de tarefas.
 */
const std::map<std::string, std::vector<Tarefa*>>& Kanban::getQuadroKanban() const {
    return quadroKanban;
}

/**
 * @brief Compara duas datas de entrega no formato "dd/mm/aaaa".
 * 
 * @param data1 Primeira data de entrega.
 * @param data2 Segunda data de entrega.
 * @return true se data1 é menor que data2, false caso contrário.
 */
bool Kanban::compararDataEntrega(const std::string& data1, const std::string& data2) {
    std::tm tm1 = {};
    std::tm tm2 = {};

    // Extrair dia, mês e ano das datas
    int dia1, mes1, ano1;
    int dia2, mes2, ano2;

    sscanf(data1.c_str(), "%d/%d/%d", &dia1, &mes1, &ano1);
    sscanf(data2.c_str(), "%d/%d/%d", &dia2, &mes2, &ano2);

    tm1.tm_mday = dia1;
    tm1.tm_mon = mes1 - 1;
    tm1.tm_year = ano1 - 1900;

    tm2.tm_mday = dia2;
    tm2.tm_mon = mes2 - 1;
    tm2.tm_year = ano2 - 1900;

    std::time_t time1 = std::mktime(&tm1);
    std::time_t time2 = std::mktime(&tm2);

    return time1 < time2;
}
