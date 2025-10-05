#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int n;
    struct Node *next;
    struct Node *prev;
}Node;

void insertEnd(Node **head,Node **tail,int n){
    Node *new=malloc(sizeof(Node));
    if(new==NULL) return;
    new->n=n;
    if(*head==NULL){
        new->next=new->prev=NULL;
        *head=*tail=new;
    }
    else{
        new->next=NULL;
        new->prev=*tail;
        (*tail)->next=new;
        *tail=new;
    }
}

void print(Node *head){
    while(head!=NULL){
        printf("|%d|",head->n);
        head=head->next;
    }
    printf("\n");
}
void printReverse(Node *head){

    while(head->next!=NULL) head=head->next;
    
    Node *aux=head; // aux=tail;

    while(aux!=NULL){
        printf("|%d|",aux->n);
        aux=aux->prev;
    }
    printf("\n");

}

void excluirIntervalo(Node **head, Node **tail, int delimitador01, int delimitador02){
    if(*head==NULL || (*head)->next==NULL || (*head)->next->next==NULL) return;

    Node *aux=*head;
    Node *no1,*no2;
    int flag1=0,flag2=0;

    while(aux!=NULL){
        if(flag1==0 && aux->n==delimitador01){
            no1=aux;
            flag1=1;
        }
        else if(flag1==1 && aux->n==delimitador02 && aux->prev!=no1){
            flag2=1;
            no2=aux;

        }
        if(flag2==1) break;
        aux=aux->next;
    }

    if(flag2!=1) return;


    aux=no1->next;

    no1->next=no2;
    no2->prev=no1;
    Node *remove;
    while(1){
        remove=aux;
        aux=aux->next;
        free(remove);

        if(aux==no2) break;;
    }

}

int main(){
    
    Node *head=NULL,*tail=NULL;

    insertEnd(&head,&tail,1);
    insertEnd(&head,&tail,2);
    insertEnd(&head,&tail,3);
    insertEnd(&head,&tail,4);
    insertEnd(&head,&tail,5);

    print(head);
    printReverse(head);

    excluirIntervalo(&head,&tail,1,5);

    print(head);
    printReverse(head);
    
    return 0;
}