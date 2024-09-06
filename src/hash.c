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
