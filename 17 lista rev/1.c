#include <stdio.h>
#include <stdlib.h>

typedef struct Tree{
    int key;
    struct Tree *right;
    struct Tree *left;
}Tree;

void fihosEsquerdos(Tree* root){
    if(root!=NULL){
        if(root->left!=NULL) printf("|%d|",root->left->key);
        fihosEsquerdos(root->left);
        fihosEsquerdos(root->right);
    }
}