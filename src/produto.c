#include "../include/produto.h"

struct produto {
    char nome[50];
    float preco;
    int quantidade;
    int altura;
    struct produto *esq;
    struct produto *dir;      
};

/*void imprimeProdutos(Produto *produto) {
    if (produto == NULL) {
        return;
    }

    // Percorre a subárvore da esquerda
    imprimeProdutos(produto->esq);

    // Imprime os detalhes do produto atual
    printf("Produto: %s\n", produto->nome);
    printf("Preço: %.2f\n", produto->preco);
    printf("Quantidade: %d\n", produto->quantidade);
    printf("-------------------------------\n");

    // Percorre a subárvore da direita
    imprimeProdutos(produto->dir);
}*/