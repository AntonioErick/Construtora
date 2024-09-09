#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void menu(){
    printf("====Bem Vindo====\n");
        printf("[1] - Cadastro Cliente\n");
        printf("[2] - Buscar Cliente\n");
        printf("[3] - Editar Cliente\n");
        printf("[4] - Remover Cliente\n");
        printf("[5] - Listar Clientes e seus respectivos produtos\n");
        printf("[6] - Cadastro Produto\n");
        printf("[7] - Busca Produto\n");
        printf("[8] - Remove Produto\n");
        printf("[0] - Sair\n");
        printf(">> ");
}

void menuEditCliente(){
    printf("[1] - Editar Nome\n");
    printf("[2] - Editar Endereço\n");
    printf("[3] - Editar Telefone\n");
    printf("[0] - Sair\n");
    printf(">> ");
}

void limpatela() {
    #ifdef _WIN32
        system("cls"); // Windows
    #elif __linux__
        system("clear"); // Linux / MacOS
    #else
        printf("Sistema operacional não suportado.\n");
    #endif
}

int gerarIdAleatorio() {
    srand(time(NULL));
    return rand() % 10000;
}
