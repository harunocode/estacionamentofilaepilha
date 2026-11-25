#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct nodo{
	char placa[15];
	struct nodo *prox;
};

struct fila{
	struct nodo *inicio;
	struct nodo *fim;
};

struct fila *init(){
	struct fila *temp=(struct fila*)malloc(sizeof(struct fila));
	temp->inicio=NULL;
	temp->fim=NULL;
	return temp;
};

void enqueue(struct fila *desc,char placa[]){
	struct nodo *novo_nodo=(struct nodo*)malloc(sizeof(struct nodo));
	strcpy(novo_nodo->placa,placa);
	novo_nodo->prox=NULL;
	if(desc->inicio==NULL){
		desc->inicio=novo_nodo;
	}
	else{
		desc->fim->prox=novo_nodo;
	}
	desc->fim=novo_nodo;
}

void cadastrar(struct fila *desc){
	char placa[15];
	
	printf("digite sua placa:\n");
	scanf("%s",&placa);
	
	enqueue(desc,placa);
}

void dequeue(struct fila *desc){
	struct nodo *temp;
	if(desc->inicio==NULL){
		printf("erro\n");
		return;
	} 
	else{
		temp=desc->inicio;
	desc->inicio=temp->prox;
	free(temp);
	if(desc->inicio == NULL){
			desc->fim = NULL;
		}
	}
	
}

void listar(struct fila *desc){
	struct nodo *temp=desc->inicio;
	printf("esta e a fila\n");
	while(temp!=NULL){
		printf("%s\n",temp->placa);
		temp=temp->prox;
	}
}
int main (){
	struct fila *fila;
	fila=init();
	
	int i;
	for(i=0;i<5;i++){
		cadastrar(fila);
	}
	
	listar(fila);
	
	
	
	
	
}


