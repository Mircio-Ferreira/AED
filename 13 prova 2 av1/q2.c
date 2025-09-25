#include <stdio.h>
#include <stdlib.h>

/*
QUESTÃO 02 - (2.5 pontos) Considere que um programa em C manipula duas
listas duplamente encadeadas (Lista01 e Lista02) e agora é necessário que seja
implementada uma nova função que realiza a troca do último elemento entre as
listas (o último nó que está na Lista01 vai para a Lista02 E o último nó que estava
na Lista02 vai para a Lista01).
Protótipo da função: void troca(Node **head1, Node **head2);
*/

typedef struct Node{
    int n;
    struct Node *next;
    struct Node *prev;
}Node;

void insert(Node **head,int n);
void print(Node *head);
void swap(Node **head1,Node **head2);

int main(){
    Node *head1=NULL, *head2=NULL;

    insert(&head1,1);
    //insert(&head1,2);
    //insert(&head1,3);
    //insert(&head1,4);
    //insert(&head1,5);
    printf("lista1: ");
    print(head1);

    insert(&head2,6);
    insert(&head2,7);
    //insert(&head2,8);
    //insert(&head2,9);
    //insert(&head2,10);
    printf("lista2: ");
    print(head2);

    
    printf("lista apos swap no final\n");
    swap(&head1,&head2);

    printf("lista1: ");
    print(head1);

    printf("lista2: ");
    print(head2);


    return 0;
}

void insert(Node **head,int n){
    Node *new=malloc(sizeof(Node));
    new->n=n;
    new->next=NULL;
    if(*head==NULL){
        new->prev=NULL;
        *head=new;
    }
    else{
        Node *aux=*head;
        while(aux->next!=NULL) aux=aux->next;
        new->prev=aux;
        aux->next=new;
    }
}

void print(Node *head){
    while(head!=NULL){
        printf("|%d|",head->n);
        head=head->next;
    }
    printf("\n");
}

void swap(Node **head1,Node **head2){
    if(*head1!=NULL && *head2!=NULL){
        Node *aux1=*head1,*aux2=*head2;
        
    }
}