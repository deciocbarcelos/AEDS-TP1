#ifndef JOGADOR_H
#define JOGADOR_H

typedef struct Jogador {
    char nome[50];
    float dinheiroinicial;
    int numero;
} Jogador;

Jogador* ler_jogadores();

#endif
