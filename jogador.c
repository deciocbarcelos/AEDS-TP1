#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "jogador.h"

#define MAX_JOGADORES 100 // Você pode ajustar esse valor conforme necessário
#define LINHA_MAX 100

Jogador* ler_jogadores() {
    FILE *arquivo = fopen("jogadores.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return NULL;
    }

    Jogador *jogadores = malloc(MAX_JOGADORES * sizeof(Jogador));
    if (jogadores == NULL) {
        printf("Erro de alocação de memória.\n");
        fclose(arquivo);
        return NULL;
    }

    int indice = 0;
    char linha[LINHA_MAX];

    // Lê o número de jogadores (primeira linha)
    if (fgets(linha, LINHA_MAX, arquivo) != NULL) {
        int num_jogadores = atoi(linha);

        while (indice < num_jogadores && fgets(linha, LINHA_MAX, arquivo) != NULL) {
            sscanf(linha, "%49[^;];%f;%d", jogadores[indice].nome, &jogadores[indice].dinheiroinicial, &jogadores[indice].numero);
            indice++;
        }
    }

    fclose(arquivo);

        return jogadores;
}
