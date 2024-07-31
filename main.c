#include "tabuleiro.h"
#include "leitura_localidades.h"
#include <stdio.h>
#include "jogador.h"

#define MAX_JOGADORES 100
int main() {
    Tabuleiro* tabuleiro = inicializa_tabuleiro();
    
    // Lê o arquivo e insere as localidades no tabuleiro
    ler_localidades(tabuleiro, "localidades.txt");

    // Imprime o tabuleiro
    imprimir_tabuleiro(tabuleiro);
    
    // Liberar memória alocada
    liberar_tabuleiro(tabuleiro);

    Jogador* jogadores = ler_jogadores();
    if (jogadores == NULL) {
        printf("Erro ao ler os jogadores.\n");
        return 1;
    }

    printf("||||| JOGADORES EM JOGO |||||\n");

    // Imprimir os jogadores
    for (int i = 0; i < MAX_JOGADORES && jogadores[i].numero != 0; i++) {
        printf("Nome: %s, Dinheiro Inicial: %.2f, Número: %d\n", 
                jogadores[i].nome, jogadores[i].dinheiroinicial, jogadores[i].numero);
    }
    printf("Aperte qualquer tecla para iniciar .... \n");
    getchar();
    return 0;
}
