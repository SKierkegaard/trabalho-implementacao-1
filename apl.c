#include "cofo.h"
#include <stdio.h>

int main() {
    Cofo *cofo = cofoCreate(3);
    if (cofo == NULL) {
        printf("Não foi possível criar o cofo!\n");

        return 1;
    }

    cofoInsert(cofo, 20);
    cofoInsert(cofo, 2);
    cofoInsert(cofo, 8);

    if (cofoConsult(cofo, 8)) {
        printf("Elemento encontrado!\n");
    } else {
        printf("Elemento não encontrado!\n");
    }

    cofoRemove(cofo, 2);
    if (!cofoDestroy(cofo)) {
        printf("Não foi possível destruir o cofo: o cofo não está vazio.\n");
    }

    cofoRemove(cofo, 20);
    cofoRemove(cofo, 8);

    if (cofoDestroy(cofo)) {
        printf("Cofo destruído com sucesso!\n");
    } 
    cofo = NULL;

    return 0;
}
