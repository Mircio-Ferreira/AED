/* 
01 - Crie uma função que indique se um determinado valor está presente na lista (primeira ocorrência) 

- Retorne 0 se o valor não estiver na lista 

- Retorne 1 se o valor estiver na lista
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int n;
    struct Node *next;
}Node;

int checkNumber(int numberCheck, Node *head){

    while(head!=NULL){
        if(head->n == numberCheck) return 1;
        head=head->next;
    }
    return 0;

}

int main(){

    Node *head=NULL;

    return 0;
}


