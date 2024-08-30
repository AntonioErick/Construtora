#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void menu(){
    printf("====Bem Vindo====\n");
        printf("[1] - Cadastro Cliente\n");
        printf("[2] - Buscar Cliente\n");
        printf("[3] - Editar Cliente\n");
        printf("[4] - Listar Clientes e seus respectivos produtos\n");
        printf("[5] - Remover Cliente\n");
        printf("[6] - Cadastro Produto\n");
        printf("[7] - Busca Produto\n");
        printf("[8] - Remove Produto\n");
        printf("[9] - Sair\n");
}

int gerarIdAleatorio() {
    srand(time(NULL));
    return rand() % 10000;
}