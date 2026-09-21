#include <stdio.h>
#include "cofo.h"

void cleanBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    int capacity;
    printf("Digite a capacidade do Cofo: ");
    scanf("%d", &capacity);
    cleanBuffer();

    Cofo *cofo = cofoCreate(capacity);
    if (cofo == NULL) {
        printf("Não foi possível criar o Cofo!\n");
        return 1;
    }

    int option;
    int value;
    int running = 1;

    while (running) {
        printf("\n#------- Menu Cofo -------#\n");
        printf("| 1 - Inserir valor       |\n");
        printf("| 2 - Remover valor       |\n");
        printf("| 3 - Consultar valor     |\n");
        printf("| 4 - Destruir Cofo(Sair) |\n");
        printf("#-------------------------#\n");
        printf("> ");

        if (scanf("%d", &option) != 1) {
            printf("Entrada inválida.\n");
            cleanBuffer();
            continue;
        }
        cleanBuffer();

        switch (option) {
            case 1:
                printf("\nDigite o valor a inserir: ");
                scanf("%d", &value);
                cleanBuffer();

                if (cofoInsert(cofo, value)) {
                    printf("Valor inserido com sucesso!\n");
                } else {
                    printf("Não foi possível inserir o valor(cofo cheio ou valor inválido)!\n");
                }
                break;

            case 2:
                printf("\nDigite o valor a remover: ");
                scanf("%d", &value);
                cleanBuffer();

                if (cofoRemove(cofo, value)) {
                    printf("Valor removido com sucesso!\n");
                } else {
                    printf("Valor não encontrado!\n");
                }
                break;

            case 3:
                printf("\nDigite o valor a consultar: ");
                scanf("%d", &value);
                cleanBuffer();

                if (cofoConsult(cofo, value)) {
                    printf("Valor encontrado!\n");
                } else {
                    printf("Valor não encontrado\n");
                }
                break;

            case 4:
                if (cofoDestroy(cofo)) {
                    printf("\nCofo destruído com sucesso!\n");
                    cofo = NULL;
                    running = 0;
                } else {
                    printf("\nNão foi possível destruir o Cofo! O Cofo não está vazio.\n");
                }
                break;

            default:
                printf("\nOpção inválida\n");
        }
    }

    return 0;
}
