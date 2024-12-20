#ifndef CARTAS_H
#define CARTAS_H

#include <stdbool.h>

#define MAX_CARTAS 100

typedef struct {
    char nome[50];
    char letra;
    int numero;
    float atributo1;
    float atributo2;
    float atributo3;
    float atributo4;
    bool superTrunfo;
} Carta;

extern Carta deck[MAX_CARTAS];
extern int totalCartas;

void listarCartas();
void inserirCarta();
void alterarCarta();
void excluirCarta();
void pesquisarCarta();
void visualizarCartaPorAtributo();

#endif
