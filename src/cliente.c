#include "../include/cliente.h"

struct cliente {
    int id;
    char nome[50];
    char endereco[100];
    char telefone[15];
    Produto *carrinho;
    Cliente *prox;
};

int listaVazia(Cliente *lista) {
    return (lista == NULL);
}

Cliente preencheCliente() {
    Cliente c;
    
    printf("Digite o nome do cliente: ");
    scanf(" %[^\n]", c.nome);
    printf("Digite o endereco do cliente: ");
    scanf(" %[^\n]", c.endereco);
    printf("Digite o telefone do cliente: ");
    scanf(" %[^\n]", c.telefone);
    c.id = gerarIdAleatorio();
    c.carrinho = NULL;
    c.prox = NULL;
    return c;
}

Cliente *insereCliente(Cliente *lista, Cliente c){
    Cliente *novo = (Cliente *) malloc(sizeof(Cliente));
    if(novo == NULL){
        printf("Erro ao alocar memoria\n");
        exit(1);
    }
    novo->id = c.id;
    strcpy(novo->nome, c.nome);
    strcpy(novo->endereco, c.endereco);
    strcpy(novo->telefone, c.telefone);
    novo->prox = NULL;

    if(lista == NULL || strcmp(lista->nome, novo->nome) > 0){
        novo->prox = lista;
        printf("Cliente %s cadastrado com sucesso\n", novo->nome);
        return novo;
    }

    Cliente *ant = NULL;
    Cliente *atual = lista;

    while(atual != NULL && strcmp(atual->nome, novo->nome) < 0){
        ant = atual;
        atual = atual->prox;
    }

    ant->prox = novo;
    novo->prox = atual;
    printf("Cliente %s cadastrado com sucesso\n", novo->nome);

    return lista;
}

void imprimeClientes(Cliente *lista){
    if(listaVazia(lista)){
        printf("Lista vazia\n");
        return;
    }

    Cliente *atual = lista;
    while(atual != NULL){
        printf("ID: %d\nNome: %s\nEndereco: %s\nTelefone: %s\n", atual->id, atual->nome, atual->endereco, atual->telefone);
        //colocar o imprime produtos quando tiver feita
        atual = atual->prox;
    }
}