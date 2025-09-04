#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int n;
    struct Node *next;
}Node;

void excluirIguais(Node *head1,Node *tail1,Node **head2, Node **tail2);

int main(){

    return 0;
}

void excluirIguais(Node *head1,Node *tail1,Node **head2, Node **tail2){
    Node *remove;
    while(head1!=NULL){
        int check=head1->n;
        while(head2!=NULL && (*head2)->n==check){
            remove=*head2;
            (*head2)=(*head2)->next;
            free(remove);
        }
        Node *aux=*head2;
        while(aux!=NULL && aux->next!=NULL){ // a primeira condicao do while resolve o caso de o aux for nulo para a seguinte n acessar um campo invalido

            //remocao de meio e tail
                if(aux->next->n==check){ // sei que tenho que remover o proximo em relação ao atual!
                    remove=aux->next; // qual o que eu vo ter que da free
                    if(*tail2==aux->next){ // sei que to em um caso especial que é a remoção de tail e não de meio
                        *tail2=aux;       // levo a tail para o anterior
                    }
                    aux->next=aux->next->next;   // serve para o meu atual receber o proximo do proximo e serve tanto para uma remocao do meio e no caos da tail ( que o proximo proximo seria null)
                    free(remove);
                    continue;
                }
        
            aux=aux->next;
        }
        head1=head1->next;
    }
}