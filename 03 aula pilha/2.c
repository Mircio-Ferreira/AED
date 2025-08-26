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

void intercalePushWithqueue(Pessoa *headF1,Pessoa *headF2,Pessoa **headPilh1);

void interleaveQueuesToStack(Pessoa *headF1,Pessoa *headF2,Pessoa **headPilha2);

void printPessoa(Pessoa *head);

int main(){
    Pessoa *headFila1=NULL, *headFila2=NULL, *headPilha1=NULL, *headPilha2=NULL;
    Pessoa *tailFila1=NULL, *tailFila2=NULL;
    char name[30];
    
    printf("insira da fila1\n");
    for(int i=0;i<10;i++){
        scanf(" %s",name);
        enqueue(&headFila1,&tailFila1,name);
    }

    printf("insira da fila2\n");
    for(int i=0;i<10;i++){
    scanf(" %s",name);
    enqueue(&headFila2,&tailFila2,name);
    }

    intercalePushWithqueue(headFila1,headFila2,&headPilha1);
    interleaveQueuesToStack(headFila1,headFila2,&headPilha2);

    printf("fila1: \n");
    printPessoa(headFila1);

    printf("fila2: \n");
    printPessoa(headFila2);

    printf("pilha1: \n");
    printPessoa(headPilha1);

    printf("pilha2: \n");
    printPessoa(headPilha2);
    

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

void intercalePushWithqueue(Pessoa *headF1,Pessoa *headF2,Pessoa **headPilh1){
    while(headF1!=NULL){
        Pessoa *new=malloc(sizeof(Pessoa));
        strcpy(new->name,headF1->name);
        new->prox=*headPilh1;
        *headPilh1=new;
        headF1=headF1->prox;
    }
    while(headF2!=NULL){
        Pessoa *new=malloc(sizeof(Pessoa));
        strcpy(new->name,headF2->name);
        new->prox=*headPilh1;
        *headPilh1=new;
        headF2=headF2->prox;
    }
}

void interleaveQueuesToStack(Pessoa *headF1,Pessoa *headF2,Pessoa **headPilha2){
    int flag=1;
    while(headF1!=headF2){
        //if(headF1==headF2) break; //Basicamente quandos ambas forem 
        if(headF1!=NULL && flag){
            Pessoa *new=malloc(sizeof(Pessoa));
            strcpy(new->name,headF1->name);
            new->prox=*headPilha2;
            *headPilha2=new;
            headF1=headF1->prox;
        }
        else if(headF2!=NULL && flag==0){
            Pessoa *new=malloc(sizeof(Pessoa));
            strcpy(new->name,headF2->name);
            new->prox=*headPilha2;
            *headPilha2=new;
            headF2=headF2->prox;
        }
        if(flag==1 && headF2!=NULL) flag=0;
        else if(flag==0 && headF1!=NULL) flag=1;
    }
}

void printPessoa(Pessoa *head){
    int cont=0;
    printf("\n\n");
    while(head!=NULL){
        printf("[%d] %s\n",cont,head->name);
        cont++;
        head=head->prox;
    }
}