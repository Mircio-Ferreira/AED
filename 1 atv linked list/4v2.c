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

void relativeInsert(Node **head, int posi, int n){
    // obs: estou supondo que a posi inicial é 1!
    if(posi < 1){
        printf("posicao invalida apenas numeros maiores ou iguais a 1\n");
        return;
    }
    Node *new=malloc(sizeof(Node));
    new->n=n;
    // basicamente insersao no comeco
    if(posi == 1){
        new->next=*head;
        *head=new;
        return;
    }
    Node *aux=*head;
    int cont=0;
    while(aux!=NULL){
        cont++;
        aux=aux->next;
    }
    if(posi > cont+1){
        printf("posicao invalida, lista de tamanho: %d, posicao maxima aceita %d\n",cont,cont+1);
        free(new);
    }
    else{
        aux=*head;
        cont=1;
        while(cont < posi-1){
            aux=aux->next;
            cont++;
        }
        new->next=aux->next;
        aux->next=new;
    }
    
}

int main(){

    return 0;
}