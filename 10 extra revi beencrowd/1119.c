#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int n;
    struct Node *next;
    struct Node *prev;
} Node;

void insert(Node **head,Node **tail,int n);
void remove(Node **head,Node **tail,int right,int left);

int main(){

    Node *head=NULL,*tail=NULL;

    int n,right,left;

    while(1){
        scanf("%d %d %d",n,right,left);

        if(n==0 && right ==0 && left ==0) break;

        for(int i=0;i<n;i++) insert(&head,&tail,n);



    }

    return 0;
}

void insert(Node **head,Node **tail,int n){
    Node *new=malloc(sizeof(Node));
    new->n=n;

    if(*head==NULL){
        *head=*tail=NULL;
        new->next=new->prev=new;
    }
    else{
        (*tail)->next=new;
        new->prev=*tail;
        new->next=*head;
        (*head)->prev=new;
        *tail=new;
    }
}

void remove(Node **head,Node **tail,int right,int left){
    Node *remove;

    while(*head!=NULL){
        //loop de ida
        Node *aux=*head;
        int cont=1;
        while(cont!=right){
            cont++;
            aux=aux->next;
        }
        remove=aux;
        printf("%d",aux->n);
        //loop de volta
        
    }
}