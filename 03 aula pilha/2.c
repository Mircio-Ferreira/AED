/*
02 - Escreva um programa em C que manipule nomes em estruturas de dados, realizando as seguintes tarefas:

a) Crie duas filas (FL1, FL2) e duas pilhas (PL1,  PL2);

b)  Insira nas filas FL1 e FL2 10 nós (em cada uma delas);

c) Concatene as filas FL1 e FL2, armazenando o resultado na Pilha PL1;


d) Intercale as filas FL1 e FL2, armazenando o resultado na Pilha PL2;


e) Exiba todos os itens das estruturas: FL1, FL2, PL1 e  PL2 .

**Como struct considere: 

typedef struct Pessoa {  char nome[30]; 
                            struct  Pessoa *prox; }   Pessoa ;
                            */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Pessoa{
    char name[30];
    struct Pessoa *prox;
}Pessoa;

void enqueue(Pessoa **head,Pessoa **tail,char *nameInput);

int main(){
    Pessoa *headFila1=NULL, *headFilla2=NULL, *headPilha=NULL, *headPilha2=NULL;
    Pessoa *tailFila1=NULL, *tailFila2=NULL;
    int input;
    
    printf("insira da fila1\n");

    for(int i=0;i<10;i++){

    }
    

    return 0;
}

void enqueue(Pessoa **head,Pessoa **tail,char *nameInput){
    Pessoa *new=malloc(sizeof(Pessoa));
    strcpy(new->name,nameInput);
    new->prox=NULL;
    if(*head==NULL) *head=*tail=new;
    else{
        (*tail)->prox=new;
        *tail=new;
    }
}
