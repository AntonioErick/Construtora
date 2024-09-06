#include "../include/hash.h"
#include "../include/cliente.h"

#define TAMANHO_TABELA 100  

typedef struct tabelaHash {
    Cliente **clientes;  
    int tamanho;         
} TabelaHash;

int funcaoHash(int id, int tamanho) {
    return id % tamanho;
}

TabelaHash* criaTabelaHash(int tamanho) {
    TabelaHash *tabela = (TabelaHash *) malloc(sizeof(TabelaHash));
    if (tabela == NULL) {
        printf("Erro ao alocar memória para a tabela hash.\n");
        exit(1);
    }

    tabela->clientes = (Cliente **) malloc(tamanho * sizeof(Cliente *));
    if (tabela->clientes == NULL) {
        printf("Erro ao alocar memória para os clientes.\n");
        exit(1);
    }

    tabela->tamanho = tamanho;

    for (int i = 0; i < tamanho; i++) {
        tabela->clientes[i] = NULL;
    }

    return tabela;
}

void insereClienteHash(TabelaHash *tabela, Cliente *cliente) {
    int indice = funcaoHash(cliente->id, tabela->tamanho);

    while (tabela->clientes[indice] != NULL) {

        if (tabela->clientes[indice]->id == cliente->id) {
            printf("Cliente com ID %d já existe, substituindo.\n", cliente->id);
            break;
        }
        indice = (indice + 1) % tabela->tamanho;
    }

    tabela->clientes[indice] = cliente;
    printf("Cliente %s inserido na posição %d da tabela hash.\n", cliente->nome, indice);
}

Cliente* buscaClienteHash(TabelaHash *tabela, int id){
    int indice = funcaoHash(id, tabela->tamanho);

    while (tabela->clientes[indice] != NULL) {
        if (tabela->clientes[indice]->id == id) {
            return tabela->clientes[indice];
        }
        indice = (indice + 1) % tabela->tamanho;
    }

    return NULL;
}

void imprimeClienteBuscado(TabelaHash *tabela, int id) {
    Cliente *cliente = buscaClienteHash(tabela, id);
    if (cliente == NULL) {
        printf("Cliente com ID %d não encontrado.\n", id);
    } else {
        imprimeCliente(cliente);
    }
}

