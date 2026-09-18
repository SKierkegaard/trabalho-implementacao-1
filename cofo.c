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
