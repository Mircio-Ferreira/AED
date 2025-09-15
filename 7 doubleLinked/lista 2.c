#include <stdio.h>
#include <stdlib.h>

typedef struct Node{ 
    int n; 
    struct Node *next; 
    struct Node *prev; 
} Node;

void print(Node *head);
void printInverse(Node *tail);

//questao 1
void insertSort(Node **head,Node **tail,int n){
    Node *new=malloc(sizeof(Node));
    new->n=n;
    if(*head==NULL){
        *head=*tail=new;
        new->next=NULL;
        new->prev=NULL;
    }
    else if((*head)->n > n){
        new->prev=NULL;
        new->next=*head;
        (*head)->prev=new;
        *head=new;
    }
    else if((*tail)->n < n){
        new->next=NULL;
        (*tail)->next=new;
        new->prev=*tail;
        *tail=new;
    }
    else{
        Node *aux=*head;
        while(aux->next->n < n) aux=aux->next;
        new->next=aux->next;
        new->prev=aux;
        aux->next->prev=new;
        aux->next=new;
    }
}

//questao 2
void insertEnd(Node **head,int n){
    Node *new=malloc(sizeof(Node));
    new->n=n;
    new->next=NULL;
    if(*head==NULL){
        *head=new;
        new->prev=NULL;
    }
    else{
        Node *aux=*head;
        while(aux->next!=NULL) aux=aux->next;
        aux->next=new;
        new->prev=aux;
    }
}

void insertIntercale(Node **head,Node *head1,Node *head2){
    while(head1!=NULL || head2!=NULL){
        if(head1!=NULL){
             insertEnd(head,head1->n);
             head1=head1->next;
        }
        if(head2!=NULL){
            insertEnd(head,head2->n);
            head2=head2->next;
        }
    }
}

//questao 3

void checkInsert(Node *head, int check){
    int contDepos=0,contAntes=0;
    Node *aux=head;
    while(aux!=NULL && aux->n!=check){
        aux=aux->next;
    }

    if(aux!=NULL){
        Node *auxAntes=aux;
        while(auxAntes->prev!=NULL){
            contAntes++;
            auxAntes=auxAntes->prev;
        }
        while(aux->next!=NULL){
            contDepos++;
            aux=aux->next;
        }
    }

    printf("Quantidade antes do No passado: %d\nQuantidade depois do No achado: %d",contAntes,contDepos);
}

int main(){
    Node *head=NULL;
    //Node *tail=NULL;
    Node *head1=NULL,*head2=NULL;
    //Questao1
    // insertSort(&head,&tail,1);
    // insertSort(&head,&tail,0);
    // insertSort(&head,&tail,2);
    // insertSort(&head,&tail,3);
    // insertSort(&head,&tail,5);
    // insertSort(&head,&tail,4);
    // print(head);
    // printInverse(tail);

    insertEnd(&head1,1);
    insertEnd(&head2,2);
    insertEnd(&head1,3);
    insertEnd(&head2,4);
    insertEnd(&head1,5);
    insertEnd(&head2,6);
    print(head1);
    print(head2);
    insertIntercale(&head,head1,head2);
    print(head);

    checkInsert(head,6);

    return 0;
}

void print(Node *head){
    while(head!=NULL){
        printf("|%d|",head->n);
        head=head->next;
    }
    printf("\n");
}
void printInverse(Node *tail){
    while(tail!=NULL){
        printf("|%d|",tail->n);
        tail=tail->prev;
    }
    printf("\n");
}