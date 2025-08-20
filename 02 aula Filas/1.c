#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int n;
    struct Node *next;
}Node;

void enqueue(Node **head,Node **tail,int num);

void dequeue(Node **head,Node **tail);

void printfEnqueue(Node *head);

int main(){
    Node *head=NULL,*tail=NULL;
    return 0;
}

void enqueue(Node **head,Node **tail,int num){
    Node *new=malloc(sizeof(Node));
    new->n=num;
    new->next=NULL;

    if(*head==NULL){
        *head=*tail=new;
    }
    else{
        (*tail)->next=new;
        *tail=new;
    }
}

void dequeue(Node **head,Node **tail){
    if(*head!=NULL){
        Node *temp=*head;
        *head = (*head)->next;
        free(temp);

        if(*head==NULL) *tail=NULL;
    }
}

void printfEnqueue(Node *head){
    while(head!=NULL){
        printf("number: %d\n",head->next);
        head=head->next;
    }
}