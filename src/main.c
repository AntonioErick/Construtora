#include "cliente.c"

int main() {

    int opcao;
    Produto p;
    char nomeCliente[50];

    Cliente *listaClientes = NULL;
    Cliente c;
    do {
        menu();
        scanf("%d", &opcao);

        switch (opcao)
        {
        //cadastrar cliente
        case 1:
            c = preencheCliente();
            listaClientes = insereCliente(listaClientes, c);
            break;
        //buscar cliente
        case 2:
            printf("Digite o nome do cliente: ");
            scanf(" %[^\n]", nomeCliente);
            buscarCliente(listaClientes, nomeCliente);
            break;
        //editar cliente
        case 3:
            printf("Digite o nome do cliente: ");
            scanf(" %[^\n]", nomeCliente);
            listaClientes = editarCliente(listaClientes, nomeCliente, p.nome);
            break;
        //imprime lista de clientes
        case 4:
            imprimeClientes(listaClientes);
            break;
            /*removerProdutoDoCliente(listaClientes);
            break;*/
        //remover cliente
        case 5:
            printf("Digite o nome do cliente: ");
            scanf(" %[^\n]", nomeCliente);
            listaClientes = removeCliente(listaClientes, nomeCliente);
            break;
        //cadastrar produto
        case 6:
            listaClientes = cadastroProduto(listaClientes);
            break;
        default:
            break;
        }

    } while (opcao != 9);

    return 0;
}