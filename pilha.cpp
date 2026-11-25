
#include <stdio.h>
#include <stdlib.h>
#include "estacionamento.h"

int inicializarPilha(Pilha *pilha, int capacidade) {
    pilha->dados = malloc(capacidade * sizeof(Veiculo));

    if (pilha->dados == NULL) {
        return 0;
    }

    pilha->topo = -1;
    pilha->quantidade = 0;
    pilha->capacidade = capacidade;

    return 1;
}

void finalizarPilha(Pilha *pilha) {
    free(pilha->dados);
    pilha->dados = NULL;
}

int empilhar(Pilha *pilha, Veiculo veiculo) {
    if (pilha->quantidade == pilha->capacidade) {
        return 0;
    }

    pilha->topo++;
    pilha->dados[pilha->topo] = veiculo;
    pilha->quantidade++;

    return 1;
}

int desempilhar(Pilha *pilha, Veiculo *veiculo) {
    if (pilha->quantidade == 0) {
        return 0;
    }

    *veiculo = pilha->dados[pilha->topo];
    pilha->topo--;
    pilha->quantidade--;

    return 1;
}

void mostrarEstacionamento(Pilha *pilhas) {
    int i, j;

    for (i = 0; i < MAX_PILHAS; i++) {
        printf("\nPilha %d:\n", i + 1);

        if (pilhas[i].quantidade == 0) {
            printf("Vazia.\n");
            continue;
        }

        for (j = pilhas[i].topo; j >= 0; j--) {
            printf("ID: %d | Placa: %s",
                   pilhas[i].dados[j].id,
                   pilhas[i].dados[j].placa);

            if (j == pilhas[i].topo) {
                printf(" (TOPO)");
            }

            printf("\n");
        }
    }
}

void atualizarEstacionamento(Fila *fila, Pilha *pilhas) {
    Veiculo veiculo;
    int i;

    while (fila->quantidade > 0) {
        int encontrouVaga = 0;

        for (i = 0; i < MAX_PILHAS; i++) {
            if (pilhas[i].quantidade < pilhas[i].capacidade) {
                if (desenfileirar(fila, &veiculo)) {
                    empilhar(&pilhas[i], veiculo);

                    printf("Veiculo %s entrou na pilha %d.\n",
                           veiculo.placa, i + 1);
                }

                encontrouVaga = 1;
                break;
            }
        }

        if (!encontrouVaga) {
            break;
        }
    }
}

int existeVeiculo(Fila *fila, Pilha *pilhas, int id) {
    int i, j;

    for (i = 0; i < fila->quantidade; i++) {
        int posicao = (fila->inicio + i) % fila->capacidade;

        if (fila->dados[posicao].id == id) {
            return 1;
        }
    }

    for (i = 0; i < MAX_PILHAS; i++) {
        for (j = 0; j <= pilhas[i].topo; j++) {
            if (pilhas[i].dados[j].id == id) {
                return 1;
            }
        }
    }

    return 0;
}
