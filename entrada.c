#include <stdio.h>
#include <stdlib.h>
#include "jogador.h"
#include "localidade.h"
#include <string.h>


    int cont;   

       jogador *lerjogadores(const char * arquivo, int * numjogadores){
        char nome_arquivojogadores[50];
        scanf("%c", nome_arquivojogadores);

       FILE * jogador;
       if(jogador = fopen(joga, "r"))== NULL{
        printf("Erro ao abrir o arquivo!");
        return;
       }
       else{
        fscanf(jogador, "%d", numjogadores);
       }
       
       
       jogador* jogadores = (jogador*)malloc(numjogadores * sizeof(jogador));
       
for (int i = 0; i < numjogadores; i++) {
        fscanf(jogador, " %[^;];%f;%d", jogadores[i].nome, &jogadores[i].dinheiroInicial, &jogadores[i].numero);
    }
fclose(jogador); // fim da leitura do arquivo jogadores.

//---------------------------------------------------------------------------------------------------------------------------------------------------------//

localidade *lerlocalidades(const char * arquivo, int * numlocalidade){  


FILE * localidade;
if(localidade = fopen(arquivo, "r"))== NULL{
    printf("Erro ao abrir o arquivo!");
    return
}
else{
    fscanf(localidade,"%d", numlocalidade);
}

    Localidade* localidades = (Localidade*) malloc((*numLocalidades) * sizeof(Localidade));

    for (int i = 0; i < *numLocalidades; i++) {
        fscanf(fp, " %[^;];%[^;];%d;%d", localidades[i].endereco, localidades[i].cor, &localidades[i].custo, &localidades[i].valoraluguel);
    }

    fclose(localidade);
       
       
       
       
       
       
       
       
       
       
       
       
       
       
       
       
       
       }                                                                                                                                                                         J  