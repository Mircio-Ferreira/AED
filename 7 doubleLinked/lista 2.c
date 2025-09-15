#include <stdio.h>
#include <stdlib.h>

typedef struct Node{ 
    int n; 
    struct Node *next; 
    struct Node *prev; 
} Node;

//questao 1
void insertSort(Node **head,Node **tail,int n){
    Node *new=malloc(sizeof(Node));
    new->n=n;
    if(*head==NULL){
        *head=*tail=new;
        new->next=NULL;
        new->prev=NULL;
    }
}

int main(){

    return 0;
}