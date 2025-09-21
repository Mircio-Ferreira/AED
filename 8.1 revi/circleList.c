#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int n;
    struct Node *next;
}Node;

void insertBeging(Node **head,Node **tail,int n);
void insertFinish(Node **head,Node **tail,int n);
void removeBeging(Node **head,Node **tail);
void removeFinish(Node **head,Node **tail);


int main(){

    Node *head=NULL,*tail=NULL;

    return 0;
}

void insertBeging(Node **head,Node **tail,int n);
void insertFinish(Node **head,Node **tail,int n);
void removeBeging(Node **head,Node **tail);
void removeFinish(Node **head,Node **tail);