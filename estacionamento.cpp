
#ifndef ESTACIONAMENTO_H
#define ESTACIONAMENTO_H

#define MAX_PILHAS 5
#define MAX_VAGAS 10
#define MAX_FILA 100

typedef struct {
    int id;
    char placa[10];
} Veiculo;

typedef struct {
    Veiculo *dados;
    int inicio;
    int fim;
    int quantidade;
    int capacidade;
} Fila;

typedef struct {
    Veiculo *dados;
    int topo;
    int quantidade;
    int capacidade;
} Pilha;

int inicializarFila(Fila *fila, int capacidade);
void finalizarFila(Fila *fila);
int enfileirar(Fila *fila, Veiculo veiculo);
int desenfileirar(Fila *fila, Veiculo *veiculo);
void mostrarFila(Fila *fila);

int inicializarPilha(Pilha *pilha, int capacidade);
void finalizarPilha(Pilha *pilha);
int empilhar(Pilha *pilha, Veiculo veiculo);
int desempilhar(Pilha *pilha, Veiculo *veiculo);
void mostrarEstacionamento(Pilha *pilhas);

int existeVeiculo(Fila *fila, Pilha *pilhas, int id);
void registrarVeiculo(Fila *fila, Pilha *pilhas);
void atualizarEstacionamento(Fila *fila, Pilha *pilhas);
void retirarVeiculo(Pilha *pilhas, Pilha *auxiliar, Fila *fila);
void consultarVeiculo(Fila *fila, Pilha *pilhas);

#endif
