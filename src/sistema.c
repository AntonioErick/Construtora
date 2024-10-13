#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

void menu(){
    printf("======================================================\n");
    printf("||          Bem-vindo ao Sistema ConstruTech        ||\n");
    printf("||       Gestao de Clientes, Produtos e Entregas    ||\n");
    printf("======================================================\n");
    printf("|| [1] - Cadastrar Cliente                          ||\n");
    printf("|| [2] - Buscar Cliente                             ||\n");
    printf("|| [3] - Editar Cliente                             ||\n");
    printf("|| [4] - Remover Cliente                            ||\n");
    printf("|| [5] - Ver Carrinho                               ||\n");
    printf("|| [6] - Adicionar Produtos ao Carrinho             ||\n");
    printf("|| [7] - Remover Produtos do Carrinho               ||\n");
    printf("|| [8] - Finalizar Compra e Registrar Pedido        ||\n");
    printf("|| [9] - Realizar Entregas                          ||\n");
    printf("|| [0] - Sair                                       ||\n");
    printf("======================================================\n");
    printf("   Selecione uma opcao: ");
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

//tratativas

int validaEntradaInteiro() {
    int valor;
    char buffer[100];
    char extra;

    while (1) {
        fgets(buffer, sizeof(buffer), stdin);
        if (sscanf(buffer, "%d %c", &valor, &extra) == 1) {
            // Apenas um número foi lido, sem caracteres adicionais
            return valor;
        } else {
            printf("Entrada invalida. Digite um numero inteiro: ");
        }
    }
}

void validaEntradaString(char *entrada, int tamanhoMax) {
    int valida = 0;

    do {
        fgets(entrada, tamanhoMax, stdin);
        entrada[strcspn(entrada, "\n")] = 0; 

        valida = 1; 

       
        for (int i = 0; i < strlen(entrada); i++) {
            if (!isalpha(entrada[i]) && entrada[i] != ' ') {  
                printf("Entrada invalida. Digite apenas letras e espacos: ");
                valida = 0;
                break;
            }
        }

        if (strlen(entrada) == 0) {  
            printf("Entrada invalida. Não pode ser vazia. Digite novamente: ");
            valida = 0;
        }

    } while (!valida);  
}

void validaEntradaTelefone(char *entrada, int tamanhoMax) {
    int valida = 0;

    do {
        fgets(entrada, tamanhoMax, stdin);
        entrada[strcspn(entrada, "\n")] = 0; 

        valida = 1; 

        int tamanhoEntrada = strlen(entrada);


        if (tamanhoEntrada < 9 || tamanhoEntrada > 15) {
            printf("Telefone invalido. Deve ter entre 9 e 15 digitos. Digite novamente: ");
            valida = 0;
            continue; 
        }

        for (int i = 0; i < tamanhoEntrada; i++) {
            if (!isdigit(entrada[i])) {  
                printf("Entrada invalida. Digite apenas numeros. Digite novamente: ");
                valida = 0;
                break;
            }
        }

    } while (!valida);  
}

void limpaBufferEntrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
