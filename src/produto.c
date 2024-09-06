#include "../include/produto.h"

struct produto {
    char nome[50];
    float preco;
    int quantidade;
    int altura;
    struct produto *esq;
    struct produto *dir;      
};