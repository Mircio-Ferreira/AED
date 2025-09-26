#include <stdio.h>
#include <stdlib.h>

/*
QUESTÃO 02 - (2.5 pontos) Considere que um programa em C manipula duas
listas duplamente encadeadas (Lista01 e Lista02) e agora é necessário que seja
implementada uma nova função que realiza a troca do último elemento entre as
listas (o último nó que está na Lista01 vai para a Lista02 E o último nó que estava
na Lista02 vai para a Lista01).
Protótipo da função: void troca(Node **head1, Node **head2);
*/

typedef struct Node{
    int n;
    struct Node *next;
    struct Node *prev;
}Node;

void insert(Node **head,int n);
void print(Node *head);
void swap(Node **head1,Node **head2);

int main(){
    Node *head1=NULL, *head2=NULL;

    insert(&head1,1);
    insert(&head1,2);
    //insert(&head1,3);
    //insert(&head1,4);
    //insert(&head1,5);
    printf("lista1: ");
    print(head1);

    insert(&head2,6);
    insert(&head2,7);
    //insert(&head2,8);
    //insert(&head2,9);
    //insert(&head2,10);
    printf("lista2: ");
    print(head2);

    
    printf("lista apos swap no final\n");
    swap(&head1,&head2);

    printf("lista1: ");
    print(head1);

    printf("lista2: ");
    print(head2);


    return 0;
}

void insert(Node **head,int n){
    Node *new=malloc(sizeof(Node));
    new->n=n;
    new->next=NULL;
    if(*head==NULL){
        new->prev=NULL;
        *head=new;
    }
    else{
        Node *aux=*head;
        while(aux->next!=NULL) aux=aux->next;
        new->prev=aux;
        aux->next=new;
    }
}

void print(Node *head){
    while(head!=NULL){
        printf("|%d|",head->n);
        head=head->next;
    }
    printf("\n");
}

void swap(Node **head1,Node **head2){
    if(*head1!=NULL && *head2!=NULL){
        Node *aux1=*head1,*aux2=*head2;

        while(aux1->next!=NULL) aux1=aux1->next;
        while(aux2->next!=NULL) aux2=aux2->next;

        if(aux1->prev==NULL && aux2->prev==NULL){
            *head1=*head2;
            *head1=aux1;
        }
        else if(aux1->prev==NULL && aux2->prev!=NULL){
            *head1=aux2;

            aux2->prev->next=aux1;
            aux1->prev=aux2->prev;

            (*head1)->prev=NULL;
            (*head1)->next=NULL;
        }
        
        else if(aux1->prev!=NULL && aux2->prev==NULL){
            
            *head2=aux1;

            aux1->prev->next=aux2;
            aux2->prev=aux1->prev;

            (*head2)->prev=NULL;
            (*head2)->next=NULL;

        }

        else{

            Node *temp1Prev = aux1->prev;
            Node *temp2prev = aux2->prev;

            temp1Prev->next=aux2;
            temp2prev->next=aux1;

            aux1->prev=temp2prev;
            aux2->prev=temp1Prev;

            //aux1->next=aux2->next=NULL;

        }
        
    }
}

/* 
void swap(Node **head1, Node **head2) {
    if (*head1 == NULL || *head2 == NULL) return;

    Node *last1 = *head1;
    Node *last2 = *head2;

    // percorre até o último nó
    while (last1->next) last1 = last1->next;
    while (last2->next) last2 = last2->next;

    // se last1 não for o único nó
    if (last1->prev) last1->prev->next = last2;
    else *head1 = last2; // last1 era o primeiro nó

    // se last2 não for o único nó
    if (last2->prev) last2->prev->next = last1;
    else *head2 = last1; // last2 era o primeiro nó

    // troca os prev
    Node *tmp = last1->prev;
    last1->prev = last2->prev;
    last2->prev = tmp;

    // troca os next
    last1->next = NULL;
    last2->next = NULL;
}
*/