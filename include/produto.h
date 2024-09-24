#ifndef PACIENTE_H
#define PACIENTE_H

#include "../src/sistema.c"

typedef struct produto Produto;

/**
 * @brief Retorna a altura de um nó da árvore AVL.
 * 
 * @param produto Ponteiro para o produto (nó) cuja altura será verificada.
 * @return A altura do nó ou 0 se for NULL.
 */
int altura(Produto *produto);

/**
 * @brief Retorna o valor máximo entre dois inteiros.
 * 
 * @param a Primeiro inteiro.
 * @param b Segundo inteiro.
 * @return O maior valor entre `a` e `b`.
 */
int max(int a, int b);

/**
 * @brief Retorna o fator de balanceamento de um nó da árvore AVL.
 * 
 * @param produto Ponteiro para o produto (nó) cuja diferença de altura será calculada.
 * @return A diferença entre as alturas da subárvore esquerda e direita.
 */
int getBalanceamento(Produto *produto);

/**
 * @brief Executa a rotação à direita em um nó da árvore AVL.
 * 
 * @param y Ponteiro para o nó que será rotacionado à direita.
 * @return O novo nó raiz após a rotação.
 */
Produto* rotacaoDireita(Produto *y);

/**
 * @brief Executa a rotação à esquerda em um nó da árvore AVL.
 * 
 * @param x Ponteiro para o nó que será rotacionado à esquerda.
 * @return O novo nó raiz após a rotação.
 */
Produto* rotacaoEsquerda(Produto *x);

/**
 * @brief Busca o nó com o menor valor (ordem alfabética) em uma árvore AVL.
 * 
 * @param produto Ponteiro para a raiz da árvore onde a busca será feita.
 * @return O nó com o menor valor (nome) na árvore.
 */
Produto* buscaMenorProduto(Produto *produto);

/**
 * @brief Cria um novo produto.
 * 
 * @param nomeProduto Nome do produto.
 * @param preco Preço do produto.
 * @param quantidade Quantidade em estoque.
 * @return Ponteiro para o novo produto criado.
 */
Produto* criaProduto(char *nomeProduto, float preco, int quantidade);

/**
 * @brief Mantém a propriedade de heap máxima em um nó da árvore AVL.
 * 
 * @param raiz Ponteiro para a raiz da subárvore a ser heapificada.
 * @return Ponteiro para o novo nó raiz após a heapificação.
 */
Produto *heapify(Produto *raiz);

/**
 * @brief Insere um novo produto na árvore AVL com a propriedade de heap máxima.
 * 
 * @param raiz Ponteiro para a raiz da árvore onde o produto será inserido.
 * @param novoProduto Ponteiro para o novo produto a ser inserido.
 * @return Ponteiro para a nova raiz da árvore AVL após a inserção.
 */
Produto* insereProdutoAVL(Produto *raiz, Produto *novoProduto);

/**
 * @brief Imprime os produtos da árvore AVL em ordem alfabética.
 * 
 * @param raiz Ponteiro para a raiz da árvore AVL que será impressa.
 */
void imprimeProdutos(Produto *raiz);

/**
 * @brief Busca um produto específico na árvore AVL.
 * 
 * @param raiz Ponteiro para a raiz da árvore onde a busca será realizada.
 * @param nome Nome do produto a ser buscado.
 * @return Ponteiro para o produto encontrado ou NULL se não existir.
 */
Produto* buscaProdutoAVL(Produto *raiz, char *nome);

/**
 * @brief Remove um produto da árvore AVL.
 * 
 * @param raiz Ponteiro para a raiz da árvore de onde o produto será removido.
 * @param nome Nome do produto a ser removido.
 * @return Ponteiro para a nova raiz da árvore AVL após a remoção.
 */
Produto* removeProdutoAVL(Produto *raiz, char *nome);

/**
 * @brief Libera a memória alocada para a árvore AVL de produtos.
 * 
 * @param raiz Ponteiro para a raiz da árvore AVL que será liberada.
 */
void liberaProdutosAVL(Produto *raiz);

#endif // PACIENTE_H
