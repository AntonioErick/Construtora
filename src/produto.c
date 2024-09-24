#include "../include/produto.h"

struct produto {
    char nome[50];
    float preco;
    int quantidade;
    int altura;
    struct produto *esq;
    struct produto *dir;      
};

int altura(Produto *produto) {
    if (produto == NULL)
        return 0;
    return produto->altura;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

int getBalanceamento(Produto *produto) {
    if (produto == NULL)
        return 0;
    return altura(produto->esq) - altura(produto->dir);
}

Produto* rotacaoDireita(Produto *y) {
    Produto *x = y->esq;
    Produto *T2 = x->dir;

    x->dir = y;
    y->esq = T2;

    y->altura = max(altura(y->esq), altura(y->dir)) + 1;
    x->altura = max(altura(x->esq), altura(x->dir)) + 1;

    return x;
}

Produto* rotacaoEsquerda(Produto *x) {
    Produto *y = x->dir;
    Produto *T2 = y->esq;

    y->esq = x;
    x->dir = T2;

    x->altura = max(altura(x->esq), altura(x->dir)) + 1;
    y->altura = max(altura(y->esq), y->altura) + 1;

    return y;
}

Produto* buscaMenorProduto(Produto *produto) {
    Produto *atual = produto;

    while (atual->esq != NULL)
        atual = atual->esq;

    return atual;
}

Produto *criaProduto(char *nomeProduto, float preco, int quantidade)
{
    Produto *novoProduto = (Produto *)malloc(sizeof(Produto));
    if (novoProduto == NULL)
    {
        printf("Erro ao alocar memória para o produto.\n");
        exit(1);
    }

    strcpy(novoProduto->nome, nomeProduto);
    novoProduto->preco = preco;
    novoProduto->quantidade = quantidade;
    novoProduto->altura = 1;
    novoProduto->esq = NULL;
    novoProduto->dir = NULL;

    printf("Produto %s criado com sucesso.\n", nomeProduto);

    return novoProduto;
}

Produto *heapify(Produto *raiz)
{
    Produto *max = raiz;

    if (raiz->esq != NULL && strcmp(raiz->esq->nome, max->nome) > 0)
    {
        max = raiz->esq;
    }
    if (raiz->dir != NULL && strcmp(raiz->dir->nome, max->nome) > 0)
    {
        max = raiz->dir;
    }

    if (max != raiz)
    {
        Produto temp = *raiz;
        *raiz = *max;
        *max = temp;

        heapify(max);
    }

    return raiz;
}

Produto *insereProdutoAVL(Produto *raiz, Produto *novoProduto)
{
    if (raiz == NULL)
    {
        return novoProduto;
    }

    if (strcmp(novoProduto->nome, raiz->nome) < 0)
    {
        raiz->esq = insereProdutoAVL(raiz->esq, novoProduto);
    }
    else if (strcmp(novoProduto->nome, raiz->nome) > 0)
    {
        raiz->dir = insereProdutoAVL(raiz->dir, novoProduto);
    }
    else
    {
        printf("Produto com o nome %s já existe.\n", novoProduto->nome);
        return raiz;
    }

    raiz->altura = 1 + max(altura(raiz->esq), altura(raiz->dir));

    raiz = heapify(raiz);

    int balance = getBalanceamento(raiz);

    if (balance > 1 && strcmp(novoProduto->nome, raiz->esq->nome) < 0)
    {
        return rotacaoDireita(raiz);
    }

    if (balance < -1 && strcmp(novoProduto->nome, raiz->dir->nome) > 0)
    {
        return rotacaoEsquerda(raiz);
    }

    if (balance > 1 && strcmp(novoProduto->nome, raiz->esq->nome) > 0)
    {
        raiz->esq = rotacaoEsquerda(raiz->esq);
        return rotacaoDireita(raiz);
    }

    if (balance < -1 && strcmp(novoProduto->nome, raiz->dir->nome) < 0)
    {
        raiz->dir = rotacaoDireita(raiz->dir);
        return rotacaoEsquerda(raiz);
    }

    return raiz;
}

void imprimeProdutos(Produto *raiz) {
    if (raiz == NULL) {
        printf("Nenhum produto cadastrado.\n");
        return;
    }
    imprimeProdutos(raiz->esq);

    printf("Produto: %s\n", raiz->nome);
    printf("Preço: %.2f\n", raiz->preco);
    printf("Quantidade: %d\n", raiz->quantidade);
    printf("-------------------------------\n");

    imprimeProdutos(raiz->dir);
}

Produto* buscaProdutoAVL(Produto *raiz, char *nome) {
    if (raiz == NULL || strcmp(raiz->nome, nome) == 0)
        return raiz;

    if (strcmp(nome, raiz->nome) < 0)
        return buscaProdutoAVL(raiz->esq, nome);
    else
        return buscaProdutoAVL(raiz->dir, nome); 
}

Produto* removeProdutoAVL(Produto *raiz, char *nome) {
    if (raiz == NULL) {
        printf("Produto não encontrado.\n");
        return raiz;
    }

    if (strcmp(nome, raiz->nome) < 0) {
        raiz->esq = removeProdutoAVL(raiz->esq, nome);
    } else if (strcmp(nome, raiz->nome) > 0) {
        raiz->dir = removeProdutoAVL(raiz->dir, nome);
    } else {
        if ((raiz->esq == NULL) || (raiz->dir == NULL)) {
            Produto *temp = raiz->esq ? raiz->esq : raiz->dir;
            if (temp == NULL) {
                temp = raiz;
                raiz = NULL;
            } else {
                *raiz = *temp;
            }
            free(temp);
        } else {
            Produto *temp = buscaMenorProduto(raiz->dir);
            strcpy(raiz->nome, temp->nome);
            raiz->preco = temp->preco;
            raiz->quantidade = temp->quantidade;
            raiz->dir = removeProdutoAVL(raiz->dir, temp->nome);
        }
    }

    if (raiz == NULL) {
        return raiz;
    }

    raiz->altura = 1 + max(altura(raiz->esq), altura(raiz->dir));
    int balance = getBalanceamento(raiz);

    if (balance > 1 && getBalanceamento(raiz->esq) >= 0) {
        return rotacaoDireita(raiz);
    }

    if (balance > 1 && getBalanceamento(raiz->esq) < 0) {
        raiz->esq = rotacaoEsquerda(raiz->esq);
        return rotacaoDireita(raiz);
    }

    if (balance < -1 && getBalanceamento(raiz->dir) <= 0) {
        return rotacaoEsquerda(raiz);
    }

    if (balance < -1 && getBalanceamento(raiz->dir) > 0) {
        raiz->dir = rotacaoDireita(raiz->dir);
        return rotacaoEsquerda(raiz);
    }

    return raiz;
}

void liberaProdutosAVL(Produto *raiz) {
    if (raiz == NULL)
        return;

    liberaProdutosAVL(raiz->esq);
    liberaProdutosAVL(raiz->dir);

    free(raiz);
}
