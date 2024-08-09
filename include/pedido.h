#ifndef PEDIDO_H
#define PEDIDO_H

// Definição da estrutura de um pedido
typedef struct Pedido {
    int id; // ID do pedido
    char descricao[100]; // Descrição do pedido
    struct Pedido *prox; // Ponteiro para o próximo pedido
} Pedido;

// Definição da estrutura da fila de pedidos em processamento
typedef struct Fila {
    Pedido *inicio; // Ponteiro para o início da fila
    Pedido *fim; // Ponteiro para o final da fila
} Fila;

// Declaração das funções utilizadas no programa
void adicionarPedido(Pedido **lista, int id, char *descricao);
void removerPedido(Pedido **lista, int id);
void processarPedido(Pedido **lista, Fila *fila);
void listarPedidosPendentes(Pedido *lista);
void listarPedidosEmProcessamento(Fila *fila);
void exibirCardapio();

#endif
