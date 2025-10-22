#include <stdio.h>
#include <stdlib.h>

typedef struct Tree{
    int key;
    struct Tree *right;
    struct Tree *left;
}Tree;

// ---- Prints de árvore ----
void PreOrdemRED(Tree *root);
void inOrdemERD(Tree *root);
void PosOrdemEDR(Tree *root);

// ---- Insert ---- 
void insertTree(Tree **root,int key);

// ---- Search ----
int searchTree(Tree *root,int key);

// ---- Remove ----
void removeTree(Tree **root,int key);

int main(){

    Tree *root=NULL;

    insertTree(&root,50);
    insertTree(&root, 30);
    insertTree(&root, 70);
    insertTree(&root, 20);
    insertTree(&root, 40);
    insertTree(&root, 60);
    insertTree(&root, 80);

    PreOrdemRED(root);
    printf("\n");

    inOrdemERD(root);
    printf("\n");

    PosOrdemEDR(root);
    printf("\n");

    printf("\n");
    printf("\n");

    
    if(searchTree(root,30)) printf("achou!\n");
    else printf("nao achou!\n");


    return 0;
}

void PreOrdemRED(Tree *root){
    if(root!=NULL){
        printf("|%d|",root->key);
        PreOrdemRED(root->left);
        PreOrdemRED(root->right);
    }
}

void inOrdemERD(Tree *root){
    if(root!=NULL){
        inOrdemERD(root->left);
        printf("|%d|",root->key);
        inOrdemERD(root->right);
    }
}

void PosOrdemEDR(Tree *root){
    if(root!=NULL){
        PosOrdemEDR(root->left);
        PosOrdemEDR(root->right);
        printf("|%d|",root->key);
    }
}

/* Analogia : 
✅ root → Tree **
✅ *root → Tree * (nó atual)
✅ (*root)->left → Tree * (subárvore esquerda)
✅ &(*root)->left → Tree ** (endereço do ponteiro da esquerda → o que a função espera)
*/
void insertTree(Tree **root,int key){
    if(*root==NULL){
        *root=malloc(sizeof(Tree));
        (*root)->left=NULL;
        (*root)->right=NULL;
        (*root)->key=key;
    }
    else{
        if((*root)->key > key) insertTree(&(*root)->left,key);

        else if((*root)->key < key) insertTree(&(*root)->right,key);
    }
}


int searchTree(Tree *root,int key){
    if(root == NULL) return 0;
    else if (root->key == key) return 1;
    else if(root->key > key) return searchTree(root->left,key);
    else if(root->key < key) return searchTree(root->right,key);

    // para compilador nao reclamar
    return 0;
}

void removeTree(Tree **root,int key){
    if(*root ==NULL) return;
    else if( (*root)->key> key ) removeTree(&(*root)->left,key);
    else if( (*root)->key< key ) removeTree(&(*root)->right,key);
    else{// achou
        if((*root)->right== NULL && (*root)->left==NULL){ //sem filhos
            free(*root);
            *root=NULL;
        }
        else if((*root)->right==NULL ^ (*root)->left==NULL){ //So tem um filho
            Tree *aux=*root;
            if( (*root)->right!=NULL ) *root=(*root)->right;
            else *root=(*root)->left;
            free(aux);
        }
        else{

        }
    }
}