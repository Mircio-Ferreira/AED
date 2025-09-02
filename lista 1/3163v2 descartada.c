#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    char voo[20];
    struct Node *next;
}Node;

char *dequeueAndPrint(Node **head,Node **tail);

void enqueue(Node **head,Node **tail,char *voo);

int main(){

    Node *head1=NULL,*head2=NULL,*head3=NULL,*head4=NULL;
    Node *tail1=NULL,*tail2=NULL,*tail3=NULL,*tail4=NULL;

    int cardeal=1;
    char voo[20];
    char saidas[10000];

    while(1){
        scanf("%d",&cardeal);
        if(cardeal==0) break;
        scanf(" %s",voo);
        if(cardeal==-1) enqueue(&head1,&tail1,voo);
        else if(cardeal==-2) enqueue(&head2,&tail2,voo);
        else if(cardeal==-3) enqueue(&head3,&tail3,voo);
        else if(cardeal==-4) enqueue(&head4,&tail4,voo);
    }
    while(1){
        strcat(saidas,dequeueAndPrint(&head1,&tail1));
        strcat(saidas,dequeueAndPrint(&head3,&tail3));
        strcat(saidas,dequeueAndPrint(&head2,&tail2));
        strcat(saidas,dequeueAndPrint(&head4,&tail4));
        //dequeueAndPrint(&head1,&tail1);
        //dequeueAndPrint(&head3,&tail3);
        //dequeueAndPrint(&head2,&tail2);
        //dequeueAndPrint(&head4,&tail4);
        if(head1==NULL && head2==NULL && head3==NULL && head4==NULL) break;
    }
    for(int i=0;i<strlen(saidas);i++){
        printf("%c",saidas[i]);
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

char* dequeueAndPrint(Node **head,Node **tail){
    if(*head!=NULL){
        char *saida;
        Node *remove=*head;
        strcpy(saida,(*head)->voo);
        saida[strlen(saida)]=' ';
        saida[strlen(saida)+1]='\0';
        *head=(*head)->next;
        free(remove);
        if(*head==NULL) *tail=NULL;
        return saida;
    }
    return '\0';
}