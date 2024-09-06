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
                printf("Saindo...\n");
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
        default:
            break;
        }
    } while (opc != 0);

    return 0;
}