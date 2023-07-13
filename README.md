# Projeto_LP1_UND2
Repositório do projeto da disciplina de Linguagem de Programação I
# Projeto Quadro Kanban
O projeto será um Gerenciador de Tarefas de Metodologia Ágil com Método Kanban, ele adiciona tarefas, define prioridades, agenda datas e classifica as tarefas.

### Detalhes tecnicos sobre o Projeto

#### Sobre o TADS
- As tarefas serão amarzenadas por Status (Backlog, Em Análise, Fazendo, Testando e Entregue (quadro kanban)) em uma lista encadeada. E serão exibidas na função "Exibir Quadro Kanban".
 
#### Busca
- A busca binária foi implementada na  função de "Encontrar Tarefa", presente no gerenciador, que ao digitar a tarefa que está procurando, ela informa qual a prioridade da tarefa (Básica, Importante, Urgente) e sua Data de Entrega.

#### Ordenação
A ordenação foi implementada da seguinte maneira:
- Merge Sort por Data de Entrega da Tarefa;
- Quick Sort Por Ordem Alfabética;
- Heap Sort por Prioridade.

#### Manipulação de Arquivos
Ao adicionar uma atividade no gerenciador e colocar suas informações (Descrição (Nome), Prioridade e Data de Entrega, um arquivo. txt é gerado e adicionado, salvando todas essas informações geradas pelo usuário. 

## Diagrama de Classes

![diagrama de classes](https://github.com/Raymendesc/Projeto_LP1_UND2/blob/main/docs/DiagramdeClasses.png)


## Diagrama de Caso de Uso
![Caso de Uso UML](https://github.com/Raymendesc/Projeto_LP1_UND2/blob/main/docs/DiagramaCasosdeUso.png)
