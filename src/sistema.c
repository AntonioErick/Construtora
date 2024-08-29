#include "../includes/sistema.h"
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>

void menu(){
    printf("====== BEM VINDO ======\n");
    printf("[1]-Adicionar Produto\n");
    printf("[2]-Buscar Produto\n");
    printf("[3]-Remover Produto\n");
    printf("[4]-Editar Produto\n");
    printf("[5]-Adicionar Cliente\n");
    printf("[6]-Buscar Cliente\n");
    printf("[7]-Remover Cliente\n");
    printf("[8]-Listar Cliente e seus respectivos produtos\n");
    printf("[9]-Sair\n");
}
