#include <stdio.h>
#include <stdlib.h>

typedef struct Tree{
    int key;
    struct Tree *right;
    struct Tree *left;
}Tree;

//inserçao
void insert(Tree **root,int key);

//print
void pre_order(Tree *root);
void in_order(Tree *root);
void pos_order(Tree *root);

//buscar
int search(Tree *root,int key);

int main(){

    Tree *root=NULL;

    //for(int i=0;i<10;i++) insert(&root,i);

    insert(&root, 10);
    insert(&root, 5);
    insert(&root, 15);
    insert(&root, 3);
    insert(&root, 7);
    insert(&root, 13);
    insert(&root, 18);
    insert(&root, 1);
    insert(&root, 4);
    insert(&root, 6);
    insert(&root, 8);
    insert(&root, 12);
    insert(&root, 14);
    insert(&root, 17);
    insert(&root, 20);

    pre_order(root);
    printf("\n");
    in_order(root);
    printf("\n");
    pos_order(root);
    printf("\n");

    //printf("buscas : %d %d %d",search(root,5),search(root,111),search(root,-2));

    for(int i=0;i<11;i++) printf("|%d|",search(root,i));

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

void in_order(Tree *root){
    if(root!=NULL){
        in_order(root->left);
        printf("|%d|",root->key);
        in_order(root->right);
    }
}

void pos_order(Tree *root){
    if(root!=NULL){
        pos_order(root->left);
        pos_order(root->right);
        printf("|%d|",root->key);
    }
}


int search(Tree *root,int key){
    if(root==NULL) return 0;
    if(root->key==key) return 1;
    else if(root->key>key)  return search(root->left,key);
    else if(root->key<key) return  search(root->right,key);
}