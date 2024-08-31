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
        //remover cliente
        case 2:
            printf("Digite o nome do cliente: ");
            scanf(" %[^\n]", nomeCliente);
            listaClientes = removeCliente(listaClientes, nomeCliente);
            break;
        //cadastrar produto
        case 3:
            listaClientes = cadastroProduto(listaClientes);
            break;
        case 4:
            removerProdutoDoCliente(listaClientes);
            break;
        //imprime lista de clientes
        case 5:
            imprimeClientes(listaClientes);
        default:
            break;
        }

    } while (opcao != 9);

    return 0;
}