#include "../include/cartas.h"
#include "../include/io.h"
#include <stdio.h>

void exportarParaCSV() {
    FILE *arquivo = fopen("data/cartas.csv", "w");
    if (arquivo == NULL) {
        printf("Erro ao criar o arquivo CSV!\n");
        return;
    }

    for (int i = 0; i < totalCartas; i++) {
        fprintf(arquivo, "%s,%c,%d,%.2f,%.2f,%.2f,%.2f,%d\n",
                deck[i].nome, deck[i].letra, deck[i].numero,
                deck[i].atributo1, deck[i].atributo2, deck[i].atributo3, deck[i].atributo4,
                deck[i].superTrunfo);
    }
    fclose(arquivo);
    printf("Deck exportado para 'data/cartas.csv'.\n");
}

void salvarDeck() {
    FILE *arquivo = fopen("data/cartas.bin", "wb");
    if (arquivo == NULL) {
        printf("Erro ao salvar o deck!\n");
        return;
    }

    fwrite(&totalCartas, sizeof(int), 1, arquivo);
    fwrite(deck, sizeof(Carta), totalCartas, arquivo);
    fclose(arquivo);
    printf("Deck salvo com sucesso!\n");
}

void carregarDeck() {
    FILE *arquivo = fopen("data/cartas.bin", "rb");
    if (arquivo != NULL) {
        fread(&totalCartas, sizeof(int), 1, arquivo);
        fread(deck, sizeof(Carta), totalCartas, arquivo);
        fclose(arquivo);
    } else {
        printf("Arquivo 'cartas.bin' não encontrado. Iniciando com um deck vazio.\n");
    }
}

