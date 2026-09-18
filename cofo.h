#ifndef COFO_H
#define COFO_H

typedef struct Cofo Cofo;

Cofo *cofoCreate(int len);
int cofoInsert(Cofo *cofo, int value);
int cofoRemove(Cofo *cofo, int value);
int cofoConsult(Cofo *cofo, int value);
int cofoDestroy(Cofo *cofo);

#endif
