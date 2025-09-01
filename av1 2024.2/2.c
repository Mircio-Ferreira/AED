#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int n;
    struct Node *next;
}Node;

void doubleFila(int delemitador,Node *head,Node *tail,Node **newHead01,Node **newTail01,Node **newHead02,Node **newTail02);


void imprimirFila(Node *head){
    while(head != NULL){
        printf("%d ", head->n);
        head = head->next;
    }
    printf("\n");
}

// Função para inserir na fila (opcional, não muda tua doubleFila)
void inserirNo(Node **head, Node **tail, int valor){
    Node *new = malloc(sizeof(Node));
    new->n = valor;
    new->next = NULL;
    if(*head == NULL) *head = *tail = new;
    else {
        (*tail)->next = new;
        *tail = new;
    }
}


int main(){
    // Criando a fila original
    Node *head=NULL, *tail=NULL;
    int valores[] = {1,2,3,4,5}; // exemplo de fila
    int tamanho = sizeof(valores)/sizeof(valores[0]);
    for(int i=0;i<tamanho;i++){
        inserirNo(&head, &tail, valores[i]);
    }

    printf("Fila original: ");
    imprimirFila(head);

    // Inicializando as novas filas
    Node *newHead01=NULL, *newTail01=NULL;
    Node *newHead02=NULL, *newTail02=NULL;

    int delimitador = 3; // teste com delimitador existente
    doubleFila(delimitador, head, tail, &newHead01, &newTail01, &newHead02, &newTail02);

    printf("Fila 1: ");
    imprimirFila(newHead01);

    printf("Fila 2: ");
    imprimirFila(newHead02);

    return 0;
}


void doubleFila(int delemitador,Node *head,Node *tail,Node **newHead01,
    Node **newTail01,Node **newHead02,Node **newTail02){
        int cont=0,stop=-1;
        Node *backUpHead=head;
        while(head!=NULL){
            cont++;
            if(head->n==delemitador) stop=cont-1;
            head=head->next;
        }
        head=backUpHead;
        if(stop!=-1){//Tenho delemitador
            for(int i=0;i<stop;i++){
                Node *new=malloc(sizeof(Node));
                new->n=head->n;
                new->next=NULL;
                if(*newHead01==NULL) *newHead01=*newTail01=new;
                else{
                    (*newTail01)->next=new;
                    *newTail01=new;
                }
                head=head->next;
            }
            while(head!=NULL){
                Node *new=malloc(sizeof(Node));
                new->n=head->n;
                new->next=NULL;
                if(*newHead02==NULL) *newHead02=*newTail02=new;
                else{
                    (*newTail02)->next=new;
                    *newTail02=new;
                }
                head=head->next;
            }   
        }
        else{ // ou seja n tenho delimitador
            int par=0;
            if(cont%2==0) par=1;
            for(int i=0;i<cont/2;i++){
                Node *new=malloc(sizeof(Node));
                new->n=head->n;
                new->next=NULL;
                if(*newHead01==NULL) *newHead01=*newTail01=new;
                else{
                    (*newTail01)->next=new;
                    *newTail01=new;
                }
                head=head->next;
            }
            if(!par){//se par for falso, entao eu coloco mais um numero
                Node *new=malloc(sizeof(Node));
                new->n=head->n;
                (*newTail01)->next=new;
                *newTail01=new;
                head=head->next;
            }
            for(int i=0;i<cont/2;i++){
                Node *new=malloc(sizeof(Node));
                new->n=head->n;
                new->next=NULL;
                if(*newHead02==NULL) *newHead02=*newTail02=new;
                else{
                    (*newTail02)->next=new;
                    *newTail02=new;
                }
                head=head->next;
            }
        }
    
}