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
    printf("[5] - Carrinhos\n");
    printf("[6] - Adicionar ao Carrinho\n");
    printf("[7] - Remover Produto\n");
    printf("[8] - Vender Produtos\n");
    printf("[9] - Realizar Entregas\n");
    printf("[0] - Sair\n");
    printf(">> ");
}

void menuEditCliente(){
    printf("[1] - Editar Nome\n");
    printf("[2] - Editar Endereco\n");
    printf("[3] - Editar Telefone\n");
    printf("[0] - Sair\n");
    printf(">> ");
}

void listaProdutos(){
    printf("=== Produtos Disponiveis ===\n");
    printf("[1] - Cimento (R$ 25.00)\n");
    printf("[2] - Brita (R$ 50.00)\n");
    printf("[3] - Areia (R$ 30.00)\n");
    printf("[4] - Tijolos (R$ 350.00)\n");
    printf("[5] - Telhas (R$ 100.00)\n");
    printf("[6] - Cabos Eletricos (R$ 200.00)\n");
    printf("[7] - Canos PVC (R$ 40.00)\n");
    printf("[8] - Parafusos (R$ 5.00)\n");
    printf("[9] - Pregos (R$ 10.00)\n");
    printf("[10] - Martelo (R$ 75.00)\n");
    printf("===========================\n");
}

void limpatela(){
    #ifdef _WIN32
        system("cls"); // Windows
    #elif __linux__
        system("clear"); // Linux / MacOS
    #else
        printf("Sistema operacional nao suportado.\n");
    #endif
}

int gerarIdAleatorio(){
    srand(time(NULL));
    return rand() % 10000;
}