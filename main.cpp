
#include <stdio.h>
#include <stdlib.h>
#include "estacionamento.h"

int main() {
    Fila fila;
    Pilha *pilhas;
    Pilha auxiliar;
    int i;
    int opcao;

    if (!inicializarFila(&fila, MAX_FILA)) {
        printf("Erro ao alocar memoria para a fila.\n");
        return 1;
    }

    pilhas = calloc(MAX_PILHAS, sizeof(Pilha));

    if (pilhas == NULL) {
        printf("Erro ao alocar memoria para as pilhas.\n");
        finalizarFila(&fila);
        return 1;
    }

    for (i = 0; i < MAX_PILHAS; i++) {
        if (!inicializarPilha(&pilhas[i], MAX_VAGAS)) {
            printf("Erro ao alocar memoria para a pilha.\n");

            while (i > 0) {
                i--;
                finalizarPilha(&pilhas[i]);
            }

            free(pilhas);
            finalizarFila(&fila);
            return 1;
        }
    }

    if (!inicializarPilha(&auxiliar, MAX_VAGAS)) {
        printf("Erro ao alocar memoria para a pilha auxiliar.\n");

        for (i = 0; i < MAX_PILHAS; i++) {
            finalizarPilha(&pilhas[i]);
        }

        free(pilhas);
        finalizarFila(&fila);
        return 1;
    }

    do {
        printf("\n===== SISTEMA DE ESTACIONAMENTO =====\n");
        printf("1 - Registrar entrada de veiculo\n");
        printf("2 - Mostrar fila de espera\n");
        printf("3 - Mostrar estacionamento\n");
        printf("4 - Retirar veiculo\n");
        printf("5 - Consultar veiculo\n");
        printf("0 - Encerrar sistema\n");
        printf("Escolha uma opcao: ");

        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                registrarVeiculo(&fila, pilhas);
                break;

            case 2:
                mostrarFila(&fila);
                break;

            case 3:
                mostrarEstacionamento(pilhas);
                break;

            case 4:
                retirarVeiculo(pilhas, &auxiliar, &fila);
                break;

            case 5:
                consultarVeiculo(&fila, pilhas);
                break;

            case 0:
                printf("Encerrando sistema...\n");
                break;

            default:
                printf("Opcao invalida.\n");
        }

    } while (opcao != 0);

    finalizarFila(&fila);

    for (i = 0; i < MAX_PILHAS; i++) {
        finalizarPilha(&pilhas[i]);
    }

    finalizarPilha(&auxiliar);
    free(pilhas);

    return 0;
}
