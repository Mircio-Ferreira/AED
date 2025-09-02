#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    char c;
    struct Node *next;
}Node;

void push(Node **head,char c);

void pop(Node **head);

int main(){
    Node *head=NULL;
    int vagao=-1;
    while(1){
        head=NULL;
        scanf("%d",&vagao);
        if(vagao==0)break;
        char entrada[vagao],saida[vagao];

        for(int i=0;i<vagao;i++) scanf(" %c",&entrada[i]);
        for(int i=0;i<vagao;i++) scanf(" %c",&saida[i]);
           
    }
    return 0;
}

void push(Node **head,char c){
    Node *new=malloc(sizeof(Node));
    new->c=c;
    new->next=*head;
    *head=new;
}

void pop(Node **head){
    if(*head!=NULL){
        Node *delete=*head;
        *head=(*head)->next;
        free(delete);
    }
}