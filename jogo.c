#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "jogador.h"
#include "tabuleiro.h"
#include "jogo.h"

#define MAX_JOGADORES 100
#define LINHA_MAX 100

Jogador* ler_jogadores() {
    FILE *arquivo = fopen("jogadores.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return NULL;
    }

    Jogador*jogadores = malloc(MAX_JOGADORES * sizeof(Jogador));
    if (jogadores == NULL) {
        printf("Erro de alocação de memória.\n");
        fclose(arquivo);
        return NULL;
    }

    int indice = 0;
    char linha[LINHA_MAX];

    // Lê o numero de jogadores
    if (fgets(linha, LINHA_MAX, arquivo) != NULL) {
        int num_jogadores = atoi(linha);

        while (indice < num_jogadores && fgets(linha, LINHA_MAX, arquivo) != NULL) {
            sscanf(linha, "%49[^;];%f;%d", jogadores[indice].nome, &jogadores[indice].dinheiroinicial, &jogadores[indice].numero);
            indice++;
        }
    }

    fclose(arquivo);

        return jogadores;


void ler_localidades(Tabuleiro* tabuleiro, const char* nome_arquivo) {
    FILE* arquivo = fopen(nome_arquivo, "r");
    if (!arquivo) {
        perror("Erro ao abrir o arquivo");
        exit(EXIT_FAILURE);
    }

    char endereco[100];
    char cor[20];
    float custo;
    float valoraluguel;

    while (fscanf(arquivo, "%[^;];%[^;];%f;%f\n", endereco, cor, &custo, &valoraluguel) == 4) {
        insere_localidade(tabuleiro, endereco, custo, valoraluguel);
    }

    fclose(arquivo);
}










}