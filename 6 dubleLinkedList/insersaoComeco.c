#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int n;
    struct Node *next;
    struct Node *prev;
}Node;

void insert(Node **head,int n);

void insert2(Node **head,int n);

void print(Node *head);

void printInverso(Node *head);

void remove(Node **head);

int main(){

    Node *head=NULL;
    insert2(&head,1); 
    insert2(&head,2);
    insert2(&head,3);
    insert2(&head,4);
    insert2(&head,5);

    print(head);

    printf("\n");

    printInverso(head);



    return 0;
}

void insert(Node **head,int n){
    Node *new=malloc(sizeof(Node));
    new->n=n;
    new->next=NULL;
    new->prev=NULL;
    if(*head==NULL) *head=new;
    else{
        new->next=*head;
        (*head)->prev=new;
        *head=new;
    }
}

void insert2(Node **head,int n){
    Node *new=malloc(sizeof(Node));
    new->n=n;
    new->prev=NULL;
    new->next=*head;
    if(*head!=NULL) (*head)->prev=new;
    *head=new;
}

void printInverso(Node *head){
    if(head!=NULL){
        Node *aux=head;
        while(aux->next!=NULL) aux=aux->next;
        while(aux!=NULL){
            printf("|%d|",aux->n);
            aux=aux->prev;
        }   
    }
}

void print(Node *head){
    while(head!=NULL){
        printf("|%d|",head->n);
        head=head->next;
    }
}

void remove(Node **head){
    if(*head!=NULL){
        Node *temp=*head;
        *head=(*head)->next;
        free(temp);
        if(*head!=NULL)(*head)->prev=NULL;
    }
}