#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int n;
    struct Node *next;
}Node;

void inserir(Node **head,int n);

void inserirV2(Node **head,int n);

void remove(Node **head,int ndel);

void print(Node *head);

int main(){

    return 0;
}

void inserir(Node **head,int n){
    Node *new=malloc(sizeof(Node));
    new->n=n;
    new->next=NULL;
    if(*head==NULL) *head=new;
    else{
        if((*head)->n>n){
            new->next=*head;
            *head=new;
            return;
        }
        Node *aux=*head;
        while(aux->next!=NULL && aux->next->n<n) aux=aux->next;
        new->next=aux->next;
        aux->next=new; 
    }
}

void inserirV2(Node **head,int n){

    Node *new=malloc(sizeof(Node));
    new->n=n;
    new->next=NULL;
    if(*head==NULL) *head=new;
    else{
        if((*head)->n>n){
            new->next=*head;
            *head=new;
            return;
        }
        Node *aux=*head;
        while(aux->next!=NULL){
            if(aux->next->n>n) {
                new->next=aux->next;
                aux->next=new; 
                return;
            }
            aux=aux->next;
        }
        aux->next=new;
    }

}

void remove(Node **head,int ndel){
    if(*head!=NULL){
        Node *remove,*aux=*head;
        if((*head)->n==ndel){
            remove=*head;
            *head=(*head)->next;
            free(remove);
            return;
        }
        while(aux->next!=NULL){
            if(aux->next->n==ndel){
                remove=aux->next;
                aux->next=aux->next->next;
                free(remove);
                return;
            }
            aux=aux->next;
        }
    }
}

void print(Node *head){
    while(head!=NULL){
        printf("%d\n",head->n);
        head=head->next;
    }
}