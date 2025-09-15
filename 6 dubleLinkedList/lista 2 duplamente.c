#include <stdio.h>
#include <stdlib.h>

typedef struct Node{ 
int n; 
struct Node *next; 
struct Node *prev; 
} Node;

void print(Node *head);


void insertSort(Node **head,Node **tail,int n);

void interecaleList(Node **head,Node *head1,Node *head2);

void insertEnd(Node **head,int n);

void searchNode(Node *head, int check);

int main(){

    Node *head=NULL;
    insertEnd(&head,1);
    insertEnd(&head,2);
    insertEnd(&head,3);
    insertEnd(&head,4);
    insertEnd(&head,5);
    insertEnd(&head,6);
    insertEnd(&head,7);
    searchNode(head,4);

    
    // Node *list1 = NULL;
    // Node *list2 = NULL;
    // Node *intercalada = NULL;

    // // Adiciona elementos à primeira lista
    // insertEnd(&list1, 1);
    // insertEnd(&list1, 3);
    // insertEnd(&list1, 5);

    // // Adiciona elementos à segunda lista
    // insertEnd(&list2, 2);
    // insertEnd(&list2, 4);
    // insertEnd(&list2, 6);
    // insertEnd(&list2, 7);


    // printf("Lista 1: ");
    // print(list1);

    // printf("Lista 2: ");
    // print(list2);

    // interecaleList(&intercalada, list1, list2);

    // printf("Lista intercalada: ");
    // print(intercalada);



    


    return 0;
}




void print(Node *head){
    while(head!=NULL){
        printf("|%d|",head->n);
        head=head->next;
    }
    printf("\n");
}
//  questao 1
void insertSort(Node **head,Node **tail,int n){
    Node *new=malloc(sizeof(Node));
    new->n=n;
    if(*head==NULL){
        *head=*tail=new;
        new->next=NULL;
        new->prev=NULL;
    }
    else if((*head)->n > n){
        new->next=*head;
        new->prev=new;
        (*head)->prev=new;
        *head=new;
    }
    else if((*tail)->n < n){
        (*tail)->next=new;
        new->prev=*tail;
        new->next=NULL;
        *tail=new;
    }
    else{
        Node *aux=*head;
        while(aux->next->n < n){
            aux=aux->next;
        }
        new->next=aux->next;
        new->prev=aux;
        aux->next->prev=new;
        aux->next=new;
    }
}
// questao 2
void insertEnd(Node **head,int n){
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
        aux->next=new;
        new->prev=aux;
    }
}

void interecaleList(Node **head,Node *head1,Node *head2){
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
// questao 3
void searchNode(Node *head, int check){
    Node *aux=head;
    int contAntes=0,contDepos=0;

    while(aux!=NULL && aux->n!=check) aux=aux->next;
    if(aux!=NULL){
        Node *auxAntes=aux, *auxDepos=aux;

        while(auxAntes->prev!=NULL){
            contAntes++;
            auxAntes=auxAntes->prev;
        }
        while(auxDepos->next!=NULL){
            contDepos++;
            auxDepos=auxDepos->next;
        }

    } 

    printf("Antes: %d\nDepos:%d",contAntes,contDepos);
}