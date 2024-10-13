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

/**
 * @brief Valida a entrada de um número inteiro.
 * 
 * Garante que o valor digitado seja um número inteiro válido. Solicita nova entrada até ser válida.
 * 
 * @param valor Ponteiro para armazenar o valor inteiro validado.
 */
void validaEntradaInteiro(int *valor);

/**
 * @brief Função que valida a entrada de uma string.
 *
 * Esta função recebe uma entrada do usuário e valida se é uma string composta apenas por letras.
 * Ela também garante que o tamanho da string não ultrapasse o limite especificado por `tamanhoMaximo`.
 * A função permite nomes compostos (com espaços), mas não permite números ou outros caracteres especiais.
 * Se a entrada for inválida, solicita ao usuário que insira novamente até que uma string válida seja fornecida.
 *
 * @param entrada Ponteiro para o array de caracteres onde a string validada será armazenada.
 * @param tamanhoMaximo O tamanho máximo permitido para a string.
 * @return void
 */
void validaEntradaString(char *entrada, int tamanhoMaximo);

/**
 * @brief Valida a entrada de um número de telefone, aceitando apenas dígitos.
 * 
 * Garante que o telefone tenha entre 9 e 15 dígitos. Solicita nova entrada até que seja válida.
 * 
 * @param telefone Ponteiro para armazenar o telefone validado.
 * @param tamanhoMaximo Tamanho máximo permitido (até 15 dígitos).
 */
void validaEntradaTelefone(char *telefone, int tamanhoMaximo);

/**
 * @brief Limpa o buffer de entrada.
 * 
 * Remove caracteres indesejados do buffer de entrada, prevenindo problemas com entradas subsequentes.
 */
void limpaBufferEntrada();

