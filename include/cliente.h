#ifndef CLIENTE_H
#define CLIENTE_H

#include "produto.h"

/**
 * @brief Estrutura que representa um cliente.
 */
typedef struct cliente Cliente;

/**
 * @brief Estrutura que representa uma heap de clientes, usada para priorizar as entregas.
 */
typedef struct heap Heap;

/**
 * @brief Cria um novo cliente, preenchendo seus dados básicos.
 *
 * @return Ponteiro para o cliente criado.
 */
Cliente *criaCliente();

/**
 * @brief Imprime as informações detalhadas de um cliente, incluindo seus produtos.
 *
 * @param cliente Ponteiro para o cliente cujas informações serão impressas.
 */
void imprimeCliente(Cliente *cliente);

/**
 * @brief Calcula o preço total de todos os produtos de um cliente armazenados na árvore AVL.
 *
 * @param raiz Ponteiro para a raiz da árvore AVL que armazena os produtos do cliente.
 * @return O preço total dos produtos do cliente.
 */
float calculaPrecoTotal(Produto *raiz);

/**
 * @brief Atualiza o valor total a pagar pelos produtos do cliente.
 *
 * @param cliente Ponteiro para o cliente cujo valor total será atualizado.
 */
void atualizarValorTotalCliente(Cliente *cliente);

/**
 * @brief Cria uma heap para armazenar clientes, utilizada para organizar a prioridade de entregas.
 *
 * @param capacidade A capacidade máxima da heap.
 * @return Ponteiro para a heap criada.
 */
Heap *criaHeap(int capacidade);

/**
 * @brief Insere um cliente na heap com base no valor total a pagar.
 *
 * @param heap Ponteiro para a heap onde o cliente será inserido.
 * @param cliente Ponteiro para o cliente a ser inserido.
 */
void insereClienteHeap(Heap *heap, Cliente *cliente);

/**
 * @brief Remove o cliente com o maior valor total da heap (prioridade máxima).
 *
 * @param heap Ponteiro para a heap de onde o cliente será removido.
 * @return Ponteiro para o cliente removido.
 */
Cliente *removeClienteHeap(Heap *heap);

/**
 * @brief Reorganiza a heap para manter a propriedade de max-heap após uma inserção ou remoção.
 *
 * @param heap Ponteiro para a heap.
 * @param i O índice do nó a ser reorganizado.
 */
void heapify(Heap *heap, int i);

/**
 * @brief Troca dois ponteiros de clientes na heap.
 *
 * @param a Ponteiro para o primeiro cliente.
 * @param b Ponteiro para o segundo cliente.
 */
void trocaClientes(Cliente **a, Cliente **b);

/**
 * @brief Realiza a entrega dos produtos do cliente com maior prioridade (valor total mais alto).
 *
 * @param heap Ponteiro para a heap onde estão armazenados os clientes para entrega.
 */
void entregaProdutos(Heap *heap);

#endif