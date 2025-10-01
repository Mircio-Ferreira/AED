#include <stdio.h>
#include <stdlib.h>

// Lista duplamente encadeada circular

typedef struct Node{
    int n;
    struct Node *next;
    struct Node *prev;
}Node;

void insetBeging(Node **head,Node **tail,int n);
void insertFinish(Node **head,Node **tail,int n);

void removeBeging(Node **head,Node **tail);
void removeFinish(Node **head,Node **tail);

void print(Node *head,Node *tail);
void printReverso(Node *head,Node *tail);

int main(){

    Node *head=NULL,*tail=NULL;

    for(int i=0;i<5;i++) insertFinish(&head,&tail,i);
    print(head,tail);
    printReverso(head,tail);

    removeBeging(&head,&tail);

    print(head,tail);
    printReverso(head,tail);

    removeFinish(&head,&tail);

    print(head,tail);
    printReverso(head,tail);

    return 0;
}

void insetBeging(Node **head,Node **tail,int n){
    Node *new=malloc(sizeof(Node));
    new->n=n;
    if(*head==NULL) *head=*tail=new->next=new->prev=new;
    else{
        new->next=*head;
        (*head)->prev=new;
        *head=new;
        (*head)->prev=*tail;
        (*tail)->next=*head;
    }
}
void insertFinish(Node **head,Node **tail,int n){
    Node *new=malloc(sizeof(Node));
    new->n=n;
    if(*head==NULL) *head=*tail=new->next=new->prev=new;
    else{
        (*tail)->next=new;
        new->prev=*tail;
        *tail=new;
        (*tail)->next=*head;
        (*head)->prev=*tail;
    }
}

void removeBeging(Node **head,Node **tail){
    if(*head!=NULL){
        Node *remove=*head;
        if(*head==*tail) *head=*tail=NULL;
        else{
            *head=(*head)->next;
            (*head)->prev=*tail;
            (*tail)->next=*head;
        }
        free(head);
    }
}
void removeFinish(Node **head,Node **tail){
    if(*head!=NULL){
        Node *remove=*tail;
        if(*head==*tail) *head=*tail=NULL;
        else{
            *tail=(*tail)->prev;
            (*tail)->next=*head;
            (*head)->prev=*tail;
        }
        free(remove);
    }
}

void print(Node *head,Node *tail){
    if(head!=NULL){
        Node *aux=head;
        do{
            printf("|%d|",aux->n);
            aux=aux->next;
        }while(aux!=head);
        printf("\n");
    }
}
void printReverso(Node *head,Node *tail){
    if(head!=NULL){
        Node *aux=tail;
        do{
            printf("|%d|",aux->n);
            aux=aux->prev;
        }while(aux!=tail);
        printf("\n");
    }
}