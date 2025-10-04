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
    Node *head=NULL,*tail=NULL;
    int n,k,m;

    while(1){

        scanf("%d %d %d",&n,&k,&m);
        if(n==0 && k==0 && m ==0) break;
        for(int i=1;i<n+1;i++) insertEnd(&head,&tail,i);
        search(&head,&tail,k,m);
    }
    printf("\n");
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
        for (int i=1;i<k-1;i++) auxRight=auxRight->next;
        for(int i=1;i<m;i++) auxLeft=auxLeft->prev;

        if(boolFirstPrint==0) printf(",");
        boolFirstPrint=0;

        if(auxLeft==auxRight){
            printf("   %d",auxLeft->n);
            
            Node *nextRight=auxRight->next;
            Node *prevLeft=auxLeft->prev;

            removeNode(head,tail,auxRight);
            
            if(*head==NULL) break;

            auxRight=nextRight;
            auxLeft=prevLeft;
        }
        else{

            printf("   %d   %d",auxRight->n,auxLeft->n);

            Node *nextRight=auxRight->next, *prevRight=auxRight->prev;
            Node *nextLeft=auxLeft->next, *prevLef=auxLeft->prev;
            
            Node *copyRight=auxRight, *copyLeft=auxLeft;

            removeNode(head,tail,auxRight);
            removeNode(head,tail,auxLeft);

            if(*head==NULL) break;
            //chegar
            if(nextRight==copyLeft) auxRight=nextLeft;
            else    auxRight=nextRight;

            if(prevLef==copyRight) auxLeft=prevRight;
            else auxLeft=prevLef; 

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



// void search(Node **head, Node **tail, int k, int m) {
//     if (*head == NULL) {
//         printf("\n");
//         return;
//     }

//     Node *cr = *head; // contador horário (começa em 1)
//     Node *cc = *tail; // contador anti-horário (começa em N)
//     int firstPrint = 1;

//     while (*head != NULL) {
//         // avança k-1 passos no sentido horário
//         for (int i = 1; i < k; i++) cr = cr->next;
//         // avança m-1 passos no sentido anti-horário
//         for (int i = 1; i < m; i++) cc = cc->prev;

//         if (!firstPrint) printf(",");
//         firstPrint = 0;

//         if (cr == cc) {
//             // ambos escolheram a mesma pessoa
//             printf("%3d", cr->n);
//             Node *next_cr = cr->next;
//             Node *prev_cc = cr->prev;
//             removeNode(head, tail, cr);
//             if (*head == NULL) break;
//             cr = next_cr;
//             cc = prev_cc;
//         } else {
//             // escolheram pessoas diferentes
//             printf("%3d%3d", cr->n, cc->n);

//             Node *a = cr, *b = cc;
//             Node *nextA = a->next, *prevA = a->prev;
//             Node *nextB = b->next, *prevB = b->prev;

//             // remove ambos (ordem não importa, pois usamos ponteiros salvos)
//             removeNode(head, tail, a);
//             removeNode(head, tail, b);

//             if (*head == NULL) break;

//             // se nextA era b (vizinhos), então o próximo válido depois de a é nextB
//             Node *new_cr = (nextA == b ? nextB : nextA);
//             // se prevB era a (vizinhos), então o anterior válido antes de b é prevA
//             Node *new_cc = (prevB == a ? prevA : prevB);

//             cr = new_cr;
//             cc = new_cc;
//         }
//     }

//     printf("\n");
// }