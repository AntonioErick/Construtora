#include "../include/produto.h"

struct produto {
    char nome[50];
    char descricao[100];
    float preco;
    int quantidade;
    Produto *prox;
};

Produto preencheProduto(){
    Produto p;
    printf("Nome do produto: ");
    scanf(" %[^\n]", p.nome);
    printf("Descricao do produto: ");
    scanf(" %[^\n]", p.descricao);
    printf("Preco do produto: ");
    scanf("%f", &p.preco);
    printf("Quantidade do produto: ");
    scanf("%d", &p.quantidade);
    p.prox = NULL;
    return p;
}

Produto *insereProduto(Produto *p, Produto pnovo){
    
    Produto *novo = (Produto *)malloc(sizeof(Produto));
    if(novo == NULL){
        printf("Erro ao alocar memoria\n");
        exit(1);
    }

    strcpy(novo->nome, pnovo.nome);
    strcpy(novo->descricao, pnovo.descricao);
    novo->preco = pnovo.preco;
    novo->quantidade = pnovo.quantidade;
    novo->prox = NULL;

    if(p == NULL || strcmp(p->nome, novo->nome) > 0){
        novo->prox = p;
        printf("Produto %s inserido com sucesso\n", novo->nome);
        return novo;
    }

    Produto *ant = NULL;
    Produto *atual = p;

    while(atual != NULL && strcmp(atual->nome, pnovo.nome) < 0){
        ant = atual;
        atual = atual->prox;
    }

    ant->prox = novo;
    novo->prox = atual;

    printf("Produto %s inserido com sucesso\n", novo->nome);
    return p;
}

void imprimeProdutos(Produto *p){
    if(p == NULL){
        printf("Nenhum produto cadastrado\n");
        return;
    }
    Produto *aux = p;
    while(aux != NULL){
        printf("Imprimindo produto...\n");
        printf("Nome: %s, Descricao: %s, Preco: %.2f, Quantidade: %d\n", aux->nome, aux->descricao, aux->preco, aux->quantidade);
        aux = aux->prox;
        printf("Produto impresso com sucesso\n");
    }
    printf("Produtos impressos com sucesso\n");
}

Produto *removeProduto(Produto *lista, char *nome){
    Produto *ant = NULL;
    Produto *p = lista;

    while(strcmp(p->nome, nome) != 0){
        if(p == NULL){
            printf("Produto nao encontrado\n");
            return lista;
        }
        ant = p;
        p = p->prox;
    }
    if(ant == NULL){
        lista = p->prox;
    } else {
        ant->prox = p->prox;
    }
    free(p);
    printf("Produto %s removido com sucesso\n", nome);
    return lista;
}

Produto *editarProduto(Produto *lista, char *nome){
    Produto *p = lista;
    int opcao = 1;
    for(p = lista; p != NULL; p = p->prox){
        if(strcmp(p->nome, nome)==0){
            printf("Nome: %s\nDescricao: %s\nPreco: %2f\nQuantidade: %d\n", p->nome, p->descricao, p->preco, p->quantidade);
            do{
                printf("[1] - Editar nome\n[2] - descricao\n[3] - preco\n[4] - quantidade\n[0] - Sair\nDigite a opcao desejada:");
                scanf("%d", &opcao);
                if (opcao == 0){
                    break;
                }
                switch(opcao){
                    case 1:
                        printf("Digite o novo nome: ");
                        scanf(" %[^\n]", p->nome);
                        break;
                    case 2:
                        printf("Digite a nova descricao: ");
                        scanf(" %[^\n]", p->descricao);
                        break;
                    case 3:
                        printf("Digite o novo preco: ");
                        scanf("%f", &p->preco);
                        break;
                    case 4:
                        printf("Digite a nova quantidade: ");
                        scanf("%d", &p->quantidade);
                        break;
                    default:
                        printf("Opcao invalida\n");
                        break;
                }
            }while(opcao != 0);
            printf("Produto %s editado com sucesso\n", nome);
            return lista;
        }
    }
    printf("Produto nao encontrado\n");
    return lista;
}