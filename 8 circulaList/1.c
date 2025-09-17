#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int n;
    struct Node *next;
}Node;

void insertBeging(Node **head,Node **tail,int n);

void print(Node *head,Node *tail);

int len(Node *head,Node *tail);

void removeBeging(Node **head,Node **tail);

int main(){

     Node *head=NULL,*tail=NULL;


    return 0;
}

void insertBeging(Node **head,Node **tail,int n){

    Node *new=malloc(sizeof(Node));
    new->n=n;

    if(*head==NULL){
        *head=*tail=new;
        (*tail)->next=*head;
    }
    else{
        new->next=*head;
        *head=new;
        (*tail)->next=*head;
    }

}

void print(Node *head,Node *tail){
    if(head!=NULL){
        Node *aux=head;
        do{
            printf("%d",aux->n);
            aux=aux->next;

        }while(aux!=head);
    }
}

int len(Node *head,Node *tail){
    int len=0;
    if(head!=NULL){
        Node *aux=head;
        do{
            len++;
            aux=aux->next;
        }while(aux!=head);
    }

    return len;
}

void removeBeging(Node **head,Node **tail){
    if(*head!=NULL){
        Node *remove=*head;
        if(*head==*tail) *head=*tail=NULL;
        else{
            *head=(*head)->next;
            (*tail)->next=*head;
        }
        free(remove);
    }
}