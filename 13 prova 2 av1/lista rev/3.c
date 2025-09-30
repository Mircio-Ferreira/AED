#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//Lista circula Simplesmente encadeada

typedef struct Node{
    int n;
    struct Node *next;
}Node;

void insertBegining(Node **head,Node **tail,int n);
void insertFinish(Node **head,Node **tail,int n);

void print(Node *head);

void removeBegining(Node **head,Node **tail);
void removeFinish(Node **head, Node **tail);

void insertSort(Node **head,Node **tail,int n);
void removePerValur(Node **head,Node **tail,int n);

int main(){
    srand(time(NULL));
    Node *head=NULL,*tail=NULL;

    for(int i=0;i<10;i++){
    int n=rand()%10;
    printf("Sorteado|%d|\n",n);
    insertSort(&head,&tail,n);
    printf("lista: ");
    print(head);
    }

    removePerValur(&head,&tail,0);
    removePerValur(&head,&tail,1);
    removePerValur(&head,&tail,2);
    removePerValur(&head,&tail,3);
    print(head);

    return 0;
}

void insertBegining(Node **head,Node **tail,int n){
    Node *new=malloc(sizeof(Node));
    new->n=n;
    if(*head==NULL) *head=*tail=new;
    else{
        new->next=*head;
        *head=new;
    }
    (*tail)->next=*head;
}

void insertFinish(Node **head,Node **tail,int n){
    Node *new=malloc(sizeof(Node));
    new->n=n;
    if(*head==NULL){
        *head=*tail=new;
        (*tail)->next=*head;
    }
    else{
        (*tail)->next=new;
        *tail=new;
        (*tail)->next=*head;
    }
}

void print(Node *head){
    if(head!=NULL){
        Node *aux=head;
        do{
            printf("|%d|",aux->n);
            aux=aux->next;
        }while(aux!=head);
        printf("\n");
    }
}

void removeBegining(Node **head,Node **tail){
    if(*head!=NULL){
        Node *remove=*head;
        if(*head==*tail) *tail=*head=NULL;
        else{
            *head=(*head)->next;
            (*tail)->next=*head;
        }
        free(remove);
    }
}
void removeFinish(Node **head, Node **tail){
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

void insertSort(Node **head,Node **tail,int n){
    Node *new=malloc(sizeof(Node));
    new->n=n;
    if(*head==NULL){
        *head=*tail=new;
        (*tail)->next=*head;
    }
    else if(n < (*head)->n){
        new->next=*head;
        *head=new;
        (*tail)->next=*head;
    }
    else if(n > (*tail)->n){
        (*tail)->next=new;
        *tail=new;
        (*tail)->next=*head;
    }
    else{// insersao de meio ou seja eu garanto que existe ao menos 2 elementos pq tenho head e tail
        Node *aux=*head;
        while(aux->next->n<n) aux=aux->next;
        new->next=aux->next;
        aux->next=new;
    }
}

void removePerValur(Node **head,Node **tail,int n){
    if(*head!=NULL){
        Node *remove;
        if((*head)->n==n && *head==*tail){
            remove=*head;
            *head=*tail=NULL;
            free(remove);
        }
        else if((*head)->n==n){
            remove=*head;
            *head=(*head)->next;
            free(remove);
            (*tail)->next=*head;
        }
        else{
            Node *aux=*head;
            //existe pelo menos 2 nos nesse else
            while(aux->next!=*head && aux->next->n!=n) aux=aux->next;
            if(aux->next->n==n){ // mesmo com o while preciso saber por esse if pra saber se o proximo no de fato é o que eu tenho que remover. e ele para um antes do que eu preciso remove
                remove=aux->next;
                aux->next=aux->next->next;
                if(*tail==remove) *tail=aux;
                free(remove);
            }
            else printf("No nao achado!\n");
        }
    }
}