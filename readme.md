# API

## 1 - int cofoCreate

```c
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
```

*cofoCreate retorna NULL para len inválido, falha na alocação do struct Cofo, falha na alocação da lista de inteiros depois de liberar o struct. Caso contrário, aloca o struct Cofo dinamicamente e sua lista de inteiros, 'seta' os campos length e capacity e retorna um ponteiro para o struct Cofo.


## 2 - cofoInsert

```c
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
```

cofoInsert retorna 0 para três casos: ponteiro cofo nulo, cofo não criado/destruído (list == NULL), ou cofo cheio, sem distinguir entre eles, por simplicidade. Caso contrário, adiciona o valor no próximo local válido, incrementa cofo->length e retorna 1.

## 3 - cofoRemove

```c
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


```

cofoRemove retorna 0 para os dois casos: ponteiro cofo nulo, cofo não criado/destruído. Se o cofo e lista forem válidos, a função percorre a lista e remove o primeiro valor igual ao que foi passado como parâmetro, move seus sucessores(se houverem) para à esquerda, decrementa cofo->length e retorna 1.

## 4 - cofoConsult

```c
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
```

cofoConsult retorna 0 para três casos: ponteiro cofo nulo, cofo não criado/destruído e valor não encontrado. Se o cofo e a lista forem válidos, a função percorre a lista e retorna 1 quando encontra um valor igual ao que foi passado como parâmetro.

## 5 - cofoDestroy

```c
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
```

cofoDestroy retorna 0 para três casos: ponteiro cofo nulo, cofo não criado/destruído e se o cofo não estiver vazio. Caso contrário, a memória é liberada e os campos de cofo são 'resetados' e retorna 1.

## Ambiente de execução

- Sistema operacional: Arch Linux(Omarchy)
- Compilador: gcc (GCC) 16.2.1 20260810
- Editor utilizado: Neovim
- - Os arquivos foram compilados para o sistema operacional Arch linux(Omarchy) com gcc (GCC) 16.2.1 20260810, caso não rode:
```bash
gcc -o ./build/cofo main.c cofo.c

./build/cofo
```

O trabalho está disponível no meu github: [trabalho-implementacao-1](https://github.com/SKierkegaard/trabalho-implementacao-1)
