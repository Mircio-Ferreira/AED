/* 
02 - A partir da Função de Inserção crie uma nova função que permita a 
inserção de um novo nó no final da lista
 (no código disponibilizado a inserção está sendo realizada no início)
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int n;
    struct Node *next;
}Node;

void insertEnd(Node **head,int nEnter){
    Node *new=malloc(sizeof(Node));
    new->n=nEnter;
    new->next=NULL;
    
    if(*head==NULL){
        *head=new;
        return;
    }
    Node *aux=*head;
    while(aux->next!=NULL){
        aux=aux->next;
    }
    aux->next=new;
}

int main(){

    

    return 0;
}