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

    for(int i=0;i<5;i++){
        //insertFinish(&head,&tail,i);
    }
    //print(head,tail);
    //printReverso(head,tail);

    return 0;
}

void insetBeging(Node **head,Node **tail,int n);
void insertFinish(Node **head,Node **tail,int n);

void removeBeging(Node **head,Node **tail);
void removeFinish(Node **head,Node **tail);

void print(Node *head,Node *tail);
void printReverso(Node *head,Node *tail);