#include<stdio.h>
#include <stdlib.h>

typedef struct Node{
    int n;
    struct Node *next;
}Node;

void troca(Node **head1,Node **head2);

int main(){
    
    return 0;
}


void troca(Node **head1,Node **head2){
    if(*head1!=NULL && *head2!=NULL){
        Node *temp=*head1;
        Node *tempNext1=(*head1)->next;
        Node *tempNext2=(*head2)->next;
        *head1=*head2;
        (*head1)->next=tempNext1;
        *head2=temp;
        (*head2)->next=tempNext2;
        
    }
}
