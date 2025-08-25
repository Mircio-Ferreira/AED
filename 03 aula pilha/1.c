#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int n;
    struct Node *next;
}Node;

void push(Node **head,int input);

void pop(Node **head);

void print(Node *head);

void printBase(Node *head);

void printPar(Node *head);

int main(){
    Node *head=NULL;
    int input;
    for(int i=0;i<5;i++){
        scanf( "%d",&input);
        push(&head,input);
    }
    printPar(head);
    printBase(head);
    printf("\n");
    print(head);
    pop(&head);
    printf("\n");
    print(head);
    pop(&head);
    printf("\n");
    print(head);
    return 0;
}

void push(Node **head,int input){
    Node *new=(Node*)malloc(sizeof(Node));
    new->n=input;
    new->next=*head;
    *head=new;
}

void pop(Node **head){
    if(*head!=NULL){
        Node *temp=*head;
        *head=(*head)->next;
        free(temp);
    }
}
void print(Node *head){
    if(head==NULL) printf("Lista Vazia");
    else{
        while(head!=NULL){
            printf("%d\n",head->n);
            head=head->next;
        }
    }
}
/*
void printBase(Node *head){
    while(head != NULL && ((head->next!=NULL && (head = head->next)) || (printf("base: %d",head->n)))) ;
}
*/
void printBase(Node *head){
    while(head!=NULL){
        if(head->next==NULL){
            printf("\nBase:%d\n",head->n);
            return;
        }
        head=head->next;
    }
}
void printPar(Node *head){
    while(head!=NULL){
        if(head->n%2==0) printf("par : %d\n",head->n);
        head=head->next;
    }
}