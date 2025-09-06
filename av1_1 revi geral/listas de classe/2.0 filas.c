#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int n;
    struct Node *next;
}Node;

void enqueue(Node **head,Node **tail, int n);

void dequeue(Node **head,Node **tail);

void print(Node *head);

void printfila(Node *head){
    while(head!=NULL){
        printf("fila: %d",head->n);
        head=head->next;
    }
}

int main(){

    Node *head1=NULL,*head2=NULL;
    Node *tail1=NULL,*tail2=NULL;
    int cont1,cont2,saida,input;

    scanf("%d %d %d",&cont1,&cont2,&saida);
    
    for(int i=0;i<cont1;i++){
        scanf("%d",&input);
        enqueue(&head1,&tail1,input);
    }
    //printfila(head1);
    for(int i=0;i<cont2;i++){
    scanf("%d",&input);
    enqueue(&head2,&tail2,input);
    }
    //printfila(head2);
    printf("saida\n\n\n\n");
    while(head1!=NULL || head2!=NULL){
    if(saida==2){
        dequeue(&head1,&tail1);
        dequeue(&head2,&tail2);
    }
    else{
        dequeue(&head2,&tail2);
        dequeue(&head1,&tail1);
    }
    }
    return 0;
}

void enqueue(Node **head,Node **tail, int n){
    Node *new=malloc(sizeof(Node));
    new->n=n;
    new->next=NULL;
    if(*head==NULL) *head=*tail=new;
    else{
        (*tail)->next=new;
        *tail=new;
    }
}

void dequeue(Node **head,Node **tail){
    if(*head!=NULL){
        print(*head);
        Node *temp=*head;
        *head=(*head)->next;
        free(temp);
        if(*head==NULL) *tail=NULL;
    }
}

void print(Node *head){
    printf("%d\n",head->n);
}