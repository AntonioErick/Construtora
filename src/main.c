#include "hash.c"

int main() {
    TabelaHash *tabela = criaTabelaHash(TAMANHO_TABELA);

    int opc, idBusca;
    Cliente *cliente = NULL;

    do
    {
        menu();
        scanf("%d", &opc);
        switch (opc){
            case 0:
                limpatela();
                printf("Saindo...\n");
                liberaTabelaHash(tabela);
                break;
            case 1:
                limpatela();
                printf("Cadastrando cliente\n");
                cliente = criaCliente();
                insereClienteHash(tabela, cliente);
                break;
            case 2:
                limpatela();
                printf("Digite o ID do cliente: ");
                scanf("%d", &idBusca);
                cliente = buscaClienteHash(tabela, idBusca);
                imprimeClienteBuscado(tabela, idBusca);
                break;
            case 3:
                limpatela();
                printf("Digite o ID do cliente para editar: ");
                scanf("%d", &idBusca);
                editaClienteHash(tabela, idBusca);
                break;
            case 4:
                limpatela();
                printf("Digite o ID do cliente para remover: ");
                scanf("%d", &idBusca);
                removeClienteHash(tabela, idBusca);
                break;
            case 5:
                limpatela();
                printf("Listando todos os clientes cadastrados\n");
                imprimeTabelaHash(tabela);
                break;
            case 6:
                limpatela();
                printf("Cadastrando produto para cliente\n");
                cadastrarProdutoParaCliente(tabela);
                break;
            case 7:
                limpatela();
                printf("Buscando produto de cliente\n");
                buscarProdutoDoCliente(tabela);
                break;
            case 8:
                limpatela();
                printf("Removendo produto de cliente\n");
                removerProdutoDoCliente(tabela);
                break;
        default:
            break;
        }
    } while (opc != 0);

    return 0;
}