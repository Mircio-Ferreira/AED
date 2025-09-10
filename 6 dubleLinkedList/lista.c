#include <stdio.h>
#include <stdlib.h>

typedef struct Node{ 
int valor; 
struct Node *prox; 
struct Node *ant; 
} Node;

//questao 1
void insertWithNotTail(Node **head,int n);

int main(){
    
    return 0;
}

//questao 1
void insertWithNotTail(Node **head,int n){
    Node *new=malloc(sizeof(Node));
    new->valor=n;
    new->prox=NULL;
    if(*head == NULL){
        new->ant=NULL;
        *head=new;
    }
    else{
        Node *aux=*head;
        while(aux->prox!=NULL) aux=aux->prox;
        aux->prox=new;
        new->ant=aux;
    }
}