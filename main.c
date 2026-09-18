#include "cofo.h"
#include <stdio.h>

int main() {
    Cofo cofo;
    cofoCriar(&cofo);
    if (cofoInserir(&cofo, 20)) {
        printf("valor inserido com sucesso!");
    }
    if (cofoInserir(&cofo, 2)) {
        printf("valor inserido com sucesso!");
    }
    if (cofoInserir(&cofo, 8)) {
        printf("valor inserido com sucesso!");
    }
    if (cofoConsultar(&cofo, 8)) {
        printf("o valor está na lista!");
    }
    if (cofoRemover(&cofo, 2)) {
        printf("Valor removido com sucesso");
    }

    if (!cofoConsultar( &cofo, 2)) {
        printf("não encontrei!");
    }
}
