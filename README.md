# Sistema de Gerenciamento de Pedidos de Restaurante (versão 1.0)

## Descrição

O **Sistema de Gerenciamento de Pedidos de Restaurante** é uma aplicação desenvolvida em C para gerenciar os pedidos de um restaurante de forma eficiente. O sistema permite que os pedidos sejam armazenados em uma lista ligada e processados pela cozinha em ordem de chegada utilizando uma fila.

## Funcionalidades

- **Adicionar Pedido**: Permite que novos pedidos sejam adicionados à lista de pedidos pendentes.
- **Remover Pedido**: Permite a remoção de pratos específicos de um pedido na lista ligada.
- **Processar Pedido**: Transfere o pedido mais antigo da lista de pedidos pendentes para a fila de processamento.
- **Listar Pedidos Pendentes**: Exibe todos os pedidos atualmente armazenados na lista ligada de pedidos pendentes.
- **Listar Pedidos em Processamento**: Exibe todos os pedidos atualmente na fila de processamento.

## Estruturas de Dados

- **Lista Ligada**: Utilizada para armazenar os pedidos pendentes, permitindo a inserção e remoção de pratos específicos.
- **Fila**: Utilizada para processar os pedidos em ordem de chegada (FIFO - First In, First Out).

## Cardápio

- **Entradas**
  1. Sopa de Cebola
  2. Salada Caesar
  3. Bruschetta
  4. Carpaccio de Carne
  5. Camarão ao Alho

- **Pratos Principais**
  1. Lasanha à Bolonhesa
  2. Filé Mignon com Fritas
  3. Frango Grelhado com Legumes
  4. Bacalhau à Gomes de Sá
  5. Risoto de Cogumelos

- **Sobremesas**
  1. Tiramisu
  2. Cheesecake de Frutas Vermelhas
  3. Mousse de Chocolate
  4. Pudim de Leite
  5. Sorvete de Baunilha com Calda de Morango

## Observações

1. O código foi modularizado para facilitar a compreensão do sistema.
2. O sistema foi projetado para lidar adequadamente com tentativas de remoção de pratos que não existem na lista ligada.
3. A interface do usuário foi projetada para ser intuitiva e de fácil utilização.
