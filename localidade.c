
#include "localidade.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h> 

Localidade* criar_localidade(char* endereco, float custo, float valoraluguel) {
    Localidade* localidade = (Localidade*)malloc(sizeof(Localidade));
    if (!localidade) {
        printf("Erro de alocação de memória!\n");
        exit(1);
    }
    strncpy(localidade->endereco, endereco, 50);
    localidade->custo = custo;
    localidade->valoraluguel = valoraluguel;
    localidade->proprietario = NULL;
    localidade->hotel = 0;
    localidade->casas = 0;
    localidade->proxima = NULL;
    return localidade;
}

void destruir_localidade(Localidade* localidade) {
    free(localidade);
}
