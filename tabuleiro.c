#include "tabuleiro.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Tabuleiro* inicializa_tabuleiro() {
    Tabuleiro* tabuleiro = (Tabuleiro*)malloc(sizeof(Tabuleiro));
    if (!tabuleiro) {
        printf("Erro de alocação de memória!\n");
        exit(1);
    }
    tabuleiro->inicio = criar_localidade("Início", 0, 0);
    tabuleiro->inicio->proxima = tabuleiro->inicio;
    return tabuleiro;
}

void insere_localidade(Tabuleiro* tabuleiro, char* endereco, float custo, float valoraluguel) {
    Localidade* nova = criar_localidade(endereco, custo, valoraluguel);
    Localidade* atual = tabuleiro->inicio;

    while (atual->proxima != tabuleiro->inicio) {
        atual = atual->proxima;
    }

    nova->proxima = tabuleiro->inicio;
    atual->proxima = nova;
}

const char* avanca_casas(Tabuleiro* tabuleiro, const char* nome_localidade, int num_casas) {
    Localidade* atual = tabuleiro->inicio;
    while (strcmp(atual->endereco, nome_localidade) != 0) {
        atual = atual->proxima;
    }
    
    for (int i = 0; i < num_casas; i++) {
        atual = atual->proxima;
    }
    
    return atual->endereco;
}

void imprimir_tabuleiro(Tabuleiro* tabuleiro) {
    Localidade* atual = tabuleiro->inicio;
    printf("%s", atual->endereco);

    atual = atual->proxima;
    while (atual != tabuleiro->inicio) {
        printf(" -> %s", atual->endereco);
        atual = atual->proxima;
    }

    printf(" -> Início\n");
}

void liberar_tabuleiro(Tabuleiro* tabuleiro) {
    Localidade* atual = tabuleiro->inicio;
    Localidade* temp;

    do {
        temp = atual;
        atual = atual->proxima;
        free(temp);
    } while (atual != tabuleiro->inicio);

    free(tabuleiro);
}
