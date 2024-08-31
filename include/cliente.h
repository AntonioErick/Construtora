#ifndef CLIENTE_H
#define CLIENTE_H

#include "../src/produto.c"

typedef struct cliente Cliente;

Cliente *buscarCliente(Cliente *lista, char *nome);
Cliente *insereCliente(Cliente *lista, Cliente c);
Cliente preencheCliente();

#endif