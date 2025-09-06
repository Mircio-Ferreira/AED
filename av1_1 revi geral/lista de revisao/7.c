/*
QUESTÃO 07 - Considere que um programa em C manipula duas Pilhas (Pilha01 e
Pilha02) e agora é necessário que seja implementada uma nova função que realiza a
troca do primeiro elemento entre as pilhas (o primeiro nó que está na Pilha01 vai para
a Pilha02 E o primeiro nó que estava na Pilha02 vai para a Pilha01).
Protótipo da função: void troca(Node **head1, Node **head2);
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int n;
    struct Node *next;
}Node;
