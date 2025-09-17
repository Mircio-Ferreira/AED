#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int n;
    struct Node *next;
}Node;

void insertEnd(Node **head,Node **tail,int n);

void pop(Node **head,Node **tail);

void print(Node *head,Node *tail);

int main(){
    Node *tail=NULL,*head=NULL;

    insertEnd(&head,&tail,0);
    insertEnd(&head,&tail,1);
    insertEnd(&head,&tail,2);
    insertEnd(&head,&tail,3);
    print(head,tail);
    pop(&head,&tail);
    print(head,tail);
    pop(&head,&tail);
    print(head,tail);
    pop(&head,&tail);
    print(head,tail);
    pop(&head,&tail);
    print(head,tail);
    pop(&head,&tail);



    return 0;
}

void insertEnd(Node **head,Node **tail,int n){
    Node *new=malloc(sizeof(Node));
    new->n=n;
    if(*head==NULL){
        *head=*tail=new;
        (*tail)->next=new;
    }
    else{
        (*tail)->next=new;
        *tail=new;
        (*tail)->next=*head;
    }
}

void pop(Node **head,Node **tail){
    if(*head!=NULL){
        Node *remove=*tail;
        if(*head==*tail) *head=*tail=NULL;
        else{
            Node *aux=*head;
            while(aux->next!=*tail) aux=aux->next;
            *tail=aux;
            (*tail)->next=*head;
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
        printf("\n");
    }
}