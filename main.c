#include "cofo.h"
#include <stdio.h>

int main() {
    Cofo cofo = {0};
    cofoCreate(&cofo, 3);

    if (cofoInsert(&cofo, 20)) {
        printf("Valor adicionado ao cofo!\n");
    } else {
        printf("Não foi possível adicionar o valor ao cofo!\n");
    }

    if (cofoInsert(&cofo, 2)) {
        printf("Valor adicionado ao cofo!\n");
    } else {
        printf("Não foi possível adicionar o valor ao cofo!\n");
    }

    if (cofoInsert(&cofo, 8)) {
        printf("Valor adicionado ao cofo!\n");
    } else {
        printf("Não foi possível adicionar o valor ao cofo!\n");
    }

    if (cofoConsult(&cofo, 8)) {
        printf("Valor encontrado!\n");
    } else {
        printf("Valor não encontrado!\n");
    }

    if (cofoRemove(&cofo, 2)) {
        printf("Valor removido com sucesso!\n");
    } else {
        printf("Não foi possível remover o valor!\n");
    }

    if (cofoDestroy(&cofo)) {
        printf("Cofo destruído com sucesso\n");
    } else {
        printf("Não foi possível destuir o cofo!\n");
    }

    return 0;
}
