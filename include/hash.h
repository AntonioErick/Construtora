#ifndef HASH_H
#define HASH_H

#include "../src/cliente.c"

#define TAMANHO_TABELA 100

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
 * @brief Calcula a função hash com base no ID do cliente.
 *
 * @param id O ID do cliente.
 * @param tamanho O tamanho da tabela hash.
 * @return O índice da tabela hash onde o cliente será armazenado.
 */
int funcaoHash(int id, int tamanho);

/**
 * @brief Busca um cliente na tabela hash pelo ID.
 *
 * @param tabela Ponteiro para a tabela hash.
 * @param id O ID do cliente a ser buscado.
 * @return Ponteiro para o cliente encontrado, ou NULL se não existir.
 */
Cliente *buscaClienteHash(TabelaHash *tabela, int id);

/**
 * @brief Imprime os detalhes do cliente buscado pelo ID.
 *
 * @param tabela Ponteiro para a tabela hash.
 * @param id O ID do cliente a ser impresso.
 */
void imprimeClienteBuscado(TabelaHash *tabela, int id);

/**
 * @brief Remove um cliente da tabela hash pelo ID.
 *
 * @param tabela Ponteiro para a tabela hash.
 * @param id O ID do cliente a ser removido.
 * @return 1 se o cliente foi removido com sucesso, 0 se não foi encontrado.
 */
int removeClienteHash(TabelaHash *tabela, int id);

/**
 * @brief Edita as informações de um cliente existente na tabela hash.
 *
 * @param tabela Ponteiro para a tabela hash.
 * @param id O ID do cliente a ser editado.
 */
void editaClienteHash(TabelaHash *tabela, int id);

/**
 * @brief Imprime todos os clientes cadastrados na tabela hash.
 *
 * @param tabela Ponteiro para a tabela hash.
 */
void imprimeTabelaHash(TabelaHash *tabela);

/**
 * @brief Cadastra um produto para um cliente na tabela hash.
 *
 * @param tabela Ponteiro para a tabela hash.
 */
void cadastrarProdutoParaCliente(TabelaHash *tabela);

/**
 * @brief Remove um produto específico de um cliente na tabela hash.
 *
 * @param tabela Ponteiro para a tabela hash.
 */
void removerProdutoDoCliente(TabelaHash *tabela);

/**
 * @brief Busca um produto específico de um cliente na tabela hash.
 *
 * @param tabela Ponteiro para a tabela hash.
 */
void buscarProdutoDoCliente(TabelaHash *tabela);

/**
 * @brief Libera a memória alocada para a tabela hash e seus clientes.
 *
 * @param tabela Ponteiro para a tabela hash a ser liberada.
 */
void liberaTabelaHash(TabelaHash *tabela);

#endif // HASH_H
