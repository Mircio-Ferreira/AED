#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int n;
    struct Node *next;
}Node;

void enqueue(Node **head,Node **tail,int input);

void printQueue(Node *head);

void filaDupla(int entrada,Node *head,Node *tail,Node **head1,Node **head2,Node **tail1, Node **tail2);

int main(){

    Node *head=NULL,*tail= NULL;
    Node *head1=NULL,*head2=NULL,*tail1=NULL,*tail2=NULL;
    int len=11,entrada=-20;
    for(int i=0;i<len;i++) enqueue(&head,&tail,i);
    printf("fila original: \n"); 
    printQueue(head);
    filaDupla(entrada,head,tail,&head1,&head2,&tail1,&tail2);
    printf("\nfila1 \n");
    printQueue(head1);
    printf("\nfila2 \n");
    printQueue(head2);
    return 0;
}

void enqueue(Node **head,Node **tail,int input){
    Node *new=malloc(sizeof(Node));
    new->n=input;
    new->next=NULL;
    if(*head==NULL) *head=*tail=new;
    else{
        (*tail)->next=new;
        *tail=new;
    }
}

void printQueue(Node *head){
    while(head!=NULL){
        printf("%d\n",head->n);
        head=head->next;
    }
}

void filaDupla(int entrada,Node *head,Node *tail,Node **head1,Node **head2,Node **tail1, Node **tail2){
    Node *backUp=head;
    int stop=-1,cont=0;
    while(head!=NULL){
        cont++;
        if(head->n==entrada) stop=cont-1;
        head=head->next;
    }
    head=backUp;
    if(stop!=-1){
        for(int i=0;i<stop;i++) {
            enqueue(head1,tail1,head->n);
            head=head->next;
        }
        while(head!=NULL){
            enqueue(head2,tail2,head->n);
            head=head->next;
        }
    }
    else{
        int par=0;
        if(cont%2==0) par=1;
        for(int i=0;i<cont/2;i++) {
            enqueue(head1,tail1,head->n);
            head=head->next;
        }

        if(!par){
            enqueue(head1,tail1,head->n);
            head=head->next;
        }
        for(int i=0;i<cont/2;i++) {
            enqueue(head2,tail2,head->n);
            head=head->next;
        }
    }
}
