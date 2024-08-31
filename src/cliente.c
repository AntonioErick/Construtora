#include "../include/cliente.h"

struct cliente {
    int id;
    char nome[50];
    char endereco[100];
    char telefone[15];
    Produto *carrinho;
    Cliente *prox;
};

Cliente *cadastroProduto(Cliente *lista){
    int opcao;
    char nomeCliente[50];
    Cliente *aux;

        printf("Digite o nome do cliente:");
        scanf(" %[^\n]", nomeCliente);
        //getchar();

        aux = buscarCliente(lista, nomeCliente);
        if(aux == NULL){
            printf("Cliente nao cadastrado, vamos cadastrar?\n[1] - Sim\n[2] - Nao\n");
            scanf("%d", &opcao);
            if(opcao == 1){
                Cliente c = preencheCliente();
                lista = insereCliente(lista, c);
            }else{
                printf("Operacao cancelada\n");
                return lista;
            }
        }

    Produto p;

    if(aux == NULL){
        printf("Insira os dados do produto\n");
        p = preencheProduto();
        aux = buscarCliente(lista, nomeCliente);
        aux->carrinho = insereProduto(aux->carrinho, p);
    }else{
        printf("Insira os dados do produto\n");
        p = preencheProduto();
        aux->carrinho = insereProduto(aux->carrinho, p);
    }
    
    return lista;
}

Cliente *buscarCliente(Cliente *lista, char *nome){
    Cliente *p;
    for(p = lista; p != NULL; p = p->prox){
        if(strcmp(p->nome, nome) == 0){
            return p;
        }
    }
    return NULL;
}

int listaVazia(Cliente *lista) {
    return (lista == NULL);
}

Cliente preencheCliente() {
    Cliente c;
    
    printf("Digite o nome do cliente: ");
    scanf(" %[^\n]", c.nome);
    printf("Digite o endereco do cliente: ");
    scanf(" %[^\n]", c.endereco);
    printf("Digite o telefone do cliente: ");
    scanf(" %[^\n]", c.telefone);
    c.id = gerarIdAleatorio();
    c.carrinho = NULL;
    c.prox = NULL;
    return c;
}

Cliente *insereCliente(Cliente *lista, Cliente c){
    Cliente *novo = (Cliente *) malloc(sizeof(Cliente));
    if(novo == NULL){
        printf("Erro ao alocar memoria\n");
        exit(1);
    }
    novo->id = c.id;
    strcpy(novo->nome, c.nome);
    strcpy(novo->endereco, c.endereco);
    strcpy(novo->telefone, c.telefone);
    novo->prox = NULL;

    if(lista == NULL || strcmp(lista->nome, novo->nome) > 0){
        novo->prox = lista;
        printf("Cliente %s cadastrado com sucesso\n", novo->nome);
        return novo;
    }

    Cliente *ant = NULL;
    Cliente *atual = lista;

    while(atual != NULL && strcmp(atual->nome, novo->nome) < 0){
        ant = atual;
        atual = atual->prox;
    }

    ant->prox = novo;
    novo->prox = atual;
    printf("Cliente %s cadastrado com sucesso\n", novo->nome);

    return lista;
}

Cliente *removeCliente(Cliente *lista, char *nome){
    Cliente *ant = NULL;
    Cliente *p = lista;
    while(p != NULL && strcmp(p->nome, nome) != 0){
        ant = p;
        p = p->prox;
    }
    if (p == NULL){
        printf("Cliente nao encontrado\n");
        return lista;
    }
    if(ant == NULL){
        lista = p->prox;
    } else {
        ant->prox = p->prox;
    }
    free(p);
    printf("Cliente %s removido com sucesso\n", nome);
    return lista;
}

void imprimeClientes(Cliente *lista){
    if(listaVazia(lista)){
        printf("Lista vazia\n");
        return;
    }

    Cliente *atual = lista;
    while(atual != NULL){
        printf("ID: %d\nNome: %s\nEndereco: %s\nTelefone: %s\n", atual->id, atual->nome, atual->endereco, atual->telefone);
        imprimeProdutos(atual->carrinho);
        atual = atual->prox;
    }
    printf("Todos os clientes foram listados\n");
}

Cliente *removerProdutoDoCliente(Cliente *lista){
    if(listaVazia(lista)){
        printf("Lista vazia\n");
        return lista;
    }

    imprimeClientes(lista);

    char nomeCliente[50];
    char nomeProduto[50];

    printf("Digite o nome do cliente: ");
    scanf(" %[^\n]", nomeCliente);
    //getchar();
    Cliente *aux = buscarCliente(lista, nomeCliente);
    if(aux == NULL){
        printf("Cliente nao encontrado\nOperacao cancelada\n");
        return lista;
    }

    printf("Digite o nome do produto: ");
    scanf(" %[^\n]", nomeProduto);
    //getchar();

    aux->carrinho = removeProduto(aux->carrinho, nomeProduto);
    return lista;
}

Cliente *editarCliente(Cliente *lista, char *nome, char *nomeProduto){
    Cliente *aux = buscarCliente(lista, nome);
    if(aux == NULL){
        printf("Cliente nao encontrado\nOperacao cancelada\n");
        return lista;
    }
    
    int opcao;
    Cliente c = preencheCliente();
    aux->id = c.id;
    strcpy(aux->nome, c.nome);
    strcpy(aux->endereco, c.endereco);
    strcpy(aux->telefone, c.telefone);
    
    printf("Deseja editar o carrinho do cliente?\n[1] - Sim\n[2] - Nao\n");
    scanf("%d", &opcao);

    if(opcao == 1){
        aux->carrinho = editarProduto(aux->carrinho, nomeProduto);
    }

    printf("Dados Atualizados\n");
    imprimeClientes(lista);
    printf("Cliente editado com sucesso\n");

    return lista;
}