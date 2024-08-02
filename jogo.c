#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "jogador.h"
#include "tabuleiro.h"
#include "jogo.h"
#include "localidade.h"

#define BONUS_INICIO 200
#define MAX_JOGADORES 100
#define LINHA_MAX 100

Jogador* ler_jogadores(){
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
}

void leitura_localidades(Tabuleiro* tabuleiro, const char* nome_arquivo) {
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
int rolarDoisDados(){
    int dado1 = (rand() % 6) + 1;
    int dado2 = (rand() % 6) + 1;

    return dado1 + dado2;
}
void comprar_propriedade(Jogador* jogador, Localidade *localidade){
if (localidade->proprietario == NULL){
    if(jogador->dinheiroinicial > localidade->custo){
        jogador->dinheiroinicial - localidade->custo;
        localidade->proprietario = jogador;
        printf("Propriedade %s comprada pelo jogador %s com sucesso!\n",localidade->endereco, jogador->nome);    
    }
    else{
        printf("Você não possui fundos suficientes para comprar essa propriedade.\n");
    }
      printf("Essa propriedade já possui dono.");

}
else{
    printf("Essa propriedade já tem dono.");
}
}
void paga_aluguel(Jogador*jogador, Localidade *localidade){
if (strcmp(localidade->proprietario->nome, jogador->nome)!= 0){
    jogador->dinheiroinicial -= localidade->valoraluguel;
    localidade->proprietario->dinheiroinicial += localidade ->valoraluguel;
    printf("O jogador %s pagou %f de aluguel para o jogador %s. \n", jogador->nome, localidade->valoraluguel, localidade->proprietario->nome);
        }
        if(jogador->dinheiroinicial < localidade->valoraluguel){
            printf("O jogador não possui dinheiro para pagar o aluguel");
        } 
        else{
            printf("O jogador %s não precisa pagar aluguel por ser dono da propriedade", jogador->nome);
        }
        
            
        

}
void constroicasa(Jogador *jogador, Localidade*localidade){
if(strcmp(localidade->proprietario->nome, jogador->nome)== 0){
    if(jogador->dinheiroinicial > localidade->custo){
        int casa = 1;
        printf("O  jogador %s construiu uma casa em %s", jogador->nome, localidade->endereco);


}
    }    

}

    


   
