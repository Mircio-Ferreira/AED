#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    char c;
    struct  Node *next;
    struct Node *prev;
}Node;

void insertFinish(Node **head,Node **tail,char c);

int len(Node *head,Node *tail);

void print(Node *head,Node *tail);

void printReverse(Node *head,Node *tail);

int checkPalidromo(Node *head,Node *tail);

int main(){

    Node *head=NULL, *tail=NULL;

    insertFinish(&head,&tail,'a');
    insertFinish(&head,&tail,'r');
    insertFinish(&head,&tail,'a');
    insertFinish(&head,&tail,'r');
    insertFinish(&head,&tail,'a');
    //insertFinish(&head,&tail,'a');


    print(head,tail);

    printReverse(head,tail);

    printf("\n|%d|\n",checkPalidromo(head,tail));


    return 0;
}

void insertFinish(Node **head,Node **tail,char c){
    Node *new=malloc(sizeof(Node));
    new->c=c;
    if(*head==NULL){
        *head=*tail=new;
        new->next=new->prev=new;
    }
    else{
        (*tail)->next=new;
        new->prev=*tail;
        *tail=new;
        new->next=*head;
        (*head)->prev=new;
    }
}

void print(Node *head,Node *tail){
    if(head!=NULL){
        Node *aux=head;
        do{
            printf("%c",aux->c);
            aux=aux->next;
        }while(aux!=head);
        
        printf("\n");
    }
}

int len(Node *head,Node *tail){
    int cont=0;
    if(head!=NULL){
        Node *aux=head;
        do{
            cont++;
            aux=aux->next;
        }while(aux!=head);
    }
    return cont;
}

int checkPalidromo(Node *head,Node *tail){
    int tam=len(head,tail);
    if( tam <= 3) return -1;

    Node *go=head,*back=tail;

    // while(go!=tail && back !=head){
    //     if(go->c!=back->c) return 0;
    //     go=go->next;
    //     back=back->prev;
    // }

    //maneira mais otimizada

    for(int i=0;i<tam/2;i++){
        if(go->c!=back->c) return 0;
        go=go->next;
        back=back->prev;
    }

    return 1;
}

void printReverse(Node *head,Node *tail){
    if(head!=NULL){
        Node *aux=tail;
        do{
            printf("|%c|",aux->c);
            aux=aux->prev;
        }while(aux!=tail);
    }
    printf("\n");
}