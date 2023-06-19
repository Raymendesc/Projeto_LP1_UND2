# Projeto_LP1_UND2
Repositório do projeto da disciplina de Linguagem de Programação I
# Projeto Quadro Kaban
O projeto será um Gerenciador de Tarefas de Metodologia Ágil com Método Kanban, ele adiciona tarefas, define prioridades, agenda datas e classifica as tarefas.

### Detalhes tecnicos sobre o Projeto

#### Sobre o TADS
- As tarefas serão amarzenadas por colunas (quadro kaban) em uma lista duplamente encadeada.
- Para armazenar as tarefas que estão em espera e serão atribuídas ao desenvolvedor (Pessoa que irá executar a tarefa) usaremos uma fila. 

#### Busca
- Para a busca binária, vamos implementá-la em uma lista ordenada de tarefas (a decidir: data_de_entrega, prioridade, status). Isso permitiria encontrar rapidamente uma tarefa específica.

#### Ordenação
- Para ordenar as tarefas que precisam ser realizadas por prioridade usaremos o Quick sort e para agendar as tarefas que serão feitas por data de entrega, usaremos Merge Sort.  

## Diagrama de Classes

![diagrama de classes]()


## Diagrama de Caso de Uso
![Caso de Uso UML](https://github.com/Raymendesc/Projeto_LP1_UND2/blob/main/docs/Diagrama%20Caso%20de%20Uso.png)
