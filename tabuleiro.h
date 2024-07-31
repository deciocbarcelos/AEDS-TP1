#ifndef TABULEIRO_H
#define TABULEIRO_H

#include "localidade.h"

typedef struct {
    Localidade* inicio;
} Tabuleiro;

Tabuleiro* inicializa_tabuleiro();
void insere_localidade(Tabuleiro* tabuleiro, char* endereco, float custo, float valoraluguel);
const char* avanca_casas(Tabuleiro* tabuleiro, const char* nome_localidade, int num_casas);
void imprimir_tabuleiro(Tabuleiro* tabuleiro);
void liberar_tabuleiro(Tabuleiro* tabuleiro);

#endif
