#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int n;
    struct Node *next;
    struct Node *prev;
}Node;

void insertBeginingNotTail(Node **head,int n);
void inserteEndNotTail(Node **head,int n);

void print(Node *head);
void printReverse(Node *head);

int main(){
    Node *head=NULL;

    //insertBeginingNotTail(&head,5);
    //insertBeginingNotTail(&head,4);
    //insertBeginingNotTail(&head,3);
    //insertBeginingNotTail(&head,2);
    //insertBeginingNotTail(&head,1);
    //inserteEndNotTail(&head,1);
    //inserteEndNotTail(&head,2);
    //inserteEndNotTail(&head,3);
    //inserteEndNotTail(&head,4);
    //inserteEndNotTail(&head,5);
    print(head);
    printReverse(head);
    return 0;
}

void insertBeginingNotTail(Node **head,int n){
    Node *new=malloc(sizeof(Node));
    if(new==NULL) return;
    new->n=n;
    new->prev=NULL;
    new->next=*head;
    if(*head!=NULL) (*head)->prev=new;
    *head=new;
}
void inserteEndNotTail(Node **head,int n){
    Node *new=malloc(sizeof(Node));
    if(new==NULL) return;
    new->n=n;
    new->next=NULL;
    if(*head==NULL){
        *head=new;
        new->prev=NULL;
    }
    else{
        Node *aux=*head;
        while(aux->next!=NULL) aux=aux->next;
        aux->next=new;
        new->prev=aux;
    }
    
}

void print(Node *head){
    while(head!=NULL){
        printf("|%d|",head->n);
        head=head->next;
    }
    printf("\n");
}
void printReverse(Node *head){
    if(head!=NULL){
        while(head->next!=NULL) head=head->next;
        while(head!=NULL){
            printf("|%d|",head->n);
            head=head->prev;
        }
        printf("\n");
    }
}