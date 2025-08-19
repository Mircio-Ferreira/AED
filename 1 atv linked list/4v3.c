/*
04 - Crie uma nova função que permita a inserção de um nó em
 uma determinada posição da lista.
Obs.: essa posição deve ser passada como parâmetro da função.
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int n;
    struct Node *next;
}Node;

void insertRelative(Node **head, int posi , int n){
    if(posi<0) return;
    Node *new =malloc(sizeof(Node));
    new->n=n;
    new->next=NULL;
    
    if(posi == 0){
        new->next=*head;
        *head=new;
        return;
    }
    Node *aux = *head;
}

int main(){



    return 0;
}