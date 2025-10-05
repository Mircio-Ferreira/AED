#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int n;
    struct Node *next;
}Node;

void print(Node *head);

void insertPerValue(Node **head,Node **tail,int n,int posi);

int main(){

    Node *head=NULL,*tail=NULL;

    insertPerValue(&head,&tail,10,1);
    insertPerValue(&head,&tail,30,2);


    print(head);
    insertPerValue(&head,&tail,20,2);
    print(head);

    insertPerValue(&head,&tail,40,1000);
    print(head);

    insertPerValue(&head,&tail,0,1);
    print(head);

    insertPerValue(&head,&tail,-1000,2);
    print(head);








    return 0;
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

void insertPerValue(Node **head,Node **tail,int n,int posi){
    if(posi < 1){
        printf("ala posi invalida\n");
        return;
    }
    Node *new=malloc(sizeof(Node));
    if(new==NULL) return ;

    new->n=n;
    if(*head==NULL){
        *head=*tail=new;
        new->next=new;
    }
    else if(posi==1){
        new->next=*head;
        *head=new;
        (*tail)->next=*head;
    }
    else{
        Node *aux=*head;
        int cont=1; 
        while(aux->next!=*head && posi!=cont+1){
            aux=aux->next;
            cont++;
        }
        if(aux->next==*head){
            (*tail)->next=new;
            new->next=*head;
            *tail=new;
        }
        else{
            new->next=aux->next;
            aux->next=new;
        }

    }
}