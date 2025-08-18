#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int num;
    struct Node *next;
} Node;

void insertFinish(Node **head,int n);

void pop(Node **head);

int main() {
    Node *head = NULL;

    return 0;
}

void insertFinish(Node **head,int n){
    Node *new=malloc(sizeof(Node));
    new->num= n;
    new->next=NULL;
    Node *aux=*head;

    if(*head==NULL){
        *head=new;
        return;
    }

    while(aux->next!=NULL){
        aux=aux->next;
    }
    aux->next=new;
    
}

void pop(Node **head){
    Node *temp;
    Node *aux=*head;
    if(*head==NULL){
        printf("Lista vazia, nao ha o que remover!");
        return;
    }

    if((*head)->next==NULL){
        temp=*head;
        *head=NULL;
        free(temp);
        return;
    }

    while(aux->next!=NULL){
        if(aux->next->next==NULL){
            temp=aux->next;
            aux->next=aux->next->next;// ou aux->next=NULL;
            free(temp);
            return;
        }
        aux=aux->next;
    }
}