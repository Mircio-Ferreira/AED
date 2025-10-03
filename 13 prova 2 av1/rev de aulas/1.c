#include <stdio.h>
#include <stdlib.h>

//intercalar e contagem 2 listas.

typedef struct Node{
    int n;
    struct Node *next;
    struct Node *prev;
}Node;

void print(Node *head);
void printReverse(Node *tail);

void insertFinish(Node **head, Node **tail, int n);

void intercale(Node **head1,Node **tail1,Node *head2,Node *head3,Node *tail2,Node *tail3);

void contagem(Node *head,Node *tail,int valor);

int main(){

    Node *head1=NULL,*head2=NULL,*head3=NULL;
    Node *tail1=NULL,*tail2=NULL,*tail3=NULL;

    for(int i=0;i<=10;i++){
        if(i%2==0) insertFinish(&head2,&tail2,i);
        else insertFinish(&head3,&tail3,i);
    }

    print(head2);
    printReverse(tail2);
    print(head3);
    printReverse(tail3);

    printf("\n");
    intercale(&head1,&tail1,head2,head3,tail2,tail3);
    print(head1);
    printReverse(tail1);
    return 0;
}

void print(Node *head){
    while(head!=NULL){
        printf("|%d|",head->n);
        head=head->next;
    }
    printf("\n");
}
void printReverse(Node *tail){
    while(tail!=NULL){
        printf("|%d|",tail->n);
        tail=tail->prev;
    }
    printf("\n");
}

void insertFinish(Node **head, Node **tail, int n){
    Node *new=malloc(sizeof(Node));
    new->n=n;
    new->next=NULL;
    if(*head==NULL){
        *head=*tail=new;
        new->prev=NULL;
    }
    else{
        new->prev=*tail;
        (*tail)->next=new;
        *tail=new;
    }
}

void intercale(Node **head1,Node **tail1,Node *head2,Node *head3,Node *tail2,Node *tail3){
    while(head3!=NULL || head2!=NULL){
        if(head2!=NULL){
            insertFinish(head1,tail1,head2->n);
            head2=head2->next;
        }
        if(head3!=NULL){
            insertFinish(head1,tail1,head3->n);
            head3=head3->next;
        }
    }
}

void contagem(Node *head,Node *tail,int valor){
    int prev=0,next=0;
    Node *voltar;
    while(head!=NULL){
        if(head->n==valor){
            voltar=head;
            break;
        }
    }
}