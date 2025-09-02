#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int n;
    struct Node *next;
}Node;

void insert(Node **head,Node **tail,int input);

void printList(Node *head);

int main(){

    Node *head=NULL,*tail=NULL;
    int array[]={3,5,1,-4,0,2,4,9,0,-99,2};
    int len=sizeof(array)/sizeof(int);
    for(int i=0;i<len;i++) insert(&head,&tail,array[i]);

    printList(head);
    

    return 0;
}

void insert(Node **head,Node **tail,int input){
    Node *new=malloc(sizeof(Node));
    new->n=input;
    new->next=NULL;
    if(*head==NULL){
        *head=*tail=new;
        return;
    }
    if((*head)->n > input){
        new->next=*head;
        *head=new;
        return;
    }
    if((*tail)->n < input){
        (*tail)->next=new;
        *tail=new;
        return;
    }
    Node *aux=*head;
    while(aux->next!=NULL){
        if(aux->next->n>input){
            new->next=aux->next;
            aux->next=new;
            return;
        }
        aux=aux->next;
    }   
}

void printList(Node *head){
    while(head!=NULL){
        printf("|%d|",head->n);
        head=head->next;
    }
}