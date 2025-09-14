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

    insertBeging(&head,1);
    insertBeging(&head,2);
    insertBeging(&head,3);
    insertBeging(&head,4);
    insertBeging(&head,5);

    print(head);



    return 0;
}

void insertBeging(Node **head,int n){
    Node *new=malloc(sizeof(Node));
}

void print(Node *head){
    while(head!=NULL){
        printf("|%d|",head->n);
        head=head->next;
    }
}