/**
 * @brief Exibe o menu principal do sistema, apresentando as opções de ações que o usuário pode escolher.
 */
void menu();

/**
 * @brief Exibe o menu de edição de cliente, apresentando as opções para editar nome, endereço ou telefone.
 */
void menuEditCliente();

/**
 * @brief Limpa a tela do console, variando o comando de acordo com o sistema operacional.
 */
void limpatela();

/**
 * @brief Gera um ID aleatório para ser utilizado como identificador único de clientes.
 *
 * @return Um número inteiro aleatório que servirá como ID do cliente.
 */
int gerarIdAleatorio();

/**
 * @brief Exibe a lista de produtos disponíveis para seleção, mostrando nome e preço de cada produto.
 */
void listaProdutos();
