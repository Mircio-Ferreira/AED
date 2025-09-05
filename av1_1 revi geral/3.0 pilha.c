/*
a) Inserir novos elementos;

b) Imprimir a base da pilha;


c) Imprimir o topo da pilha;



d) Remover um nó da pilha;

e) Imprimir todos os nós na posição par.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int n;
    struct Node *next;
}Node;

void push(Node **head, int n);
void printBase(Node *head);
void printTop(Node *head);
void pop(Node **head);
void printStack(Node *head);

int main(){

    Node *head=NULL;
    push(&head,1);
    push(&head,2);
    push(&head,3);
    push(&head,4);
    push(&head,5);

    printf("pilha:\n");
    printStack(head);
    printf("base: ");
    printBase(head);
    printf("\ntopo: ");
    printTop(head);
    pop(&head);
    pop(&head);
    printf("\npilha:\n");
    printStack(head);
    printf("base: ");
    printBase(head);
    printf("\ntopo: ");
    printTop(head);




    return 0;
}

void push(Node **head, int n){
    Node *new=malloc(sizeof(Node));
    new->n=n;
    new->next=*head;
    *head=new;
}
void printBase(Node *head){
    if(head!=NULL){
    while(head->next!=NULL) head=head->next;
    printf("Base da pilha: %d\n",head->n);
    }
}
void printTop(Node *head){
    if(head!=NULL) printf("Topo da pilha: %d\n",head->n);

}
void pop(Node **head){
    if(head!=NULL){
        Node *temp=*head;
        *head=(*head)->next;
        free(temp);
    }
}
void printStack(Node *head){
    while(head!=NULL){
        printf("%d\n",head->n);
        head=head->next;
    }
}