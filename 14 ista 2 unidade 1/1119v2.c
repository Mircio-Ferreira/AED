#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int n;
    struct Node *next;
    struct Node *prev;
}Node;


void insertEnd(Node **head,Node **tail,int n);
void search(Node **head,Node **tail,int k,int m);
void removeNode(Node **head,Node **tail,Node *deleteNode);

int main(){
    int n,k,m;

    while(1){
        Node *head=NULL,*tail=NULL;
        scanf("%d %d %d",&n,&k,&m);
        if(n==0 && k==0 && m ==0) break;
        for(int i=1;i<n+1;i++) insertEnd(&head,&tail,i);
        search(&head,&tail,k,m);
        printf("\n");
    }
    //printf("\n");
    return 0;
}



void insertEnd(Node **head,Node **tail,int n){
    Node *new=malloc(sizeof(Node));
    new->n=n;
    if(*head==NULL) *tail=*head=new->next=new->prev=new;
    else{
        new->next=*head;
        new->prev=*tail;
        (*tail)->next=new;
        *tail=new;
        (*head)->prev=*tail;
       }
}

void search(Node **head,Node **tail,int k,int m){
    Node *auxRight=*head,*auxLeft=*tail;
    int boolFirstPrint=1;
    while(*head!=NULL){
        for(int i=1;i<k;i++) auxRight=auxRight->next;
        for(int i=1;i<m;i++) auxLeft=auxLeft->prev;

        if(boolFirstPrint==0) printf(",");
        boolFirstPrint=0;

        if(auxLeft==auxRight){
            printf("%3d",auxLeft->n);
            
            Node *nextRight=auxRight->next;
            Node *prevLeft=auxLeft->prev;

            removeNode(head,tail,auxRight);
            
            if(*head==NULL) break;

            auxRight=nextRight;
            auxLeft=prevLeft;
        }
        else{

            printf("%3d%3d",auxRight->n,auxLeft->n);

            Node *nextRight=auxRight->next,*prevRight=auxRight->prev;
            Node *nextLeft=auxLeft->next,*prevLeft=auxLeft->prev;
            
            Node *copyRight=auxRight, *copyLeft=auxLeft;

            removeNode(head,tail,auxRight);
            removeNode(head,tail,auxLeft);

            if(*head==NULL) break;
 
            if(nextRight==copyLeft) auxRight=nextLeft;
            else auxRight=nextRight;

            if(prevLeft==copyRight) auxLeft=prevRight;
            else auxLeft=prevLeft;

        }
    }

}

void removeNode(Node **head,Node **tail,Node *deleteNode){
    if(*head!=NULL){
        Node *removeNode=deleteNode;
        if(deleteNode->next==deleteNode) *head=*tail=NULL;
        else{
            if(*head==deleteNode){
                *head=(*head)->next;
                (*head)->prev=*tail;
                (*tail)->next=*head;
            }
            else if(*tail==deleteNode){
                *tail=(*tail)->prev;
                (*tail)->next=*head;
                (*head)->prev=*tail;
            }
            else{
            deleteNode->prev->next = deleteNode->next;
            deleteNode->next->prev = deleteNode->prev;
            }
        }
        free(removeNode);
    }
}