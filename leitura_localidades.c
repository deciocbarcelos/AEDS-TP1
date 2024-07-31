#include "leitura_localidades.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
