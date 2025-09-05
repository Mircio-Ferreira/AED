/*
a) Crie duas filas (FL1, FL2) e duas pilhas (PL1,  PL2);

b)  Insira nas filas FL1 e FL2 10 nós (em cada uma delas);

c) Concatene as filas FL1 e FL2, armazenando o resultado na Pilha PL1;


d) Intercale as filas FL1 e FL2, armazenando o resultado na Pilha PL2;


e) Exiba todos os itens das estruturas: FL1, FL2, PL1 e  PL2 .

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Pessoa{  
    char nome[30]; 
    struct  Pessoa *prox;
}Pessoa ;

void enqueue(Pessoa **head,Pessoa **tail,char *nome);


int main(){
    Pessoa *headf1=NULL,*headf2=NULL,*tailf1=NULL,*tailf2=NULL;
    Pessoa *headp1=NULL,*headp2=NULL;
    char nome[30];
    printf("Fila 1\n");
    for(int i=0;i<10;i++){
        scanf("%s",nome);
        enqueue(&headf1,&tailf1,nome);
    }
    printf("Fila 2\n");
    for(int i=0;i<10;i++){
        scanf("%s",nome);
        enqueue(&headf2,&tailf2,nome);
    }
    return 0;
}

void enqueue(Pessoa **head,Pessoa **tail,char *nome){
    Pessoa *new=malloc(sizeof(Pessoa));
    new->prox=NULL;
    strcpy(new->nome,nome);
    if(*head==NULL) *head=*tail=new;
    else{
        (*tail)->prox=new;
        *tail=new;
    }
}