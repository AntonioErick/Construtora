#ifndef PACIENTE_H
#define PACIENTE_H

#include "../src/sistema.c"

typedef struct produto Produto;

/**
 * @brief Retorna a altura de um nó na árvore AVL de produtos.
 *
 * @param produto Ponteiro para o produto (nó) cuja altura será calculada.
 * @return A altura do nó.
 */
int altura(Produto *produto);

/**
 * @brief Retorna o maior valor entre dois inteiros.
 *
 * @param a Um valor inteiro.
 * @param b Outro valor inteiro.
 * @return O maior valor entre os dois inteiros fornecidos.
 */
int max(int a, int b);

/**
 * @brief Calcula o balanceamento de um nó na árvore AVL.
 *
 * @param produto Ponteiro para o produto (nó) cuja diferença de altura será calculada.
 * @return O fator de balanceamento do nó.
 */
int getBalanceamento(Produto *produto);

/**
 * @brief Realiza a rotação para a direita em um nó da árvore AVL.
 *
 * @param y O nó desbalanceado para o qual a rotação à direita será realizada.
 * @return O novo nó raiz após a rotação.
 */
Produto *rotacaoDireita(Produto *y);

/**
 * @brief Realiza a rotação para a esquerda em um nó da árvore AVL.
 *
 * @param x O nó desbalanceado para o qual a rotação à esquerda será realizada.
 * @return O novo nó raiz após a rotação.
 */
Produto *rotacaoEsquerda(Produto *x);

/**
 * @brief Busca o produto com o menor valor na subárvore.
 *
 * @param produto Ponteiro para a raiz da subárvore.
 * @return Ponteiro para o produto com o menor valor.
 */
Produto *buscaMenorProduto(Produto *produto);

/**
 * @brief Cria um novo produto com base no código do produto e quantidade.
 *
 * @param codigoProduto O código do produto (de uma lista predefinida).
 * @param quantidade A quantidade do produto.
 * @return Ponteiro para o novo produto criado.
 */
Produto *criaProduto(int codigoProduto, int quantidade);

/**
 * @brief Insere um produto na árvore AVL.
 *
 * @param raiz Ponteiro para a raiz da árvore AVL.
 * @param novoProduto O produto a ser inserido na árvore.
 * @return Ponteiro para a nova raiz da árvore AVL após a inserção.
 */
Produto *insereProdutoAVL(Produto *raiz, Produto *novoProduto);

/**
 * @brief Calcula o preço total de todos os produtos armazenados na árvore AVL.
 *
 * @param raiz Ponteiro para a raiz da árvore AVL.
 * @return O preço total de todos os produtos.
 */
float calculaPrecoTotal(Produto *raiz);

/**
 * @brief Imprime as informações de todos os produtos armazenados na árvore AVL.
 *
 * @param raiz Ponteiro para a raiz da árvore AVL.
 */
void imprimeProdutos(Produto *raiz);

/**
 * @brief Busca um produto específico na árvore AVL pelo nome.
 *
 * @param raiz Ponteiro para a raiz da árvore AVL.
 * @param nome O nome do produto a ser buscado.
 * @return Ponteiro para o produto encontrado ou NULL se não for encontrado.
 */
Produto *buscaProdutoAVL(Produto *raiz, char *nome);

/**
 * @brief Remove um produto da árvore AVL com base no nome.
 *
 * @param raiz Ponteiro para a raiz da árvore AVL.
 * @param nome O nome do produto a ser removido.
 * @return Ponteiro para a nova raiz da árvore AVL após a remoção.
 */
Produto *removeProdutoAVL(Produto *raiz, char *nome);

/**
 * @brief Libera a memória de todos os produtos armazenados na árvore AVL.
 *
 * @param raiz Ponteiro para a raiz da árvore AVL a ser liberada.
 */
void liberaProdutosAVL(Produto *raiz);

#endif // PACIENTE_H