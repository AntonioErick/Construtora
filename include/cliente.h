#ifndef CLIENTE_H
#define CLIENTE_H

#include "../src/produto.c"

typedef struct cliente Cliente;

Cliente* criaCliente();
void imprimeCliente(Cliente *cliente);
#endif