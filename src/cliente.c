#include "../include/cliente.h"
#include "produto.c" // Include the header file for Produto

struct cliente
{
    int id;
    char nome[50];
    char endereco[100];
    char telefone[15];
    Produto *produtos;
    float valorTotal; // Valor total a pagar pelos produtos
};

typedef struct heap
{
    Cliente **clientes;
    int tamanho;
    int capacidade;
} Heap;

Cliente *criaCliente()
{
    Cliente *novoCliente = (Cliente *)malloc(sizeof(Cliente));
    if (novoCliente == NULL)
    {
        printf("Erro ao alocar memória para o cliente.\n");
        exit(1);
    }

    printf("Digite o nome do cliente: ");
    scanf(" %[^\n]", novoCliente->nome);

    printf("Digite o endereco do cliente: ");
    scanf(" %[^\n]", novoCliente->endereco);

    printf("Digite o telefone do cliente: ");
    scanf(" %[^\n]", novoCliente->telefone);

    novoCliente->id = gerarIdAleatorio();
    novoCliente->produtos = NULL;
    novoCliente->valorTotal = 0.0; // Inicializa o valor total

    printf("Cliente %s criado com sucesso. ID: %d\n", novoCliente->nome, novoCliente->id);

    return novoCliente;
}

void atualizarValorTotalCliente(Cliente *cliente)
{
    if (cliente != NULL)
    {
        cliente->valorTotal = calculaPrecoTotal(cliente->produtos);
    }
}

// Funções de impressão dos clientes
void imprimeCliente(Cliente *cliente)
{
    if (cliente == NULL)
    {
        printf("Cliente invalido ou nao encontrado.\n");
        return;
    }

    printf("=== Detalhes do Cliente ===\n");
    printf("ID: %d\n", cliente->id);
    printf("Nome: %s\n", cliente->nome);
    printf("Endereco: %s\n", cliente->endereco);
    printf("Telefone: %s\n", cliente->telefone);
    printf("===========================\n");

    if (cliente->produtos == NULL)
    {
        printf("Nenhum produto cadastrado para este cliente.\n");
    }
    else
    {
        printf("=== Produtos Associados ===\n");
        imprimeProdutos(cliente->produtos);
        printf("===========================\n");

        float precoTotal = calculaPrecoTotal(cliente->produtos);
        printf("Preco total a pagar: R$ %.2f\n", precoTotal);
    }
}

// Funções da Heap (lista de prioridade)

Heap *criaHeap(int capacidade)
{
    Heap *heap = (Heap *)malloc(sizeof(Heap));
    heap->clientes = (Cliente **)malloc(capacidade * sizeof(Cliente *));
    heap->tamanho = 0;
    heap->capacidade = capacidade;
    return heap;
}

void trocaClientes(Cliente **a, Cliente **b)
{
    Cliente *temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(Heap *heap, int i)
{
    int maior = i;
    int esq = 2 * i + 1;
    int dir = 2 * i + 2;

    if (esq < heap->tamanho && heap->clientes[esq]->valorTotal > heap->clientes[maior]->valorTotal)
        maior = esq;

    if (dir < heap->tamanho && heap->clientes[dir]->valorTotal > heap->clientes[maior]->valorTotal)
        maior = dir;

    if (maior != i)
    {
        trocaClientes(&heap->clientes[i], &heap->clientes[maior]);
        heapify(heap, maior);
    }
}

void insereClienteHeap(Heap *heap, Cliente *cliente)
{
    if (heap->tamanho == heap->capacidade)
    {
        printf("Heap cheia, não é possível inserir mais clientes.\n");
        return;
    }

    heap->clientes[heap->tamanho] = cliente;
    int i = heap->tamanho;
    heap->tamanho++;

    while (i != 0 && heap->clientes[(i - 1) / 2]->valorTotal < heap->clientes[i]->valorTotal)
    {
        trocaClientes(&heap->clientes[i], &heap->clientes[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

Cliente *removeClienteHeap(Heap *heap)
{
    if (heap->tamanho <= 0)
    {
        return NULL;
    }

    if (heap->tamanho == 1)
    {
        heap->tamanho--;
        return heap->clientes[0];
    }

    Cliente *raiz = heap->clientes[0];
    heap->clientes[0] = heap->clientes[heap->tamanho - 1];
    heap->tamanho--;
    heapify(heap, 0);

    return raiz;
}

// Função para realizar a entrega dos produtos
void entregaProdutos(Heap *heap)
{
    if (heap->tamanho == 0)
    {
        printf("Nenhum cliente na fila de entregas.\n");
        return;
    }

    printf("=== Fila de Entregas ===\n");
    for (int i = 0; i < heap->tamanho; i++)
    {
        printf("%d. Cliente: %s\n", i + 1, heap->clientes[i]->nome);
    }
    printf("=======================\n");

    // Processa a entrega para o cliente com maior prioridade
    Cliente *cliente = removeClienteHeap(heap);

    if (cliente == NULL)
    {
        printf("Falha ao realizar a entrega.\n");
        return;
    }

    // Exibe informações do cliente e realiza a "entrega"
    printf("Realizando a entrega para o cliente: %s\n", cliente->nome);
    printf("Endereço: %s\n", cliente->endereco);

    // Simula a entrega removendo o cliente da heap (produtos já foram vendidos)
    printf("Entrega realizada com sucesso para %s.\n", cliente->nome);
}
