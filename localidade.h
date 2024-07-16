
#include "jogador.h"
typedef struct {

    char endereco[20];
    char cor[20];
    float custo;
    float valoraluguel;
    Jogador *proprietario; // Ponteiro para  o jogador que é proprietário;
    int hotel; //  1 se há hotel, 0 caso não haja;
    int casas; //numero de casas construidas
} localidade ;


localidade* criar_localidade(char*endereco, const char*cor, float custo, float valoraluguel){



}





