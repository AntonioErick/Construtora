#ifndef CLIENTE_H
#define CLIENTE_H

#include "../src/produto.c"

typedef struct cliente Cliente;

/**
 * @brief Cria um novo cliente com as informações fornecidas pelo usuário.
 *
 * Solicita ao usuário o nome, endereço e telefone do cliente e gera um ID aleatório para o cliente.
 *
 * @return Ponteiro para o novo cliente criado.
 */
Cliente *criaCliente();

/**
 * @brief Imprime os detalhes de um cliente, incluindo suas informações básicas e produtos associados.
 *
 * Exibe o ID, nome, endereço e telefone do cliente, além de listar os produtos cadastrados, caso existam.
 *
 * @param cliente Ponteiro para o cliente a ser impresso.
 */
void imprimeCliente(Cliente *cliente);

#endif // CLIENTE_H
