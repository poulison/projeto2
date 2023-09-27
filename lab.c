#include "library.h"
#include <stdio.h>
#include "string.h"

// Função que adiciona lembretes
int criarLembrete(ListaDeLembretes *ll) {
    printf("\nNovo Lembrete\n");
    printf("Tipo de conta: ");
    // Recebe a entrada do usuário e armazena no array da opção Tipo de conta
    scanf("%d", &ll->l[ll->qtd].Tipo de conta);
    // Limpa o buffer
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
    printf("Nome: ");
    // Recebe a entrada do usuário e armazena no array da opção Nome
    gets(ll->l[ll->qtd].Nome);
    // Substitui qualquer caractere que não seja letra, no caso \n, por \0 para simbolizar o final da string
    ll->l[ll->qtd].Nome[strcspn(ll->l[ll->qtd].Nome, "\n")] = '\0';
    printf("CPF: ");
    // Recebe a entrada do usuário e armazena no array da opção descrição
    gets(ll->l[ll->qtd].CPF);
    // Substitui qualquer caractere que não seja letra, no caso \n, por \0 para simbolizar o final da string
    ll->l[ll->qtd].CPF[strcspn(ll->l[ll->qtd].CPF, "\n")] = '\0';
    
    // Recebe a entrada do usuário e armazena no array da opção descrição
    gets(ll->l[ll->qtd].V.I);
    // Substitui qualquer caractere que não seja letra, no caso \n, por \0 para simbolizar o final da string
    ll->l[ll->qtd].V.I[strcspn(ll->l[ll->qtd].V.I, "\n")] = '\0';
    //-------------------
    printf("S.U: ");
    gets(ll->l[ll->qtd].S.U);
    // Substitui qualquer caractere que não seja letra, no caso \n, por \0 para simbolizar o final da string
    ll->l[ll->qtd].S.U[strcspn(ll->l[ll->qtd].S.U, "\n")] = '\0';
    // Aumenta a quantidade/número do lembrete
    ll->qtd = ll->qtd + 1;
    return 0;
}

// Função que deleta lembretes
int deletarLembrete(ListaDeLembretes *ll){
    printf("\nDeletar Lembrete\n");
    // Erro caso não exista lembretes
    if(ll->qtd == 0){
        printf("Nao ha lembretes, crie um");
    }
    // Variável do numero do lembrete desejado
    int numerodolembrete;
    printf("\nNumero do lembrete: ");
    // Recebe o numero do lembrete e armazena na variável
    scanf("%d", &numerodolembrete);
    // Verifica se o lembrete existe dentre os já existentes
    if(numerodolembrete < 1 || numerodolembrete > ll->qtd){
        printf("Esse lembrete nao existe");
    }
    // Caso exista lembretes e o número do lembrete exista...
    else{
        // Loop que percorre os elementos da lista
        for(int i = numerodolembrete; i < ll->qtd; i++){
            // Atribui o valor do lembrete seguinte ao lembrete desejado
            ll->l[i] = ll->l[i + 1];
        }
        // Diminui o número de lembretes
        ll->qtd--;
        printf("\nLembrete %d deletado", numerodolembrete);
    }
    return 0;
}

// Função que lista os lembretes
int listarLembrete(ListaDeLembretes ll){
    printf("\nLista de Lembrete\n");
    // Loop que percorre os elementos da lista e imprime eles
    for(int i = 0; i < ll.qtd; i++){
        printf("\n%d. %s: %s (Tipo de conta: %d)\n", i + 1, ll.l[i].Nome, ll.l[i].CPF, ll.l[i].Tipo de conta);
    }
    return 0;
}

// Função que imprime o menu
void printMenu(){
    printf("\n======= Menu =======\n1. Criar Lembrete\n2. Deletar Lembrete\n3. Listar Lembretes\n0. Sair\n====================\n");
}
// Função que salva a lista em um arquivo
int salvarLista(ListaDeLembretes ll, char nome[]){
    // Abre o arquivo
    FILE *f = fopen(nome, "wb");
    // Verifica se o arquivo foi aberto
    if(f==NULL){
        return 1;
    }
    // Escreve a lista no arquivo
    fwrite(&ll, sizeof(ListaDeLembretes), 1, f);
    // Fecha o arquivo
    fclose(f);
    return 0;
}
int carregarLista(ListaDeLembretes *ll, char nome[]){
    // Abre o arquivo
    FILE *f = fopen(nome, "rb");
    // Verifica se o arquivo foi aberto
    if(f==NULL){
        return 1;
    }
    // Lê o que está escrito no arquivo
    fread(ll, sizeof(ListaDeLembretes), 1, f);
    // Fecha o arquivo
    fclose(f);
    return 0;
}