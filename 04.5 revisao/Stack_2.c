#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    char c;
    struct Node *next;
}Node;

void push(Node **head,char c){
    Node *new=malloc(sizeof(Node));
    new->c=c;
    new->next=*head;
    *head=new;
}

int peak(Node *head,char c){
    return (head->c==c) ? 1 : 0 ;
}

void pop(Node **head){
    if(head!=NULL){
        Node *temp=*head;
        *head=(*head)->next;
        free(temp);
    }
}

int main(){
    Node *head=NULL;
    char banlanceamento[9]="[{[()]}]";

    for(int i=0;i<9;i++){
        if(banlanceamento[i]=='(' ||banlanceamento[i]=='[' || banlanceamento[i]=='{'){
            push(&head,banlanceamento[i]);
        }
        else{
            if(peak(head,banlanceamento[i])) pop(&head);
        }
    }

    (head==NULL) ? printf("deu certo") : printf("nao deu certo");

    return 0;
}