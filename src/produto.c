#include "../include/produto.h"

struct produto {
    char nome[50];
    char descricao[100];
    float preco;
    int quantidade;
    Produto *prox;
};

