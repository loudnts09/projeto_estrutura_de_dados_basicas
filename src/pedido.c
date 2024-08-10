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
    printf("\n----Pedido adicionado com sucesso!----\n");
}

// Função para remover um pedido da lista de pedidos
void removerPedido(Pedido **lista, int id) {
    Pedido *temp = *lista, *prev = NULL; // Ponteiros temporários para percorrer a lista
    while (temp != NULL && temp->id != id) { // Encontra o pedido a ser removido
        prev = temp;
        temp = temp->prox;
    }
    if (temp == NULL){
        printf("\n----Pedido não encontrado.----\n");
        return;
    } // Pedido não encontrado
    if (prev == NULL) *lista = temp->prox; // Remove o primeiro pedido da lista
    else prev->prox = temp->prox; // Remove um pedido no meio ou no final da lista
    printf("\n----Pedido removido com sucesso!----\n");
    free(temp); // Libera a memória do pedido removido
}

// Função para processar um pedido, movendo-o da lista de pedidos pendentes para a fila de processamento
void processarPedido(Pedido **lista, Fila *fila) {
    if (*lista == NULL){
        printf("\n----Não há pedidos para serem processados.----\n");
        return;
    } // Verifica se a lista de pedidos está vazia
    
    Pedido *temp = *lista;
    Pedido *prev = NULL;
    
    // Percorre a lista até encontrar o primeiro pedido
    while (temp->prox != NULL) {
        prev = temp;
        temp = temp->prox;
    }
    
    if (prev != NULL) {
        prev->prox = NULL; // Remove o primeiro pedido da lista
    } else {
        *lista = NULL; // A lista tinha apenas um elemento, agora fica vazia
    }
    
    temp->prox = NULL; // Define o próximo do pedido como NULL
    
    // Adiciona o pedido na fila de processamento
    if (fila->fim == NULL) { // Verifica se a fila está vazia
        fila->inicio = fila->fim = temp; // Adiciona o pedido como o único elemento na fila
    } else {
        fila->fim->prox = temp; // Adiciona o pedido no final da fila
        fila->fim = temp; // Atualiza o ponteiro do final da fila
    }
    printf("\n----Pedido processado com sucesso!----\n");
}

// Função para listar todos os pedidos pendentes
void listarPedidosPendentes(Pedido *lista) {
    if (lista == NULL) { // Verifica se a lista está vazia
        printf("\n----Não há pedidos pendentes.----\n"); // Exibe a mensagem
        return;
    }

    Pedido *temp = lista; // Ponteiro temporário para percorrer a lista
    while (temp != NULL) {
        printf("ID: %d, Descrição: %s\n", temp->id, temp->descricao); // Exibe os detalhes do pedido
        temp = temp->prox; // Move para o próximo pedido
    }
}

// Função para listar todos os pedidos em processamento
void listarPedidosEmProcessamento(Fila *fila) {
    if (fila ->inicio == NULL) { // Verifica se a fila está vazia
        printf("\n----Não há pedidos em processamento.----\n"); // Exibe a mensagem
        return;
    }

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
    printf("5. Sorvete de Baunilha com Calda de Morango\n\n\n");
}
