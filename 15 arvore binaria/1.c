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

int main(){

    return 0;
}

void PreOrdemRED(Tree *root){
    if(root!=NULL){
        printf("|%d|",root->key);
        printRED(root->left);
        printRED(root->right);
    }
    printf("\n");
}

void inOrdemERD(Tree *root){
    if(root!=NULL){
        inOrdemERD(root->left);
        printf("%d",root->key);
        inOrdemERD(root->right);
    }
    printf("\n");
}

void PosOrdemEDR(Tree *root){
    if(root!=NULL){
        PosOrdemEDR(root->left);
        PosOrdemEDR(root->right);
        PosOrdemEDR(root->key);
    }
}