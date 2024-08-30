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
        case 1:
            c = preencheCliente();
            listaClientes = insereCliente(listaClientes, c);
            imprimeClientes(listaClientes);
            break;
        case 2:

        default:
            break;
        }

    } while (opcao != 9);

    return 0;
}