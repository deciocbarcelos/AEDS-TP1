#ifndef JOGO_H
#define JOGO_H
#define MAX_JOGADORES 100

#include "tabuleiro.h"
#include "jogador.h"    
#include "stdio.h"
#include "stdlib.h"

typedef struct Jogo{
Tabuleiro tabuleiro;
Jogador jogador[MAX_JOGADORES];
int numero_jogadores;
}Jogo;






Jogador* ler_jogadores();
void leitura_localidades(Tabuleiro* tabuleiro, const char* nome_arquivo);
int rolarDoisDados() ;
void comprar_propriedade(Jogador* jogador, Localidade *localidade);
void constroicasa(Jogador *jogador, Localidade*localidade);
void paga_aluguel(Jogador*jogador, Localidade *localidade);

#endif


