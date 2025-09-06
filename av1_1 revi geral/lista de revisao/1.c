/*
QUESTÃO 01 - Revise a implementação das funções a seguir para as Listas
Simplesmente Encadeadas:
● Inserção (Início/Final/Meio) , Remoção (Início/Final/Meio) e Impressão
■ OBS.: Não utilize Tail.
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int n;
    struct Node *next;
}Node;

void insertSortl(Node **head,int n);

void printList(Node *head);

void removeRelative(Node **head,int del);

int main(){

    Node *head=NULL;

    insertSortl(&head,3);
    insertSortl(&head,2);
    insertSortl(&head,-2);
    insertSortl(&head,0);
    insertSortl(&head,100);
    printList(head);
    removeRelative(&head,99);
    printList(head);
    removeRelative(&head,0);
    printList(head);
    removeRelative(&head,-2);
    printList(head);
    removeRelative(&head,100);
    printList(head);
    return 0;
}

void insertSortl(Node **head,int n){
    Node *new=malloc(sizeof(Node));
    new->n=n;
    new->next=NULL;
    if(*head==NULL) *head=new;
    else if((*head)->n > n){
        new->next=*head;
        *head=new;
    }
    else{
        Node *aux=*head;
        /*
        while(aux->next!=NULL){
            if(aux->next->n > n){
                new->next=aux->next;
                aux->next=new;
                return;
            }
            aux=aux->next;
        }
        aux->next=new;        
        */
       while(aux->next!=NULL && (aux->next->n < n)) aux=aux->next;
       new->next=aux->next;
       aux->next=new;
    }
}

void printList(Node *head){
    printf("lista: ");
    while(head!=NULL){
        printf("|%d|",head->n);
        head=head->next;
    }
    printf("\n");
}

void removeRelative(Node **head,int del){
    if(*head==NULL) return;
    if((*head)->n == del){
        Node *remove=*head;
        *head=(*head)->next;
        free(remove);
    }
    else{
        Node *remove,*aux=*head;
        while(aux->next!=NULL){
            if(aux->next->n==del){
                remove=aux->next;
                aux->next=aux->next->next;
                free(remove);
                return;
            }
            aux=aux->next;
        }
    }
}