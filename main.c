#include "tabuleiro.h"
#include <stdio.h>
#include "jogador.h"
#include "jogo.h"
#include <stdlib.h>



int main() {
    Tabuleiro* tabuleiro = inicializa_tabuleiro();
    
    leitura_localidades(tabuleiro, "localidades.txt");

    imprimir_tabuleiro(tabuleiro);
    
    liberar_tabuleiro(tabuleiro);

    Jogador* jogadores = ler_jogadores();
    if (jogadores == NULL) {
        printf("Erro ao ler os jogadores.\n");
        return 1;
    }

    printf("||||| JOGADORES EM JOGO |||||\n");

    
    for (int i = 0; i < MAX_JOGADORES && jogadores[i].numero != 0; i++) {
        printf("Nome: %s, Dinheiro Inicial: %.2f, Número: %d\n", 
                jogadores[i].nome, jogadores[i].dinheiroinicial, jogadores[i].numero);
    }
    printf("Aperte qualquer tecla para iniciar .... \n");
    
    return 0;
}
