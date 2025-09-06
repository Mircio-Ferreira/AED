/*
QUESTÃO 04 - Considere que um programa em C manipula duas Filas (Fila01 e Fila02) e
agora é necessário que seja implementada uma nova função que verifique se existem
valores repetidos entre as filas, caso tenha valor repetido, deve ser removido apenas da
Fila2;.
Protótipo da função: void excluirIguais(Node *head1,Node *tail1, Node **head2,
Node **tail2);
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int n;
    struct Node *next;
}Node;

void removeDuplicate(Node *head1,Node **head2,Node **tail2);

int main(){

    return 0;
}


void removeDuplicate(Node *head1,Node **head2,Node **tail2){
    
}