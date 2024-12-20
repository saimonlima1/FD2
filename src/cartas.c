#include "../include/cartas.h"
#include "utils.h"
#include <stdio.h>
#include <string.h>

Carta deck[MAX_CARTAS];
int totalCartas = 0;

void listarCartas() {
    if (totalCartas == 0) {
        printf("\nNão há cartas no deck.\n");
        return;
    }

    printf("\n--- Lista de Cartas ---\n");
    for (int i = 0; i < totalCartas; i++) {
        printf("%d. %s | Letra: %c | Número: %d | Atributos: %.2f, %.2f, %.2f, %.2f | Super Trunfo: %s\n",
               i + 1, deck[i].nome, deck[i].letra, deck[i].numero,
               deck[i].atributo1, deck[i].atributo2, deck[i].atributo3, deck[i].atributo4,
               deck[i].superTrunfo ? "Sim" : "Não");
    }
}

// Função para inserir uma nova carta no deck
void inserirCarta() {
    if (totalCartas >= MAX_CARTAS) {
        printf("\nO deck está cheio. Não é possível adicionar mais cartas.\n");
        return;
    }

    Carta novaCarta;

    // Leitura e validação do nome da carta
    printf("\nDigite o nome da carta: ");
    limparBuffer();  // Limpa o buffer antes de ler a string
    scanf("%49[^\n]", novaCarta.nome);  // Limita a leitura a 49 caracteres

    // Leitura e validação da letra (A-D)
    do {
        printf("Digite a letra da carta (A-D): ");
        scanf(" %c", &novaCarta.letra);
        limparBuffer();
        if (novaCarta.letra < 'A' || novaCarta.letra > 'D') {
            printf("Letra inválida! Por favor, digite uma letra entre A e D.\n");
        }
    } while (novaCarta.letra < 'A' || novaCarta.letra > 'D');

    // Leitura e validação do número (1-8)
    do {
        printf("Digite o número da carta (1-8): ");
        if (scanf("%d", &novaCarta.numero) != 1) {
            printf("Entrada inválida! Por favor, digite um número entre 1 e 8.\n");
            limparBuffer();
            continue;
        }
        limparBuffer();
        if (novaCarta.numero < 1 || novaCarta.numero > 8) {
            printf("Número inválido! Por favor, digite um número entre 1 e 8.\n");
        }
    } while (novaCarta.numero < 1 || novaCarta.numero > 8);

    // Leitura dos 4 atributos
    printf("Digite os 4 atributos (separados por espaço): ");
    while (scanf("%f %f %f %f", &novaCarta.atributo1, &novaCarta.atributo2, &novaCarta.atributo3, &novaCarta.atributo4) != 4) {
        printf("Entrada inválida! Por favor, digite 4 números separados por espaço.\n");
        limparBuffer();
    }
    limparBuffer();

    // Leitura se a carta é Super Trunfo
    int superTrunfoInput;
    do {
        printf("É uma carta Super Trunfo? (1 para Sim, 0 para Não): ");
        if (scanf("%d", &superTrunfoInput) != 1 || (superTrunfoInput != 0 && superTrunfoInput != 1)) {
            printf("Entrada inválida! Digite 1 para Sim ou 0 para Não.\n");
            limparBuffer();
        } else {
            novaCarta.superTrunfo = superTrunfoInput;
            limparBuffer();
            break;
        }
    } while (1);

    // Adiciona a nova carta ao deck
    deck[totalCartas++] = novaCarta;
    printf("\nCarta adicionada com sucesso!\n");
}

void alterarCarta() {
    listarCartas();
    if (totalCartas == 0) {
        return;
    }

    int indice;
    printf("\nDigite o número da carta que deseja alterar (1 a %d): ", totalCartas);
    scanf("%d", &indice);
    limparBuffer();

    if (indice < 1 || indice > totalCartas) {
        printf("Número inválido!\n");
        return;
    }

    Carta *carta = &deck[indice - 1];

    printf("Digite o novo nome da carta: ");
    scanf(" %[^\n]", carta->nome);
    printf("Digite a nova letra da carta (A-D): ");
    scanf(" %c", &carta->letra);
    printf("Digite o novo número da carta: ");
    scanf("%d", &carta->numero);
    printf("Digite os 4 novos atributos (separados por espaço): ");
    scanf("%f %f %f %f", &carta->atributo1, &carta->atributo2, &carta->atributo3, &carta->atributo4);
    printf("É uma carta Super Trunfo? (1 para Sim, 0 para Não): ");
    scanf("%d", (int*)&carta->superTrunfo);

    printf("Carta alterada com sucesso!\n");
}


void excluirCarta() {
    listarCartas();
    if (totalCartas == 0) {
        return;
    }

    int indice;
    printf("\nDigite o número da carta que deseja excluir (1 a %d): ", totalCartas);
    scanf("%d", &indice);
    limparBuffer();

    if (indice < 1 || indice > totalCartas) {
        printf("Número inválido!\n");
        return;
    }

    for (int i = indice - 1; i < totalCartas - 1; i++) {
        deck[i] = deck[i + 1];
    }

    totalCartas--;
    printf("Carta excluída com sucesso!\n");
}

void pesquisarCarta() {
    char nomeBusca[50];
    printf("\nDigite o nome da carta para pesquisar: ");
    scanf(" %[^\n]", nomeBusca);

    int encontrado = 0;
    for (int i = 0; i < totalCartas; i++) {
        if (strcmp(deck[i].nome, nomeBusca) == 0) {
            printf("Carta encontrada:\n");
            printf("%d. %s | Letra: %c | Número: %d | Atributos: %.2f, %.2f, %.2f, %.2f | Super Trunfo: %s\n",
                   i + 1, deck[i].nome, deck[i].letra, deck[i].numero,
                   deck[i].atributo1, deck[i].atributo2, deck[i].atributo3, deck[i].atributo4,
                   deck[i].superTrunfo ? "Sim" : "Não");
            encontrado = 1;
        }
    }

    if (!encontrado) {
        printf("Carta não encontrada.\n");
    }
}

void visualizarCartaPorAtributo() {
    float valor;
    printf("Digite o valor mínimo do atributo a visualizar: ");
    scanf("%f", &valor);

    printf("\n--- Cartas com atributos acima de %.2f ---\n", valor);
    for (int i = 0; i < totalCartas; i++) {
        if (deck[i].atributo1 >= valor || deck[i].atributo2 >= valor ||
            deck[i].atributo3 >= valor || deck[i].atributo4 >= valor) {
            printf("%d. %s | Atributos: %.2f, %.2f, %.2f, %.2f\n",
                   i + 1, deck[i].nome, deck[i].atributo1,
                   deck[i].atributo2, deck[i].atributo3, deck[i].atributo4);
        }
    }
}


