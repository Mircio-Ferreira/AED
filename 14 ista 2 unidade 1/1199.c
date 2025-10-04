#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int n;
    struct Node *next;
    struct Node *prev;
}Node;

void insertBegining(Node **head,Node **tail,int n);

void busca(Node **head,Node **tail,int k,int m);

void remover(Node **head,Node **tail,int referencia);


int main(){
    int n,k,m;
    Node *head=NULL,*tail=NULL;

    while(1){
        scanf("%d %d %d",&n,&k,&m);
        if(k==0 && n ==0 && m== 0) break;
        
        for(int i=1;i<n+1;i++) {
            insertBegining(&head,&tail,i);

        }
        busca(&head,&tail,k,m);
    }


    return 0;
}

void insertBegining(Node **head,Node **tail,int n){
    Node *new=malloc(sizeof(Node));
    new->n=n;

    if(*head==NULL) *head=*tail=new->next=new->prev= new;
    else{
        (*tail)->next=new;
        new->prev=*tail;
        new->next=*head;
        *tail=new;
        (*head)->prev=*tail;
    }
}

void busca(Node **head,Node **tail,int k,int m){
    Node *auxRight=*head, *auxLeft=*tail;
        while(*head!=NULL){
            for(int i=0;i<k-1;i++) auxRight=auxRight->next;
            for(int i=0;i<m-1;i++) auxLeft=auxLeft->prev;
            if(auxRight==auxLeft){
                printf("   %d,",auxRight->n);
                int ref=auxRight->n;
                auxRight=auxRight->next;
                auxLeft=auxLeft->prev;
                remover(head,tail,ref);
            }
            else{
                printf("   %d   %d,",auxRight->n,auxLeft->n);
                int ref1=auxRight->n;
                int ref2=auxLeft->n;
                auxRight=auxRight->next;
                auxLeft=auxLeft->prev;
                remover(head,tail,ref1);
                remover(head,tail,ref2);
            }
    }
    printf("\n");
}
void remover(Node **head,Node **tail,int referencia){
    if(*head!=NULL){
        Node *remove;
        if((*head)->n==referencia && *tail==*head){
            free(*head);
            *head=*tail=NULL;
        }
        else if((*head)->n==referencia){
            remove=*head;
            *head=(*head)->next;
            free(remove);
            (*head)->prev=*tail;
            (*tail)->next=*head;           
        }
        else if((*tail)->n==referencia){
            remove=*tail;
            *tail=(*tail)->prev;
            free(remove);
            (*tail)->next=*head;
            (*head)->prev=*tail;
        }
        else{
            //Caso geral e valor sempre ira existir
            Node *aux=*head;
            while(aux->n!=referencia) aux=aux->next;
            remove=aux;
            aux->prev->next=aux->next;
            aux->next->prev=aux->prev;
            free(remove);
        }
    }
}