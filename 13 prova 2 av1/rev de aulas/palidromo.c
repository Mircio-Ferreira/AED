#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    char c;
    struct Node *next;
    struct Node *prev;
}Node;

void print(Node *head){
    if(head!=NULL){
        Node *aux=head;
        do{
            printf("|%c|",aux->c);
            aux=aux->next;
        }while(aux!=head);
        printf("\n");
    }
}
void printReverse(Node *tail){
    if(tail!=NULL){
        Node *aux=tail;
        do{
            printf("|%c|",aux->c);
            aux=aux->prev;
        }while(aux!=tail);
        printf("\n");
    }
}

void inserEnd(Node **head,Node **tail,char c){
    Node *new=malloc(sizeof(Node));
    if(new==NULL) return;
    new->c=c;
    if(*head==NULL){
        *head=*tail=new;
        new->next=new->prev=new;
    }
    else{
        (*tail)->next=new;
        new->prev=*tail;
        new->next=*head;
        *tail=new;
        (*head)->prev=*tail;
    }
}

int palidromo(Node *head,Node *tail){
    if(head==NULL || head->next==head || head->next->next==head) return 0;
    Node *noNext=head,*NoPrev=tail;
    do{
        if(noNext->c!=NoPrev->c) return 0;
        noNext=noNext->next;
        NoPrev=NoPrev->prev;
    }while(noNext->next!=head);
    return 1;
}

int main(){
    Node *head=NULL,*tail=NULL;

    inserEnd(&head,&tail,'a');
    inserEnd(&head,&tail,'a');
    inserEnd(&head,&tail,'a');
    //inserEnd(&head,&tail,'a');
    //inserEnd(&head,&tail,'a');
    //inserEnd(&head,&tail,'c');

    int pali=palidromo(head,tail);

    print(head);
    printReverse(tail);

    if(pali) printf("\nPalidromo!\n");
    else printf("nao e");

    return 0;
}