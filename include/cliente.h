#ifndef CLIENTE_H
#define CLIENTE_H

#include "produto.h"

typedef struct cliente Cliente;
typedef struct heap Heap;

    // Funções de cliente
    Cliente *
    criaCliente();
void imprimeCliente(Cliente *cliente);
float calculaPrecoTotal(Produto *raiz);
void atualizarValorTotalCliente(Cliente *cliente);

// Funções da heap
Heap *criaHeap(int capacidade);
void insereClienteHeap(Heap *heap, Cliente *cliente);
Cliente *removeClienteHeap(Heap *heap);
void heapify(Heap *heap, int i);
void trocaClientes(Cliente **a, Cliente **b);

// Função para realizar entrega
void entregaProdutos(Heap *heap);

#endif