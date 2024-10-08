#ifndef HASH_H
#define HASH_H

#include "../src/cliente.c"

#define TAMANHO_TABELA 100

typedef struct tabelaHash TabelaHash;

TabelaHash* criaTabelaHash(int tamanho);
void insereClienteHash(TabelaHash *tabela, Cliente *cliente);
int funcaoHash(int id, int tamanho);
Cliente* buscaClienteHash(TabelaHash *tabela, int id);
void imprimeClienteBuscado(TabelaHash *tabela, int id);
int removeClienteHash(TabelaHash *tabela, int id);
void editaClienteHash(TabelaHash *tabela, int id);
void imprimeTabelaHash(TabelaHash *tabela);
void cadastrarProdutoParaCliente(TabelaHash *tabela);
void removerProdutoDoCliente(TabelaHash *tabela);
void buscarProdutoDoCliente(TabelaHash *tabela);
void liberaTabelaHash(TabelaHash *tabela);


#endif