/*
05 - Crie uma nova função que permita a remoção de um elementos em uma determinada posição da lista.

Obs.: essa posição deve ser passada como parâmetro da função.
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int n;
    struct Node *next;
}Node;

void popRelative(Node **head, int posi){
    Node *temp,*aux=*head;
    if(posi < 1 || *head==NULL){
        printf("posi invalida ou lista vazia\n");
        return;
    }
    //remocao no comeco
    if(posi==1){
        temp=*head;
        *head=(*head)->next;
        free(temp);
        return;
    }
    int cont=0;
    while(aux!=NULL) {
        aux=aux->next;
        cont++;
    }
    if(posi > cont){
        printf("posicao invalida, elementos da lista: %d\n",cont);
        return;
    }
    aux=*head;
    cont=1;
    while(cont != posi-1){
        cont++;
        aux=aux->next;
    }
    temp=aux->next;
    aux->next=aux->next->next;
    free(temp);
}

int main(){

    Node *head=NULL;
    
    return 0;
}