#include <stdio.h>
#include <stdlib.h>

typedef struct Node{ 
int valor; 
struct Node *prox; 
struct Node *ant; 
} Node;

//questao 1
void insertWithNotTail(Node **head,int n);

//questao 2
void removeWithNotTail(Node **head);

//questao 3 
void insertionWithTail(Node **head,Node **tail,int n);

//questao 4
void removeWithTail(Node **head,Node **tail);

//extras 
void inserirComeco(Node **head,int n);

void removeComeco(Node **head);

void print(Node *head);

void printInversoWithNotTail(Node *head);

void printInversoWithNotTail(Node *head);

void printInversoWithTail(Node *head,Node *tail);


int main(){

}

//questao 1
void insertWithNotTail(Node **head,int n){
    Node *new=malloc(sizeof(Node));
    new->valor=n;
    new->prox=NULL;
    if(*head == NULL){
        new->ant=NULL;
        *head=new;
    }
    else{
        Node *aux=*head;
        while(aux->prox!=NULL) aux=aux->prox;
        aux->prox=new;
        new->ant=aux;
    }
}
//questao 2
void removeWithNotTail(Node **head){
    if(*head!=NULL){
        if((*head)->prox==NULL){
            free(*head);
            *head=NULL;
        }
        else{
            Node *aux=*head;
            while(aux->prox!=NULL) aux=aux->prox;
            aux->ant->prox=NULL;
            free(aux);
        }
    }
}

//questao 3 
void insertionWithTail(Node **head,Node **tail,int n){
    Node *new=malloc(sizeof(Node));
    new->valor=n;
    new->prox=NULL;
    if(*head==NULL){
        *head=*tail=new;
        new->ant=NULL;
    }
    else{
        (*tail)->prox=new;
        new->ant=*tail;
        *tail=new;
    }
}
//questao 4
void removeWithTail(Node **head,Node **tail){
    if(*head!=NULL){
        Node *remove=*tail;
        *tail=(*tail)->ant;
        if(*tail==NULL) *head=NULL;
        else (*tail)->prox=NULL;
        free(remove);
    }
}

//extras
void inserirComeco(Node **head,int n){
    Node *new=malloc(sizeof(Node));
    new->valor=n;
    new->ant=NULL;
    new->prox=*head;
    if(*head!=NULL) (*head)->ant=new;
    *head=new;
}

void removeComeco(Node **head){
    if(*head!=NULL){
        Node *remove=*head;
        *head=(*head)->prox;
        free(remove);
        if(*head!=NULL) (*head)->ant=NULL;
    }
}

void print(Node *head){
    while(head!=NULL){
        printf("|%d|",head->valor);
        head=head->prox;
    }
    printf("\n");
}

void printInversoWithNotTail(Node *head){
    if(head!=NULL){
        Node *aux=head;
        while(aux->prox!=NULL) aux=aux->prox;
        while(aux!=NULL){
            printf("|%d|",aux->valor);
            aux=aux->ant;
        }
        printf("\n");
    }
}

void printInversoWithTail(Node *head,Node *tail){
    while(tail!=NULL){
        printf("|%d|",tail->valor);
        tail=tail->ant;
    }
    printf("\n");
}