/*
03 - A partir da Função de Remoção crie uma nova função que 
permita a remoção de um nó no final da lista
(no código disponibilizado a remoção está sendo realizada no início)
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int n;
    struct Node *next;
}Node;

void pop(Node **head){
    if(*head==NULL) {
        printf("Lista VAZIA!");
        return;
    }
    Node *temp,*aux=*head;
    
    while(aux!=NULL){

    }
}

int main(){

    Node *head=NULL;
    
    return 0;
}