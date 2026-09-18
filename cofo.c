#include "cofo.h"
#include <stdlib.h>

void cofoCriar(Cofo *cofo) {
    cofo->tamanho = 0;
}

int cofoInserir(Cofo *cofo, int valor) {
    if (cofo->tamanho < TAM_MAX) {
        cofo->lista[cofo->tamanho] = valor;
        cofo->tamanho++;

        return 1;
    }

    return 0;
}

int cofoRemover(Cofo *cofo, int valor) {
    for (int i = 0; i < cofo->tamanho; i++) {
        if (cofo->lista[i] == valor) {
            for (int j = i; j < cofo->tamanho - 1; j++) {
                cofo->lista[j] = cofo->lista[j + 1];
            }

            cofo->tamanho--;
            return 1;
        }
    }

    return 0;
}

int cofoConsultar(Cofo *cofo, int valor) {
    for (int i = 0; i < cofo->tamanho; i++) {
        if (cofo->lista[i] == valor) {
            return 1;
        }
    }

    return 0;
}

int cofoDestruir(Cofo *cofo) {
    if (cofo->tamanho == 0) {
        cofo->tamanho = -1;
        return 1;
    }

        return 0;
}
