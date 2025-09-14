#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int n;
    struct Node *prev;
    struct Node *next;
}Node;

void insertBeging(Node **head,int n);

void inserEnd(Node **head,int n);

void print(Node *head);

void printInverse(Node *head);

void removeBeging(Node **head);

void removeEnd(Node **head);

void insertSort(Node **head,int n);

void insertRelative(Node **head,int n, int posi);

int main(){

    Node *head=NULL;

    // insertBeging(&head,1);
    // insertBeging(&head,2);
    // insertBeging(&head,3);
    // insertBeging(&head,4);
    // insertBeging(&head,5);
    // inserEnd(&head,100);
    // inserEnd(&head,200);
    // insertBeging(&head,6);
    // removeBeging(&head);
    // removeEnd(&head);
    insertSort(&head,9);
    insertSort(&head,1);
    insertSort(&head,300);
    insertSort(&head,-1);
    insertSort(&head,105);
    insertRelative(&head,999,0);
    insertRelative(&head,1000,100);
    insertRelative(&head,978,1);
    insertRelative(&head,-12023232,7);










    print(head);
    printf("\n");
    printInverse(head);



    return 0;
}

void insertBeging(Node **head,int n){
    Node *new=malloc(sizeof(Node));
    new->n=n;
    new->prev=NULL;
    new->next=*head;
    if(*head!=NULL) (*head)->prev=new;
    *head=new;
}

void print(Node *head){
    while(head!=NULL){
        printf("|%d|",head->n);
        head=head->next;
    }
}

void inserEnd(Node **head,int n){
    Node *new=malloc(sizeof(Node));
    new->n=n;
    new->next=NULL;
    if(*head==NULL){
        new->prev=NULL;
        *head=new;
    }
    else{
        Node *aux=*head;
        while(aux->next!=NULL){
            aux=aux->next;
        }
        aux->next=new;
        new->prev=aux;
    }
}

void printInverse(Node *head){
    if(head!=NULL){
        Node *aux=head;
        while(aux->next!=NULL) aux=aux->next;
        while(aux!=NULL){
            printf("|%d|",aux->n);
            aux=aux->prev;
        }
    }
}

void removeBeging(Node **head){
    if(*head!=NULL){
        Node *remove=*head;
        *head=(*head)->next;
        if(*head!=NULL) (*head)->prev=NULL;
        free(remove);
    }
}

void removeEnd(Node **head){
    if(*head!=NULL){
        if((*head)->next==NULL){
            Node *remove=*head;
            free(remove);
            *head=NULL;
        }
        else{
        Node *aux=*head;
        while(aux->next!=NULL) aux=aux->next;
        aux->prev->next=NULL;
        free(aux);
        }
        
    }
}

void insertSort(Node **head,int n){
    Node *new=malloc(sizeof(Node));
    new->n=n;
    if(*head==NULL){
        new->next=NULL;
        new->prev=NULL;
        *head=new;
    }
    else if(new->n < (*head)->n){
        new->next=*head;
        new->prev=NULL;
        (*head)->prev=new;
        *head=new;
    }
    else{
        Node *aux=*head;
        while(aux->next!=NULL && aux->next->n < n){
            aux=aux->next;
        }
        new->next=aux->next;
        new->prev=aux;
        if(aux->next!=NULL) aux->next->prev=new;
        aux->next=new;
    }
}

void insertRelative(Node **head,int n, int posi){
    Node *new=malloc(sizeof(Node));
    new->n=n;
    Node *aux=*head;
    int len=0;
    while(aux!=NULL){
        aux=aux->next;
        len++;
    }
    if(posi<=0){
        new->prev=NULL;
        new->next=*head;
        if(*head!=NULL) (*head)->prev=new;
        *head=new;
    }
    else{
        aux=*head;
        int cont=0;
        while(aux->next!=NULL && cont < posi-1) {
            aux=aux->next;
            cont++;
        }
        new->next=aux->next;
        new->prev=aux;
        if(aux->next!=NULL) aux->next->prev=new;
        aux->next=new;
    }
}