#include "cofo.h"
#include <stdlib.h>

struct Cofo {
    int *list;
    int length;
    int capacity;
};

Cofo *cofoCreate(int len) {
    if (len <= 0) {
        return  NULL;
    }

    Cofo *cofo = malloc(sizeof(Cofo));
    if (cofo == NULL) {
        return NULL;
    }

    cofo->list = malloc(sizeof(int) * len);
    if (cofo->list == NULL) {
        free(cofo);
        return NULL;
    }

    cofo->length = 0;
    cofo->capacity = len;

    return cofo;
}

int cofoInsert(Cofo *cofo, int value) {
    if (cofo != NULL) {
        if (cofo->list != NULL && cofo->length < cofo->capacity) {
            cofo->list[cofo->length] = value;
            cofo->length++;

            return 1;
        }
    }

    return 0;
}

int cofoRemove(Cofo *cofo, int value) {
    if (cofo != NULL) {
        if (cofo->list != NULL) {
            for (int i = 0; i < cofo->length; i++) {
                if (cofo->list[i] == value) {
                    for (int j = i; j < cofo->length - 1; j++) {
                        cofo->list[j] = cofo->list[j + 1];
                    }

                    cofo->length--;
                    return 1;
                }
            }
        }
    }

    return 0;
}

int cofoConsult(Cofo *cofo, int value) {
    if (cofo != NULL) {
        if (cofo->list != NULL) {
            for (int i = 0; i < cofo->length; i++) {
                if (cofo->list[i] == value) {
                    return 1;
                }
            }
        }
    }

    return 0;
}

int cofoDestroy(Cofo *cofo) {
    if (cofo != NULL) {
        if (cofo->list != NULL && cofo->length == 0) {
            free(cofo->list);
            free(cofo);

            return 1;
        }
    }

    return 0;
}
