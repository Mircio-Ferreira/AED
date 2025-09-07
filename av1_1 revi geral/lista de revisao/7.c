/*
QUESTÃO 07 - Considere que um programa em C manipula duas Pilhas (Pilha01 e
Pilha02) e agora é necessário que seja implementada uma nova função que realiza a
troca do primeiro elemento entre as pilhas (o primeiro nó que está na Pilha01 vai para
a Pilha02 E o primeiro nó que estava na Pilha02 vai para a Pilha01).
Protótipo da função: void troca(Node **head1, Node **head2);
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int n;
    struct Node *next;
}Node;

void push(Node **head,int n);

void print(Node *head);

void troca(Node **head1, Node **head2);

void pop(Node **head);

int main(){
    Node *p1=NULL,*p2=NULL;

    push(&p1,0);
    push(&p1,1);
    push(&p1,2);
    push(&p1,3);
    print(p1);
    push(&p2,4);
    push(&p2,5);
    push(&p2,6);
    push(&p2,7);
    print(p2);
    troca(&p1,&p2);
    printf("1\n");
    print(p1);
    printf("2\n");
    print(p2);

    pop(&p2);
    pop(&p2);
    print(p2);


    return 0;
}

void push(Node **head,int n){
    Node *new=malloc(sizeof(Node));
    new->n=n;
    new->next=*head;
    *head=new;
}

void print(Node *head){
    printf("Pilha: ");
    while(head!=NULL){
        printf("|%d|",head->n);
        head=head->next;
    }
    printf("\n");
}

void troca(Node **head1, Node **head2){
    Node *head1next=(*head1)->next;
    Node *head2next=(*head2)->next;
    Node *temp=*head1;
    *head1=*head2;
    (*head1)->next=head1next;
    *head2=temp;
    (*head2)->next=head2next;
}

void pop(Node **head){
    if(*head!=NULL){
        Node *temp=*head;
        *head=(*head)->next;
        free(temp);
    }
}