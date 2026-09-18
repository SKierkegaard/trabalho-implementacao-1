# API

## 1 - int cofoCreate

- Assume-se como premissa que Cofo é zerada antes da primeira chamada de cofoCreate.
ex: Cofo cofo = {0};

```c
int cofoCreate(Cofo *cofo, int len) {
    if (cofo->list != NULL) {
        free(cofo->list);
        cofo->list = NULL;
    }

    if (len > 0) {
        cofo->list = (int *) malloc(sizeof(int) * len);
        if (cofo->list == NULL) {
            return 0;
        }

        cofo->length = 0;
        cofo->capacity = len;
        return 1;
    }

    return 0;
}
```

Como Cofo foi inicializado com todos os campos zerados, free(cofo->list) não é *undefined behavior*, além disso, evita que haja vazamento de memória se cofoCreate for chamado duas vezes para um mesmo cofo.

"cofo->list = NULL" evita o seguinte cenário:

```c 
Cofo cofo = {0};
cofoCreate(&cofo, 10); // sucesso
cofoCreate(&cofo, -5);
```

A memória é liberada, porém len > 0 é falso e a função retorna 0, mas cofo->list continua apontando para memória que foi liberada e não é mais dele.

Após essas checagens, é alocado dinamicamente um vetor de inteiros de tamanho len, cofo->length e cofo->capacity são atualizados, retornando 1 no final.

## 2 - cofoInsert

```c
int cofoInsert(Cofo *cofo, int value) {
    if (cofo->list != NULL && cofo->length < cofo->capacity) {
        cofo->list[cofo->length] = value;
        cofo->length++;

        return 1;
    }

    return 0;
}
```

cofoInsert retorna 0 tanto para o caso de cofo não criado/destruído quanto para cofo cheio para fins de simplicidade. Caso contraŕio, adiciona o valor no próximo local válido, incrementa cofo->length e retorna 1.

## 3 - cofoRemove

```c
int cofoRemove(Cofo *cofo, int value) {
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

    return 0;
}
```

cofoRemove retorna 0 tanto para o caso de cofo não criado/destruído quanto para item não encontrado. Se a lista é válida, a função percorre a lista e remove o primeiro valor igual ao que foi passado como parâmetro, move seus sucessores(se houverem) para à esquerda, decrementa cofo->length e retorna 1.

## 4 - cofoConsult

```c
int cofoConsult(Cofo *cofo, int value) {
    if (cofo->list != NULL) {
        for (int i = 0; i < cofo->length; i++) {
            if (cofo->list[i] == value) {
                return 1;
            }
        }
    }

    return 0;
}
```

cofoConsult retorna 0 tanto para cofo não criado/destruído quanto para item não encontrado. Se a lista é válida, a função percorre a lista e retorna 1 quando encontra um valor igual ao que foi passado como parâmetro.

## 5 - cofoDestroy

```c
int cofoDestroy(Cofo *cofo) {
    if (cofo->list != NULL && cofo->length == 0) {
        free(cofo->list);
        cofo->list = NULL;
        cofo->capacity = 0;

        return 1;
    }

    return 0;
}
```

cofoDestroy retorna 0 tanto para o caso de cofo não criado/destruído quanto para cofo não vazio. Se o cofo estiver vazio, a memória é liberada e os campos de cofo são 'resetados' e retorna 1.

## Ambiente de execução

- Sistema operacional: Arch Linux(Omarchy)
- Compilador: gcc (GCC) 16.2.1 20260810
- Editor utilizado: Neovim
- - Os arquivos foram compilados para o sistema operacional Arch linux(Omarchy) com gcc (GCC) 16.2.1 20260810, caso não rode:
```bash
gcc -o ./build/cofo main.c cofo.c cofo.h main.c

./build/cofo
```

O trabalho está disponível no meu github: (trabalho-implementacao-1)[https://github.com/SKierkegaard/trabalho-implementacao-1]
