#include "localidade.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


localidade *criar_localidade(char *endereco, char *cor, float custo, float valoraluguel){
 
 localidade*localidade = (localidade*)malloc(sizeof(localidade));
 strncpy(localidade->endereco, endereco, sizeof(localidade->endereco)-1);
 localidade->endereco[sizeof(localidade->endereco)- 1] == '\0';
 strncpy(localidade->cor, cor, sizeof(localidade->cor)-1);
localidade->cor[sizeof(localidade->cor)- 1] == '\0';        
localidade->custo = custo;
localidade->valoraluguel = valoraluguel;
localidade->casas = 0;
localidade->hotel =0;
return localidade;
}

void construircasa(localidade*localidade){
    if(localidade-> hotel == 1){
        printf("Não é possível construir uma casa nesse local");
    }
    else{
        localidade->casas ++
    }
}

void construirhotel(localidade*localidade){
    if(localidade->casas == 1){
        printf("Não é possível construir um hotel nesse local");
    }
    if(localidade->hotel == 1){
        printf("Já existe um hotel nessa localidade");
        return;
    }
    else{
        localidade->hotel = 1;
    }

}

    void destruir_localidade(localidade *localidade){
        free(localidade);
    }

    void definirproprietario(jogador*jogador, localidade*localidade){
        localidade->proprietario = jogador;
    }
