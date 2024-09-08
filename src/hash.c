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
        printf("Erro ao alocar memória para a tabela hash.\n");
        exit(1);
    }

    tabela->clientes = (Cliente **) malloc(tamanho * sizeof(Cliente *));
    if (tabela->clientes == NULL) {
        printf("Erro ao alocar memória para os clientes.\n");
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
            printf("Cliente com ID %d já existe, substituindo.\n", cliente->id);
            break;
        }
        indice = (indice + 1) % tabela->tamanho;
    }

    tabela->clientes[indice] = cliente;
    printf("Cliente %s inserido na posição %d da tabela hash.\n", cliente->nome, indice);
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
        printf("Cliente com ID %d não encontrado.\n", id);
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

    printf("Cliente com ID %d não encontrado.\n", id);
    return 0;
}

void editaClienteHash(TabelaHash *tabela, int id) {
    int opc;
    char novoNome[50];
    char novoEndereco[100];
    Cliente *cliente = buscaClienteHash(tabela, id);

    if (cliente == NULL) {
        printf("Cliente com ID %d não encontrado.\n", id);
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
                printf("Endereço atual: %s\n", cliente->endereco);
                printf("Digite o novo endereço: ");
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
                printf("Opção inválida.\n");
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

void cadastrarProdutoParaCliente(TabelaHash *tabela) {
    int idCliente;
    char nomeProduto[50];
    float preco;
    int quantidade;
    
    printf("Digite o ID do cliente: ");
    scanf("%d", &idCliente);

    Cliente *cliente = buscaClienteHash(tabela, idCliente);
    if (cliente == NULL) {
        printf("Cliente não encontrado. Deseja cadastrar um novo cliente? (1 - Sim / 0 - Não): ");
        int opcao;
        scanf("%d", &opcao);
        if (opcao == 1) {
            cliente = criaCliente();
            insereClienteHash(tabela, cliente);
        } else {
            printf("Operação cancelada.\n");
            return;
        }
    }

    printf("Digite o nome do produto: ");
    scanf(" %[^\n]", nomeProduto);
    printf("Digite o preço do produto: ");
    scanf("%f", &preco);
    printf("Digite a quantidade do produto: ");
    scanf("%d", &quantidade);

    Produto *novoProduto = criaProduto(nomeProduto, preco, quantidade);
    cliente->produtos = insereProdutoAVL(cliente->produtos, novoProduto);
    printf("Produto %s cadastrado com sucesso para o cliente de ID %d.\n", nomeProduto, idCliente);
}

void removerProdutoDoCliente(TabelaHash *tabela) {
    int idCliente;
    char nomeProduto[50];

    // Solicita o ID do cliente
    printf("Digite o ID do cliente: ");
    scanf("%d", &idCliente);

    // Busca o cliente na tabela hash pelo ID
    Cliente *cliente = buscaClienteHash(tabela, idCliente);
    if (cliente == NULL) {
        printf("Cliente com ID %d não encontrado.\n", idCliente);
        return;
    }

    // Verifica se o cliente tem produtos cadastrados
    if (cliente->produtos == NULL) {
        printf("O cliente de ID %d não tem produtos cadastrados.\n", idCliente);
        return;
    }

    // Solicita o nome do produto a ser removido
    printf("Digite o nome do produto a ser removido: ");
    scanf(" %[^\n]", nomeProduto);

    // Remove o produto da árvore AVL do cliente
    cliente->produtos = removeProdutoAVL(cliente->produtos, nomeProduto);

    printf("Produto %s removido com sucesso do cliente de ID %d.\n", nomeProduto, idCliente);
}

void buscarProdutoDoCliente(TabelaHash *tabela) {
    int idCliente;
    char nomeProduto[50];

    // Solicita o ID do cliente
    printf("Digite o ID do cliente: ");
    scanf("%d", &idCliente);

    // Busca o cliente na tabela hash pelo ID
    Cliente *cliente = buscaClienteHash(tabela, idCliente);
    if (cliente == NULL) {
        printf("Cliente com ID %d não encontrado.\n", idCliente);
        return;
    }

    // Verifica se o cliente tem produtos cadastrados
    if (cliente->produtos == NULL) {
        printf("O cliente de ID %d não tem produtos cadastrados.\n", idCliente);
        return;
    }

    // Solicita o nome do produto a ser buscado
    printf("Digite o nome do produto que deseja buscar: ");
    scanf(" %[^\n]", nomeProduto);

    // Busca o produto na árvore AVL do cliente
    Produto *produto = buscaProdutoAVL(cliente->produtos, nomeProduto);

    if (produto == NULL) {
        printf("Produto %s não encontrado para o cliente de ID %d.\n", nomeProduto, idCliente);
    } else {
        // Exibe as informações do produto
        printf("Produto encontrado:\n");
        printf("Nome: %s\n", produto->nome);
        printf("Preço: %.2f\n", produto->preco);
        printf("Quantidade: %d\n", produto->quantidade);
    }
}

void liberaTabelaHash(TabelaHash *tabela) {
    for (int i = 0; i < tabela->tamanho; i++) {
        if (tabela->clientes[i] != NULL) {
            // Libera os produtos do cliente (árvore AVL de produtos)
            liberaProdutosAVL(tabela->clientes[i]->produtos);

            // Libera o cliente
            free(tabela->clientes[i]);
        }
    }

    // Libera a tabela hash
    free(tabela->clientes);
    free(tabela);
}
