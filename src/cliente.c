#include "../include/cliente.h"

struct cliente {
    int id;
    char nome[50];
    char endereco[100];
    char telefone[15];
    Produto *produtos;
};

Cliente* criaCliente() {
    Cliente *novoCliente = (Cliente *) malloc(sizeof(Cliente));
    if (novoCliente == NULL) {
        printf("Erro ao alocar memoria para o cliente.\n");
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

    printf("Cliente %s criado com sucesso. ID: %d\n", novoCliente->nome, novoCliente->id);

    return novoCliente;
}

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

        // Calcula o preço total de todos os produtos do cliente
        float precoTotal = calculaPrecoTotal(cliente->produtos);
        printf("Preco total a pagar: R$ %.2f\n", precoTotal);
    }
}
