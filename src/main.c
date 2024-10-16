#include "hash.c"

int main(){
    TabelaHash *tabela = criaTabelaHash(TAMANHO_TABELA);
    Heap *heap = criaHeap(100);
    int opc, idBusca;
    Cliente *cliente = NULL;

    do{
        menu();
        opc = validaEntradaInteiro();
        switch (opc){
            case 0:
                limpatela();
                printf("Saindo...\n");
                liberaTabelaHash(tabela);
                free(heap);
                break;
            case 1:
                limpatela();
                printf("Cadastrando cliente\n");
                cliente = criaCliente();
                insereClienteHash(tabela, cliente); 
                atualizarValorTotalCliente(cliente);
                break;
            case 2:
                limpatela();
                printf("Digite o ID do cliente: ");
                idBusca = validaEntradaInteiro();
                cliente = buscaClienteHash(tabela, idBusca);
                imprimeClienteBuscado(tabela, idBusca);
                break;
            case 3:
                limpatela();
                printf("Digite o ID do cliente para editar: ");
                idBusca = validaEntradaInteiro();
                editaClienteHash(tabela, idBusca);
                break;
            case 4:
                limpatela();
                printf("Digite o ID do cliente para remover: ");
                idBusca = validaEntradaInteiro();
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
                printf("Removendo produto de cliente\n");
                removerProdutoDoCliente(tabela);
                break;
            case 8:
                limpatela();
                printf("Vendendo os Produtos\n");
                venderProdutos(tabela, heap);
                break;
            case 9:
                limpatela();
                printf("Realizando entrega de produtos\n");
                entregaProdutos(heap);
                break;
            default:
                break;
        }
    } while (opc != 0);

    return 0;
}