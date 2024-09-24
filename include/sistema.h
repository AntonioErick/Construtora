/**
 * @brief Exibe o menu principal do sistema, listando as opções disponíveis para o usuário.
 *
 * O menu inclui opções como cadastro, busca, edição, remoção de clientes e produtos,
 * além de listar clientes e sair do sistema.
 */
void menu();

/**
 * @brief Exibe o menu de edição de cliente, listando as opções para alterar os dados de um cliente.
 *
 * O menu permite ao usuário editar o nome, endereço ou telefone de um cliente.
 */
void menuEditCliente();

/**
 * @brief Limpa a tela do console, dependendo do sistema operacional.
 *
 * No Windows, utiliza `cls`, enquanto no Linux e MacOS utiliza `clear`.
 * Se o sistema operacional não for suportado, exibe uma mensagem de erro.
 */
void limpatela();

/**
 * @brief Gera um ID aleatório para ser atribuído a novos clientes.
 *
 * Utiliza a função `rand()` para gerar um número aleatório entre 0 e 9999.
 *
 * @return Um número inteiro representando o ID aleatório gerado.
 */
int gerarIdAleatorio();
