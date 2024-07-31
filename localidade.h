#ifndef LOCALIDADE_H
#define LOCALIDADE_H

#include "jogador.h"

typedef struct localidade {
    char endereco[50];
    float custo;
    float valoraluguel;
    Jogador* proprietario; // Ponteiro para o jogador que é proprietário
    int hotel; // 1 se há hotel, 0 caso não haja
    int casas; // número de casas construídas
    struct localidade* proxima; // Ponteiro para a próxima localidade na lista circular
} Localidade;

Localidade* criar_localidade(char* endereco, float custo, float valoraluguel);
void destruir_localidade(Localidade* localidade);

#endif
