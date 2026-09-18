#ifndef COFO_H
#define COFO_H

#define TAM_MAX 100

typedef struct {
    int lista[TAM_MAX];
    int tamanho;
} Cofo;

void cofoCriar(Cofo *cofo);
int cofoInserir(Cofo *cofo, int valor);
int cofoRemover(Cofo *cofo, int valor);
int cofoConsultar(Cofo *cofo, int valor);
int cofoDestruir(Cofo *cofo);

#endif // !COFO_H
