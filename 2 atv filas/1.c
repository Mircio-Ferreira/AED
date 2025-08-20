#include <stdio.h>
#include <stdlib.h>

// https://www.thehuxley.com/problem/5

typedef struct Node{
    int n;
    struct Node *next;
}Node;


void enqueue(Node **head,Node **tail, int n);

void dequeue(Node **head,Node **tail);

void printNode(Node *head);


int main(){

    Node *head1=NULL, *tail1=NULL, *head2=NULL, *tail2=NULL;

    int input;
    int quantFila1,quantFila2,exit;

    scanf("%d %d %d",&quantFila1,&quantFila2,&exit);

    for(int i=0;i<quantFila1;i++){
        scanf(" %d",&input);
        enqueue(&head1,&tail1,input);
    }
    for(int i=0;i<quantFila2;i++){
        scanf(" %d",&input);
        enqueue(&head2,&tail2,input);
    }
    printf("Saidas: \n");
    if(exit==1){
        while(1){
            dequeue(&head2,&tail2);
            dequeue(&head1,&tail1);
            if(head1 == head2) break;
        }
    }
    else{
        while(1){
            dequeue(&head1,&tail1);
            dequeue(&head2,&tail2);
            if(head1 == head2) break;
        }
    }
    return 0;
}

void enqueue(Node **head,Node **tail, int n){
    Node *new=(Node *)malloc(sizeof(Node));
    new->n=n;
    new->next=NULL;
    if(*head==NULL) *head=*tail=new;
    else{
        (*tail)->next=new;
        *tail=new;
    }
}
void dequeue(Node **head,Node **tail){
    if(*head!=NULL){
        printNode(*head);
        Node *temp=*head;
        *head=(*head)->next;
        free(temp);
        if(*head==NULL) *tail=NULL;
    }
    return;
}

void printNode(Node *head){
    printf("%d\n",head->n);
}