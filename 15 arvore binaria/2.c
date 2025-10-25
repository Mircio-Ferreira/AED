#include <stdlib.h>
#include <stdio.h>

typedef struct Tree{
    int key;
    struct Tree *right;
    struct Tree *left;
}Tree;

//RED
void printPreOrder(Tree *root){
    if(root!=NULL){
        printf("|%d|",root->key);
        printPreOrder(root->left);
        printPreOrder(root->right);
    }
}
//ERD
void printInOrder(Tree *root){
    if(root!=NULL){
        printInOrder(root->left);
        printf("|%d|",root->key);
        printInOrder(root->right);
    }
}
//EDR
void printPosOrder(Tree *root){
    if(root!=NULL){
        printPosOrder(root->left);
        printPosOrder(root->right);
        printf("|%d|",root->key);
    }
}

void insertTreeABB(Tree **root,int keyInsert){
    if(*root==NULL){
        *root=malloc(sizeof(Tree));
        (*root)->right=NULL;
        (*root)->left=NULL;
        (*root)->key=keyInsert;
    }
    else{
        if( (*root)->key> keyInsert) insertTreeABB(&(*root)->left,keyInsert);
        else if( (*root)->key < keyInsert) insertTreeABB(&(*root)->right,keyInsert);
    }
}

Tree *SearchTreeRoot(Tree *root,int keySearch){
    if(root==NULL) return NULL;
    else if(root->key==keySearch) return root;
    else if(root->key > keySearch) return SearchTreeRoot(root->left,keySearch);
    else if(root->key < keySearch) return SearchTreeRoot(root->right,keySearch);
    return NULL;
}

//01- Crie uma função (recursiva) que retorne o nó que apresentar a chave de maior valor na árvore.

int BiggestKeyTree(Tree *root){
    if(root!=NULL){
        if(root->right==NULL) return root->key;
        else return BiggestKeyTree(root->right);
    }
    return -1;//Valor Default
}

//02 - Crie uma função recursiva em C que retorne a altura da árvore.

int heightTree(Tree *root){
    if(root==NULL) return -1;

    int heightLeft = heightTree(root->left);
    int heightRight = heightTree(root->right);

    if(heightLeft > heightRight) return heightLeft+1;
    else return heightRight+1;
}

//03 - Crie uma função recursiva em C que imprima as folhas da árvore.

void printTreeLeaf(Tree *root){
    if(root!=NULL){
        if(root->right==NULL && root->left==NULL) printf("|%d|",root->key);
        printTreeLeaf(root->left);
        printTreeLeaf(root->right);
    }
}

int main(){

    return 0;
}