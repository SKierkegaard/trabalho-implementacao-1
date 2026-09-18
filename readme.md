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
