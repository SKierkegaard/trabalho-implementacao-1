#include "cofo.h"
#include <stdlib.h>

int cofoCreate(Cofo *cofo, int len) {
    if (cofo->list != NULL) {
        free(cofo->list);
        cofo->list = NULL;
    }

    if (len > 0) {
        cofo->list = malloc(sizeof(int) * len);
        if (cofo->list == NULL) {
            return 0;
        }

        cofo->length = 0;
        cofo->capacity = len;
        return 1;
    }

    return 0;
}

int cofoInsert(Cofo *cofo, int value) {
    if (cofo->list != NULL && cofo->length < cofo->capacity) {
        cofo->list[cofo->length] = value;
        cofo->length++;

        return 1;
    }

    return 0;
}
