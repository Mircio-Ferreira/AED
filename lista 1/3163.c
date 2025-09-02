#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    char voo[20];
    struct Node *next;
}Node;

void dequeueAndPrint(Node **head,Node **tail);

void dequeueAndPrintLast(Node **head,Node **tail);

void enqueue(Node **head,Node **tail,char *voo);

int main(){

    Node *head1=NULL,*head2=NULL,*head3=NULL,*head4=NULL;
    Node *tail1=NULL,*tail2=NULL,*tail3=NULL,*tail4=NULL;

    int cardeal=1;
    char voo[20];
    int contEntradas=0;
    int cont=0;
    while(1){
        scanf("%d",&cardeal);
        if(cardeal==0) break;
        scanf(" %s",voo);
        if(cardeal==-1) enqueue(&head1,&tail1,voo);
        else if(cardeal==-2) enqueue(&head2,&tail2,voo);
        else if(cardeal==-3) enqueue(&head3,&tail3,voo);
        else if(cardeal==-4) enqueue(&head4,&tail4,voo);
        contEntradas++;
    }
    while(1){
        if(cont==contEntradas){
            dequeueAndPrintLast(&head1,&tail1);
            dequeueAndPrintLast(&head2,&tail2);
            dequeueAndPrintLast(&head3,&tail3);
            dequeueAndPrintLast(&head4,&tail4);
            break;
        }
        if(head1!=NULL) cont++;
        if(cont!=contEntradas) dequeueAndPrint(&head1,&tail1);
        if(head3!=NULL) cont++;
        if(cont!=contEntradas) dequeueAndPrint(&head3,&tail3);
        if(head2!=NULL) cont++;
        if(cont!=contEntradas) dequeueAndPrint(&head2,&tail2);
        if(head4!=NULL) cont++;
        if(cont!=contEntradas) dequeueAndPrint(&head4,&tail4);
    }
    printf("\n");

    return 0;
}

void enqueue(Node **head,Node **tail,char *voo){
    Node *new=malloc(sizeof(Node));
    strcpy(new->voo,voo);
    new->next=NULL;
    if(*head==NULL) *head=*tail=new;
    else{
        (*tail)->next=new;
        *tail=new;
    }
}

void dequeueAndPrint(Node **head,Node **tail){
    if(*head!=NULL){
        Node *remove=*head;
        printf("%s ",(*head)->voo);
        *head=(*head)->next;
        free(remove);
        if(*head==NULL) *tail=NULL;
    }
}

void dequeueAndPrintLast(Node **head,Node **tail){
    if(*head!=NULL){
        Node *remove=*head;
        printf("%s",(*head)->voo);
        *head=(*head)->next;
        free(remove);
        if(*head==NULL) *tail=NULL;
    }
}
