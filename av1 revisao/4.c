#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int n;
    struct Node *next;
}Node;

void removeDuplicate(Node *head1,Node *tail1,Node **head2, Node **tail2);

int main(){

    return 0;
}

void removeDuplicate(Node *head1,Node *tail1,Node **head2, Node **tail2){
    Node *remove,*aux;
    while(head1!=NULL){
        int check=head1->n;
        //removendo head
        while(*head2!=NULL && (*head2)->n==check){
            remove=*head2;
            *head2=(*head2)->next;
            free(remove);
            if(*head2==NULL) *tail2=NULL;
        }
        //removendo tail
        while( *tail2!=NULL && (*tail2)->n==check){
            aux=*head2;
            while(aux->next!=NULL){
                if(aux->next->n==check){
                    remove=aux->next;
                    free(remove);
                    aux->next=NULL;
                    *tail2=aux;
                    break;
                }
                aux=aux->next;
            }
        }
        //removendo memio
        aux=*head2;
        while(aux->next!=NULL){
            if(aux->next->n==check){
                remove=aux->next;
                aux->next=aux->next->next;
                free(remove);
                if(aux->next==NULL) break;
            }
            aux=aux->next;
        }
        head1=head1->next;
    }

}