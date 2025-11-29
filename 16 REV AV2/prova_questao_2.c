#include <stdio.h>
#include <stdlib.h>

typedef struct Tree{
    int key;
    struct Tree *right;
    struct Tree *left;
}Tree;

void insert(Tree **root,int key);
void pre_order(Tree *root);

int check(Tree *root);

int main(){

    

    return 0;
}


void insert(Tree **root,int key){
    if(*root == NULL){
        *root=malloc(sizeof(Tree));
        (*root)->key=key;
        (*root)->left=NULL;
        (*root)->right=NULL;
    }
    else{
        if((*root)->key < key) insert(&(*root)->right,key);
        else if( (*root)->key > key) insert(&(*root)->left,key); 
    }
}

void pre_order(Tree *root){
    if(root!=NULL){
        printf("|%d|",root->key);
        pre_order(root->left);
        pre_order(root->right);
    }
}


int check(Tree *root){
    if(root!=NULL){
        if(root->right==NULL && root->left==NULL) return 1;
        if(root->right!=NULL ^ root->left!=NULL) return 0;
        return check(root->right) * check(root->left);
    }
    return 1;    
}