#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int n;
    struct Node *prev;
    struct Node *next;
} Node;

void insertBeging(Node **head, Node **tail, int n);
void insertEnd(Node **head, Node **tail, int n);
void removeBeging(Node **head, Node **tail);
void removeEnd(Node **head,Node **tail);

int main()
{
    Node *head = NULL, *tail = NULL;

    return 0;
}

void insertBeging(Node **head, Node **tail, int n)
{
    Node *new = malloc(sizeof(Node));
    new->n = n;
    new->prev = NULL;
    new->next = *head;
    if (*head == NULL)
        *head = *tail = new;
    else
    {
        (*head)->prev = new;
        *head = new;
    }
}

void insertEnd(Node **head, Node **tail, int n)
{
    Node *new = malloc(sizeof(Node));
    new->n = n;
    new->next = NULL;
    if (*head == NULL)
    {
        *head = *tail = new;
        new->prev = NULL;
    }
    else
    {
        (*tail)->next = new;
        new->prev = *tail;
        *tail = new;
    }
}

void removeBeging(Node **head, Node **tail)
{
    if (*head)
    {
        Node *remove = *tail;
        *tail = (*tail)->prev;
        if (*tail!=NULL) (*tail)->next = NULL;
        else *head=NULL;
        free(remove);
    }
}


void removeEnd(Node **head,Node **tail){
    if(*head){
        Node *remove=*tail;
        *tail=(*tail)->prev;
        if(*tail==NULL) *head=NULL;
        else (*tail)->next=NULL;
        free(remove);
    }
}