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

void push(Pessoa **headp,char *nome);

void conect(Pessoa *headf1,Pessoa *headf2,Pessoa *tailf1, Pessoa *tailf2,Pessoa **headp1);

void printar(Pessoa *head);

void intercale(Pessoa **headp2,Pessoa *headf1, Pessoa *headf2);


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
    printf("fila 1: \n");
    printar(headf1);
    printf("fila 2: \n");
    printar(headf2);
    printf("pilha 1: \n");
    conect(headf1,headf2,tailf1,tailf2,&headp1);
    printar(headp1);
    printf("pilha 2: \n");
    intercale(&headp2,headf1,headf2);
    printar(headp2);
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

void printar(Pessoa *head){
    while(head!=NULL){
        printf("%s\n",head->nome);
        head=head->prox;
    }
}

void push(Pessoa **headp,char *nome){
    Pessoa *new=malloc(sizeof(Pessoa));
    strcpy(new->nome,nome);
    new->prox=*headp;
    *headp=new;
}

void conect(Pessoa *headf1,Pessoa *headf2,Pessoa *tailf1, Pessoa *tailf2,Pessoa **headp1){
    for(int i=0;i<10;i++){
        push(headp1,headf1->nome);
        headf1=headf1->prox;
    }
    for(int i=0;i<10;i++){
        push(headp1,headf2->nome);
        headf2=headf2->prox;
    }
}

void intercale(Pessoa **headp2,Pessoa *headf1, Pessoa *headf2){
    for(int i=0;i<20;i++){
        if(i%2==0){
            push(headp2,headf1->nome);
            headf1=headf1->prox;
        }
        else{
            push(headp2,headf2->nome);
            headf2=headf2->prox;
        }
    }
}
