#ifndef COFO_H
#define COFO_H

#define TAM_MAX 100

typedef struct {
    int *list;
    int length;
    int capacity;
} Cofo;

int cofoCreate(Cofo *cofo, int len);
int cofoInsert(Cofo *cofo, int value);

#endif // !COFO_H
