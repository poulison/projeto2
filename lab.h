#ifndef PROJECT1_LIBRARY_H
#define PROJECT1_LIBRARY_H

// Definindo a estrutura do lembrete
typedef struct lembrete{
    // Variável da prioridade
    int prioridade;
    // Variável da descrição
    char descricao[300];
    // Variável da categoria
    char categoria[100];
} Lembrete;

// Define a estrtura da lista com lembretes
typedef struct{
    // Quantidade de lembretes
    Lembrete l[100];
    // Variável da quantidade
    int qtd;
} ListaDeLembretes;

// Função que adiciona lembretes
int criarLembrete(ListaDeLembretes *ll);
// Função que deleta lembretes
int deletarLembrete(ListaDeLembretes *ll);
// Função que lista os lembretes
int listarLembrete(ListaDeLembretes ll);

//  Função que imprime o menu
void printMenu();
// Função que salva a lista de lembretes no arquivo
int salvarLista(ListaDeLembretes ll, char nome[]);
// Função que carrega os lembretes do arquivo
int carregarLista(ListaDeLembretes *ll, char nome[]);



#endif //PROJECT1_LIBRARY_H
