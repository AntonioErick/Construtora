<h1>
  <div align="center">
    <p>Construtech - Construa seu futuro com a gente!🛠️<p>
  </div>
</h1>

## 🚨Sobre nós

**Construtech** é um projeto desenvolvido em linguagem C, que implementa um sistema de gerenciamento para uma construtora que armazena e gerencia dados de clientes e produtos. A aplicação é composta por diversas funcionalidades que permitem um controle eficiente das informações relacionadas aos clientes e seus respectivos produtos.

## 💻Estrutura de Dados Utilizadas

- Tabela Hash: Desenvolvida para distribuir e armazenar clientes, possibilitando operações de inserção, busca e remoção de maneira rápida e com o tratamento de colisões.
  
- AVL: Implementada para gerenciar produtos, assegurando operações balanceadas de inserção, busca e remoção, com complexidade de tempo O(log n).
  
- Heap: Gerencia a
prioridade nas entregas dos produtos vendidos, permitindo um
controle otimizado e seguro da sequência de entregas conforme
a prioridade dos pedidos.

## 🔍Funcionalidades
- Cliente:

   - Adicionar novos clientes ao sistema. 

   - Permite procurar um cliente específico no sistema.

   - Opção para atualizar informações de um cliente já cadastrado.
 
   - Permite a exclusão de um cliente cadastrado.

- Loja:

  - Exibe uma lista de todos os clientes cadastrados e os seus respectivos produtos.

  - Função para adicionar novos produtos à loja, permitindo que sejam vinculados aos clientes.

  - Permite excluir um produto da lista de disponíveis na loja.

  - Encerra o programa.
 
- Menu Interativo:
```bash
=============================================
       Bem-vindo ao Sistema ConstruTech     
    Gestão de Clientes, Produtos e Entregas 
=============================================
[1] - Cadastrar Cliente
[2] - Buscar Cliente
[3] - Editar Cliente
[4] - Remover Cliente
[5] - Ver Carrinho
[6] - Adicionar Produtos ao Carrinho
[7] - Remover Produtos do Carrinho
[8] - Finalizar Compra e Registrar Pedido
[9] - Realizar Entregas
[0] - Sair
=============================================
````

## 🗂 Arquivos de Cabeçalho (.h)
  - cliente.h:
    - Estrutura Cliente, com novos atributos para suportar o
carrinho de compras e histórico de pedidos.
    - Funções expandidas para manipulação de clientes.
      
  - hash.h
    - Funções de tabela hash otimizadas, incluindo
insereClienteHash e buscaClienteHash.
    - Nova função editaClienteHash para permitir edição de
informações do cliente diretamente pela interface.

  - produto.h
    - Estrutura Produto e funções de árvore AVL para gerenciar
produtos.
    - Funções de controle de estoque e verificação de
disponibilidade foram adicionadas.

  - sistema.h
    - Adição de funções de interface, como menu() e
menuEditCliente().
    - Implementação das funções listaProdutos() e limpatela()
para melhorar a experiência do usuário.

## 🗂 Arquivos de Implementação (.c)
  - main.c
    - Arquivo principal reorganizado com novos casos de uso,
como cadastrar produtos no carrinho e finalizar compras.
    - Função venderProdutos() aprimorada para registrar e
transferir pedidos para a fila de entregas.

  - sistema.c
    - Novas funções adicionadas para exibir produtos, limpar a
tela e gerar IDs aleatórios.
    - Menus otimizados e funções de validação implementadas
para evitar entradas incorretas do usuário.

  - hash.c
    - Código da tabela hash melhorado para suportar tratamento
de colisões e edição de clientes.
    - Nova função removeClienteHash() otimizada para liberar
memória de forma segura.

  - produto.c
    - Implementações de AVL aprimoradas com funções para
controle de estoque e verificação de produtos.

  - cliente.c
    - Expansão da função criaCliente() para lidar com carrinho
de compras.
    - Função imprimeCliente() atualizada para exibir carrinho e
histórico de pedidos.


## ♻ Clonar repositório
```bash
# Clone the repository
$ git clone https://github.com/AntonioErick/Construtora.git

https://github.com/AntonioErick/Construtora.git
````

```bash
# Enter directory
$ cd Construtora
```

## 👨‍💻 Contribuidores

<table align="center">
  <tr>
    <td align="center">
      <b>João Gustavo</b><br>
      <img src="https://avatars.githubusercontent.com/u/111452823?s=100&v=4" alt="João Gustavo" width="60">
    </td>
    <td align="center">
      <b>Jean Richardson</b><br>
      <img src="https://avatars.githubusercontent.com/u/124441400?s=100&v=4" alt="Jean Richardson" width="60">
    </td>
  </tr>
  <tr>
    <td align="center">
      <b>Gustavo Kesley</b><br>
      <img src="https://avatars.githubusercontent.com/u/72459288?s=100&v=4" alt="Gustavo Kesley" width="60">
    </td>
    <td align="center">
      <b>Antonio Erick</b><br>
      <img src="https://avatars.githubusercontent.com/u/147534096?v=4" alt="Antonio Erick" width="60">
    </td>
  </tr>
</table>
