/*
01 - Um determinado programa será implementado em C e deve permitir manipular números inteiros em uma pilha, implemente as seguintes funcionalidades para o programa:

a) Inserir novos elementos;

b) Imprimir a base da pilha;


c) Imprimir o topo da pilha;



d) Remover um nó da pilha;

e) Imprimir todos os nós na posição par.

*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int n;
    struct Node *next;
}Node;

void push(Node **head, int input);

void pop(Node **head);

void printBase(Node *head);

void printTop(Node *head);

void printParPosition(Node *head);

int main(){

    Node *head=NULL;
    int comand;

    while(1){
        printf("1 inserir\n2 imprimir base da pilha\n3 imprimir topo da pilha\n4 remover um no da pilha\n5 imprimir todos os nos na posicao par\n6 Sair\n");
        printf("digite comando: ");
        scanf(" %d",&comand);

        if(comand==1){
            int input;
            scanf(" %d",&input);
            push(&head,input);
        }
        else if(comand==2) printBase(head);
        else if(comand==3) printTop(head);
        else if(comand==4) pop(&head);
        else if(comand==5) printParPosition(head);
        else if(comand==6) break;
        else printf("\nComando invalido tente novamente!\n\n");
    }

    return 0;
}

void push(Node **head, int input){
    Node *new=malloc(sizeof(Node));
    if(new!=NULL){
        new->n=input;
        new->next=*head;
        *head=new;
    }
}

void pop(Node **head){
    if(*head!=NULL){
        Node *temp=*head;
        *head=(*head)->next;
        free(temp);
    }
}

void printBase(Node *head){
    while(head!=NULL){
        if(head->next==NULL) printf("\nBase: %d\n",head->n);
        head=head->next;
    }
}

void printTop(Node *head){
    if(head!=NULL) printf("\nPrimeiro :%d\n",head->n);
    else printf("\n\nLista vazia\n");
}

void printParPosition(Node *head){
    int cont=0;
    while(head!=NULL){
        if(cont%2==0) printf("\npar: %d\n",head->n);
        cont++;
        head=head->next;
    }
}