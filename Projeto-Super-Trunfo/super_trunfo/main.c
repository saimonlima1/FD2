#include <stdio.h>
#include <stdlib.h>
#include "jogo.h"
#include "cartas.h"

int main() {
    int escolha;
    carregarCartasBinario();

    do {
        printf("\n=== Super Trunfo Pokémon ===\n");
        printf("1. Listar Cartas\n");
        printf("2. Inserir Carta\n");
        printf("3. Jogar Partida\n");
        printf("4. Carregar Cartas do CSV\n");
        printf("5. Sair\n");
        printf("Escolha: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                listarCartas();
                break;
            case 2:
                inserirCarta();
                break;
            case 3:
                jogarPartida(deck, totalCartas);
                break;
            case 4:
                carregarCartasDoCSV();
                break;
            case 5:
                salvarCartasBinario();
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (escolha != 5);

    return 0;
}
