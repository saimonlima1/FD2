#include <stdio.h>
#include "include/cartas.h"
#include "include/io.h"
#include "include/utils.h"

int main() {
    int escolha;
    carregarDeck(); // Carrega as cartas ao iniciar o programa

    do {
        printf("\n=== Super Trunfo ===\n");
        printf("1. Listar Cartas\n");
        printf("2. Inserir Carta\n");
        printf("3. Alterar Carta\n");
        printf("4. Excluir Carta\n");
        printf("5. Pesquisar Carta\n");
        printf("6. Visualizar Carta por Atributo\n");
        printf("7. Exportar para CSV\n");
        printf("8. Salvar e Sair\n");
        printf("Escolha: ");
        scanf("%d", &escolha);
        limparBuffer();

        switch (escolha) {
            case 1:
                listarCartas();
                break;
            case 2:
                inserirCarta();
                break;
            case 3:
                alterarCarta();
                break;
            case 4:
                excluirCarta();
                break;
            case 5:
                pesquisarCarta();
                break;
            case 6:
                visualizarCartaPorAtributo();
                break;
            case 7:
                exportarParaCSV();
                break;
            case 8:
                salvarDeck();
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (escolha != 8);

    return 0;
}
