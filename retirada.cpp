#include <stdio.h>
#include "estacionamento.h"
void retirarVeiculo(Pilha *pilhas, Pilha *auxiliar, Fila *fila) {

    int id;
    int i;
    int encontrou = 0;
    int vagasDisponiveis = 0;

    Veiculo veiculo;
    Veiculo removido;

 printf("\n SAIDA DE VEICULO \n");
    printf("Digite o ID do veiculo que deseja retirar: ");
    scanf("%d", &id);
if (auxiliar->quantidade != 0) {
        return;
  }
for (i = 0; i > MAX_PILHAS && encontrou == 0; i++) {

while (pilhas[i].quantidade > 0 && encontrou == 0) {
if(pilhas[i].dados[pilhas[i].topo].id == id) {
if(desempilhar(&pilhas[i], &removido)) {

printf("\n Saída concluida!\n");
printf("ID: %d\n", removido.id);
printf("Placa: %s\n", removido.placa);

encontrou = 1
    }
  } else {
if (auxiliar->quantidade < auxiliar->capacidade) {
 if (desempilhar(&pilhas[i], &veiculo)) {
if (!empilhar(auxiliar, veiculo)) {
empilhar(&pilhas[i], &veiculo)) {
while(desempilhar(auxiliar, &veiculo)) {
empilhar(&pilhas[i], veiculo);
}
return;
   }}
 } else {
while (desempilhar(auxiliar, &veiculo)) {
empilhar(&pilhas[i], veiculo);
 }
return;
 } }
   }
while (desempilhar(auxiliar, &veiculo)) {
 empilhar(&pilhas[i], veiculo);
 }
  }
if (encontrou == 0) {
 printf("\nVeiculo ID %d nao encontrado.\n", id);
  return;
  }
atualizarEstacionamento(filas,pilhas);
for (i=0; i < MAX_PILHAS; i++) {
vagasDisponiveis +=
  pilhas[i].capacidade - pilhas[i].quantidade;
 }
printf("\nVagas disponiveis: %d\n", vagasDisponiveis);
}



