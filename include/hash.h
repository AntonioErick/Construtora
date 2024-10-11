#ifndef HASH_H
#define HASH_H

#include "../src/cliente.c"

#define TAMANHO_TABELA 100

/**
 * @brief Estrutura que representa uma tabela hash.
 */
typedef struct tabelaHash TabelaHash;

/**
 * @brief Cria uma tabela hash com o tamanho especificado.
 *
 * @param tamanho O tamanho da tabela hash.
 * @return Ponteiro para a nova tabela hash criada.
 */
TabelaHash *criaTabelaHash(int tamanho);

/**
 * @brief Insere um cliente na tabela hash.
 *
 * @param tabela Ponteiro para a tabela hash.
 * @param cliente Ponteiro para o cliente a ser inserido.
 */
void insereClienteHash(TabelaHash *tabela, Cliente *cliente);

/**
 * @brief Função hash que calcula o índice de um cliente com base no seu ID.
 *
 * @param id O ID do cliente.
 * @param tamanho O tamanho da tabela hash.
 * @return O índice calculado para o cliente na tabela hash.
 */
int funcaoHash(int id, int tamanho);

/**
 * @brief Busca um cliente na tabela hash com base no seu ID.
 *
 * @param tabela Ponteiro para a tabela hash.
 * @param id O ID do cliente a ser buscado.
 * @return Ponteiro para o cliente encontrado ou NULL se o cliente não for encontrado.
 */
Cliente *buscaClienteHash(TabelaHash *tabela, int id);

/**
 * @brief Imprime as informações de um cliente buscado pelo ID.
 *
 * @param tabela Ponteiro para a tabela hash.
 * @param id O ID do cliente a ser impresso.
 */
void imprimeClienteBuscado(TabelaHash *tabela, int id);

/**
 * @brief Remove um cliente da tabela hash com base no seu ID.
 *
 * @param tabela Ponteiro para a tabela hash.
 * @param id O ID do cliente a ser removido.
 * @return 1 se o cliente foi removido com sucesso, 0 caso contrário.
 */
int removeClienteHash(TabelaHash *tabela, int id);

/**
 * @brief Edita as informações de um cliente na tabela hash.
 *
 * @param tabela Ponteiro para a tabela hash.
 * @param id O ID do cliente a ser editado.
 */
void editaClienteHash(TabelaHash *tabela, int id);

/**
 * @brief Imprime todos os clientes cadastrados na tabela hash.
 *
 * @param tabela Ponteiro para a tabela hash que contém os clientes.
 */
void imprimeTabelaHash(TabelaHash *tabela);

/**
 * @brief Cadastra um produto para um cliente existente na tabela hash.
 *
 * @param tabela Ponteiro para a tabela hash onde o cliente está armazenado.
 */
void cadastrarProdutoParaCliente(TabelaHash *tabela);

/**
 * @brief Remove um produto de um cliente na tabela hash.
 *
 * @param tabela Ponteiro para a tabela hash onde o cliente está armazenado.
 */
void removerProdutoDoCliente(TabelaHash *tabela);

/**
 * @brief Busca um produto de um cliente específico na tabela hash.
 *
 * @param tabela Ponteiro para a tabela hash onde o cliente está armazenado.
 */
void buscarProdutoDoCliente(TabelaHash *tabela);

void venderProdutos(TabelaHash *tabela);

/**
* @brief Libera toda a memória associada à tabela hash e aos clientes nela armazenados.
*
* @param tabela Ponteiro para a tabela hash a ser liberada.
*/
void liberaTabelaHash(TabelaHash *tabela);

#endif
