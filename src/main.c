#include <stdio.h>
#include <stdlib.h>
#include "../include/pedido.h"

// Função que exibe o menu de opções para o usuário
void menu() {
    printf("-Escolha uma opção:\n\n");
    printf("1. Exibir Cardápio\n");
    printf("2. Adicionar Pedido\n");
    printf("3. Remover Pedido\n");
    printf("4. Processar Pedido\n");
    printf("5. Listar Pedidos Pendentes\n");
    printf("6. Listar Pedidos em Processamento\n");
    printf("7. Sair\n");
}

int main() {
    Pedido *lista = NULL; // Lista encadeada de pedidos
    Fila fila = {NULL, NULL}; // Fila de pedidos em processamento
    int opcao, id;
    char descricao[100];

    printf("===============================================================\n");
    printf("Bem-vindo ao Sistema de Gerenciamento de Pedidos de Restaurante\n");
    printf("===============================================================\n\n");

    while (1) {
        menu(); // Exibe o menu para o usuário
        scanf("%d", &opcao); // Lê a opção escolhida pelo usuário
        printf("\n------------------------------------------------------------\n");
        switch (opcao) {
            case 1:
                exibirCardapio(); // Exibe o cardápio
                break;
            case 2:
                printf("Digite o ID do pedido: ");
                scanf("%d", &id);
                printf("Digite a descrição do pedido: ");
                scanf(" %[^\n]", descricao); // Lê a descrição do pedido
                adicionarPedido(&lista, id, descricao); // Adiciona um novo pedido
                break;
            case 3:
                printf("Digite o ID do pedido a ser removido: ");
                scanf("%d", &id);
                removerPedido(&lista, id); // Remove um pedido existente
                break;
            case 4:
                processarPedido(&lista, &fila); // Processa um pedido
                break;
            case 5:
                listarPedidosPendentes(lista); // Lista todos os pedidos pendentes
                break;
            case 6:
                listarPedidosEmProcessamento(&fila); // Lista todos os pedidos em processamento
                break;
            case 7:
                exit(0); // Encerra o programa
            default:
                printf("Opção inválida!\n"); // Mensagem de erro para opção inválida
        }
    }

    return 0;
}
