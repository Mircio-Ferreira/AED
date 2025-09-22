#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int n;
    struct Node *next;
    struct Node *prev;
}Node;

void insertBeging(Node **head,Node **tail,int n);

void removeBeging(Node **head,Node **tail);

void insertFinish(Node **head,Node **tail,int n);

void removeFinish(Node **head,Node **tail);


void print(Node *head,Node *tail);
void printReverse(Node *head,Node *tail);


int main(){
    Node *tail=NULL,*head=NULL;
    insertBeging(&head,&tail,5);
    insertBeging(&head,&tail,4);
    insertBeging(&head,&tail,3);
    insertBeging(&head,&tail,2);
    insertBeging(&head,&tail,1);

    print(head,tail);

    removeBeging(&head,&tail);
    removeBeging(&head,&tail);
    
    print(head,tail);

    insertFinish(&head,&tail,6);
    insertFinish(&head,&tail,7);
    insertFinish(&head,&tail,8);
    insertFinish(&head,&tail,9);

    print(head,tail);
    

    removeFinish(&head,&tail);
    removeFinish(&head,&tail);
    removeFinish(&head,&tail);

    print(head,tail);

    printReverse(head,tail);



    return 0;
}

void insertBeging(Node **head,Node **tail,int n){
    Node *new=malloc(sizeof(Node));
    new->n=n;
    if(*head==NULL){
        *head=*tail=new;
        new->next=*tail;
        new->prev=*head;
    }
    else{
        new->next=*head;
        (*head)->prev=new;
        new->prev=*tail;
        (*tail)->next=new;

        *head=new;
    }
}


void insertFinish(Node **head,Node **tail,int n){
    Node *new=malloc(sizeof(Node));
    new->n=n;
    if(*head==NULL){
        *head=*tail=new;
        new->prev=new->next=new;
    }
    else{
        (*tail)->next=new;
        new->prev=*tail;
        *tail=new;
        (*head)->prev=*tail;
        (*tail)->next=*head;
    }
}

void removeBeging(Node **head,Node **tail){
    if(*head!=NULL){
        Node *remove=*head;
        if(*head==*tail) *head=*tail=NULL;
        else{
            *head=(*head)->next;
            (*head)->prev=*tail;
            (*tail)->next=*head;
        }
        free(remove);
    }
}

void removeFinish(Node **head,Node **tail){
    if(*head!=NULL){
        Node *remove=*tail;
        if(*head==*tail) *head=*tail=NULL;
        else{
            *tail=(*tail)->prev;
            (*tail)->next=*head;
            (*head)->prev=*tail;
        }
        free(remove);
    }
}

void print(Node *head,Node *tail){
    if(head!=NULL){
        Node *aux=head;
        do{
            printf("|%d|",aux->n);
            aux=aux->next;
        }while(aux!=head);
    }
    printf("\n");
}

void printReverse(Node *head,Node *tail){
    if(head!=NULL){
        do{
            printf("|%d|",tail->n);
            tail=tail->prev;
        }while(tail->next!=head);
        printf("\n");
    }
}
