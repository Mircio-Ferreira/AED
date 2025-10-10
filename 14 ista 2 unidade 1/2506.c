#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int horas;
    int minutos;
    struct Node *next;
    struct Node *prev;
}Node;

void insertEnd(Node **head,Node **tail,int horas,int minutos);
void checkCritical(Node *head,Node *tail);

int main(){
    Node *head=NULL,*tail=NULL;
}