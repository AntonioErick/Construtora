#ifndef PACIENTE_H
#define PACIENTE_H

#include "../src/sistema.c"

typedef struct produto Produto;

int altura(Produto *produto);
int max(int a, int b);
int getBalanceamento(Produto *produto);
Produto* rotacaoDireita(Produto *y);
Produto* rotacaoEsquerda(Produto *x);
Produto* buscaMenorProduto(Produto *produto);
Produto *criaProduto(int codigoProduto, int quantidade);
Produto *insereProdutoAVL(Produto *raiz, Produto *novoProduto);
float calculaPrecoTotal(Produto *raiz);
void imprimeProdutos(Produto *raiz);
Produto* buscaProdutoAVL(Produto *raiz, char *nome);
Produto* removeProdutoAVL(Produto *raiz, char *nome);
void liberaProdutosAVL(Produto *raiz);

#endif // PACIENTE_H