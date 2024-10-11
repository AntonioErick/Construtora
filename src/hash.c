#include "../include/hash.h"
#include "../include/cliente.h"

#define TAMANHO_TABELA 100  

typedef struct tabelaHash {
    Cliente **clientes;  
    int tamanho;         
} TabelaHash;

int funcaoHash(int id, int tamanho) {
    return id % tamanho;
}

TabelaHash* criaTabelaHash(int tamanho) {
    TabelaHash *tabela = (TabelaHash *) malloc(sizeof(TabelaHash));
    if (tabela == NULL) {
        printf("Erro ao alocar memoria para a tabela hash.\n");
        exit(1);
    }

    tabela->clientes = (Cliente **) malloc(tamanho * sizeof(Cliente *));
    if (tabela->clientes == NULL) {
        printf("Erro ao alocar memoria para os clientes.\n");
        exit(1);
    }

    tabela->tamanho = tamanho;

    for (int i = 0; i < tamanho; i++) {
        tabela->clientes[i] = NULL;
    }

    return tabela;
}

void insereClienteHash(TabelaHash *tabela, Cliente *cliente) {
    int indice = funcaoHash(cliente->id, tabela->tamanho);

    while (tabela->clientes[indice] != NULL) {

        if (tabela->clientes[indice]->id == cliente->id) {
            printf("Cliente com ID %d ja existe, substituindo.\n", cliente->id);
            break;
        }
        indice = (indice + 1) % tabela->tamanho;
    }

    tabela->clientes[indice] = cliente;
    printf("Cliente %s inserido na posicao %d da tabela hash.\n", cliente->nome, indice);
}

Cliente* buscaClienteHash(TabelaHash *tabela, int id){
    int indice = funcaoHash(id, tabela->tamanho);

    while (tabela->clientes[indice] != NULL) {
        if (tabela->clientes[indice]->id == id) {
            return tabela->clientes[indice];
        }
        indice = (indice + 1) % tabela->tamanho;
    }

    return NULL;
}

void imprimeClienteBuscado(TabelaHash *tabela, int id) {
    Cliente *cliente = buscaClienteHash(tabela, id);
    if (cliente == NULL) {
        printf("Cliente com ID %d nao encontrado.\n", id);
    } else {
        imprimeCliente(cliente);
    }
}

int removeClienteHash(TabelaHash *tabela, int id) {
    int indice = funcaoHash(id, tabela->tamanho);

    while (tabela->clientes[indice] != NULL) {
        if (tabela->clientes[indice]->id == id) {
            free(tabela->clientes[indice]);
            tabela->clientes[indice] = NULL;
            printf("Cliente com ID %d removido com sucesso.\n", id);
            return 1;
        }
        indice = (indice + 1) % tabela->tamanho;
    }

    printf("Cliente com ID %d nao encontrado.\n", id);
    return 0;
}

void editaClienteHash(TabelaHash *tabela, int id) {
    int opc;
    char novoNome[50];
    char novoEndereco[100];
    Cliente *cliente = buscaClienteHash(tabela, id);

    if (cliente == NULL) {
        printf("Cliente com ID %d nao encontrado.\n", id);
        return;
    }

    printf("=== Editando Cliente com ID %d ===\n", cliente->id);

    do{
        menuEditCliente();
        scanf("%d", &opc);

        switch(opc){
            case 0:
                break;
            case 1:
                limpatela();
                printf("Nome atual: %s\n", cliente->nome);
                printf("Digite o novo nome: ");
                scanf(" %[^\n]", novoNome);
                if (strlen(novoNome) > 0) {
                    strcpy(cliente->nome, novoNome);
                }
                break;
            case 2:
                printf("Endereco atual: %s\n", cliente->endereco);
                printf("Digite o novo endereco: ");
                scanf(" %[^\n]", novoEndereco);
                if (strlen(novoEndereco) > 0) {
                    strcpy(cliente->endereco, novoEndereco);
                }
                break;
            case 3:
                printf("Telefone atual: %s\n", cliente->telefone);
                printf("Digite o novo telefone: ");
                char novoTelefone[15];
                scanf(" %[^\n]", novoTelefone);
                if (strlen(novoTelefone) > 0) {
                    strcpy(cliente->telefone, novoTelefone);
                }
                break;
            default:
                printf("Opcao invalida.\n");
                break;
        }
    }while(opc != 0);

    printf("Cliente com ID %d editado com sucesso.\n", id);
}

void imprimeTabelaHash(TabelaHash *tabela) {
    printf("=== Clientes Cadastrados ===\n");
    
    int encontrados = 0;
    
    for (int i = 0; i < tabela->tamanho; i++) {
        if (tabela->clientes[i] != NULL) {
            imprimeCliente(tabela->clientes[i]);
            encontrados++;
        }
    }

    if (encontrados == 0) {
        printf("Nenhum cliente cadastrado.\n");
    }
    printf("===========================\n");
}

void cadastrarProdutoParaCliente(TabelaHash *tabela)
{
    int idCliente, codigoProduto, quantidade;

    printf("Digite o ID do cliente: ");
    scanf("%d", &idCliente);

    Cliente *cliente = buscaClienteHash(tabela, idCliente);
    if (cliente == NULL)
    {
        printf("Cliente nao encontrado. Deseja cadastrar um novo cliente? (1 - Sim / 0 - Nao): ");
        int opcao;
        scanf("%d", &opcao);
        if (opcao == 1)
        {
            cliente = criaCliente();
            insereClienteHash(tabela, cliente);
        }
        else
        {
            printf("Operacao cancelada.\n");
            return;
        }
    }

    listaProdutos();
    printf("Escolha o numero do produto: ");
    scanf("%d", &codigoProduto);

    printf("Digite a quantidade do produto: ");
    scanf("%d", &quantidade);

    Produto *novoProduto = criaProduto(codigoProduto, quantidade);
    if (novoProduto != NULL)
    {
        cliente->produtos = insereProdutoAVL(cliente->produtos, novoProduto);
        printf("Produto cadastrado com sucesso para o cliente de ID %d.\n", idCliente);
    }
    else
    {
        printf("Falha ao cadastrar o produto.\n");
    }
}

void removerProdutoDoCliente(TabelaHash *tabela) {
    int idCliente;
    char nomeProduto[50];

    printf("Digite o ID do cliente: ");
    scanf("%d", &idCliente);

    Cliente *cliente = buscaClienteHash(tabela, idCliente);
    if (cliente == NULL) {
        printf("Cliente com ID %d nao encontrado.\n", idCliente);
        return;
    }

    if (cliente->produtos == NULL) {
        printf("O cliente de ID %d nao tem produtos cadastrados.\n", idCliente);
        return;
    }

    printf("Digite o nome do produto a ser removido: ");
    scanf(" %[^\n]", nomeProduto);

    cliente->produtos = removeProdutoAVL(cliente->produtos, nomeProduto);

    printf("Produto %s removido com sucesso do cliente de ID %d.\n", nomeProduto, idCliente);
}

void venderProdutos(TabelaHash *tabela, Heap *heap)
{
    int idCliente;

    printf("Digite o ID do cliente: ");
    scanf("%d", &idCliente);

    Cliente *cliente = buscaClienteHash(tabela, idCliente);
    if (cliente == NULL)
    {
        printf("Cliente com ID %d não encontrado.\n", idCliente);
        return;
    }

    if (cliente->produtos == NULL)
    {
        printf("O cliente não tem produtos cadastrados.\n");
        return;
    }

    liberaProdutosAVL(cliente->produtos);
    cliente->produtos = NULL;
    cliente->valorTotal = 0;

    printf("Todos os produtos do cliente de ID %d foram vendidos com sucesso.\n", idCliente);

    // Adiciona o cliente na heap com prioridade para entrega
    insereClienteHeap(heap, cliente);
    printf("Cliente %s adicionado à fila de entregas.\n", cliente->nome);
}

void buscarProdutoDoCliente(TabelaHash *tabela) {
    int idCliente;
    char nomeProduto[50];

    printf("Digite o ID do cliente: ");
    scanf("%d", &idCliente);

    Cliente *cliente = buscaClienteHash(tabela, idCliente);
    if (cliente == NULL) {
        printf("Cliente com ID %d nao encontrado.\n", idCliente);
        return;
    }

    if (cliente->produtos == NULL) {
        printf("O cliente de ID %d nao tem produtos cadastrados.\n", idCliente);
        return;
    }

    printf("Digite o nome do produto que deseja buscar: ");
    scanf(" %[^\n]", nomeProduto);

    Produto *produto = buscaProdutoAVL(cliente->produtos, nomeProduto);

    if (produto == NULL) {
        printf("Produto %s nao encontrado para o cliente de ID %d.\n", nomeProduto, idCliente);
    } else {
        printf("Produto encontrado:\n");
        printf("Nome: %s\n", produto->nome);
        printf("Preco: %.2f\n", produto->preco);
        printf("Quantidade: %d\n", produto->quantidade);
    }
}

void liberaTabelaHash(TabelaHash *tabela) {
    for (int i = 0; i < tabela->tamanho; i++) {
        if (tabela->clientes[i] != NULL) {
            liberaProdutosAVL(tabela->clientes[i]->produtos);

            free(tabela->clientes[i]);
        }
    }

    free(tabela->clientes);
    free(tabela);
}
