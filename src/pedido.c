#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/pedido.h"

// Função para adicionar um novo pedido na lista de pedidos
void adicionarPedido(Pedido **lista, int id, char *descricao) {
    Pedido *novo = (Pedido *)malloc(sizeof(Pedido)); // Aloca memória para um novo pedido
    novo->id = id; // Define o ID do pedido
    strcpy(novo->descricao, descricao); // Copia a descrição do pedido
    novo->prox = *lista; // Aponta o novo pedido para o início da lista
    *lista = novo; // Atualiza a lista para incluir o novo pedido
}

// Função para remover um pedido da lista de pedidos
void removerPedido(Pedido **lista, int id) {
    Pedido *temp = *lista, *prev = NULL; // Ponteiros temporários para percorrer a lista
    while (temp != NULL && temp->id != id) { // Encontra o pedido a ser removido
        prev = temp;
        temp = temp->prox;
    }
    if (temp == NULL) return; // Pedido não encontrado
    if (prev == NULL) *lista = temp->prox; // Remove o primeiro pedido da lista
    else prev->prox = temp->prox; // Remove um pedido no meio ou no final da lista
    free(temp); // Libera a memória do pedido removido
}

// Função para processar um pedido, movendo-o da lista de pedidos pendentes para a fila de processamento
void processarPedido(Pedido **lista, Fila *fila) {
    if (*lista == NULL) return; // Verifica se a lista de pedidos está vazia
    Pedido *pedido = *lista; // Aponta para o primeiro pedido da lista
    *lista = (*lista)->prox; // Remove o pedido da lista
    pedido->prox = NULL; // Define o próximo do pedido como NULL
    if (fila->fim == NULL) { // Verifica se a fila está vazia
        fila->inicio = fila->fim = pedido; // Adiciona o pedido como o único elemento na fila
    } else {
        fila->fim->prox = pedido; // Adiciona o pedido no final da fila
        fila->fim = pedido; // Atualiza o ponteiro do final da fila
    }
}

// Função para listar todos os pedidos pendentes
void listarPedidosPendentes(Pedido *lista) {
    Pedido *temp = lista; // Ponteiro temporário para percorrer a lista
    while (temp != NULL) {
        printf("ID: %d, Descrição: %s\n", temp->id, temp->descricao); // Exibe os detalhes do pedido
        temp = temp->prox; // Move para o próximo pedido
    }
}

// Função para listar todos os pedidos em processamento
void listarPedidosEmProcessamento(Fila *fila) {
    Pedido *temp = fila->inicio; // Ponteiro temporário para percorrer a fila
    while (temp != NULL) {
        printf("ID: %d, Descrição: %s\n", temp->id, temp->descricao); // Exibe os detalhes do pedido
        temp = temp->prox; // Move para o próximo pedido
    }
}

// Função para exibir o cardápio
void exibirCardapio() {
    printf("=====================================\n");
    printf("             Cardápio\n");
    printf("=====================================\n\n");

    printf("- Entradas:\n");
    printf("1. Sopa de Cebola\n");
    printf("2. Salada Caesar\n");
    printf("3. Bruschetta\n");
    printf("4. Carpaccio de Carne\n");
    printf("5. Camarão ao Alho\n");
    printf("\n- Pratos Principais\n");
    printf("1. Lasanha à Bolonhesa\n");
    printf("2. Filé Mignon com Fritas\n");
    printf("3. Frango Grelhado com Legumes\n");
    printf("4. Bacalhau à Gomes de Sá\n");
    printf("5. Risoto de Cogumelos\n");
    printf("\n- Sobremesas\n");
    printf("1. Tiramisu\n");
    printf("2. Cheesecake de Frutas Vermelhas\n");
    printf("3. Mousse de Chocolate\n");
    printf("4. Pudim de Leite\n");
    printf("5. Sorvete de Baunilha com Calda de Morango\n");
}
