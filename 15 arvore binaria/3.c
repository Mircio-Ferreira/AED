#include <stdio.h>
#include <stdlib.h>

typedef struct Tree{
    int key;
    struct Tree *right;
    struct Tree *left;
}Tree;

//insert ABB
void insert_Tree(Tree **root,int key);

//print arvore ABB
void PrintPreOrder(Tree *root);
void PrintInOrder(Tree *root);
void PrintPosOrder(Tree *root);

void printLeaf(Tree *root);

//retorno de key
void Bigest_key(Tree *root);
void Smaller_key(Tree *root);

int lenght_Tree(Tree *root);

int main(){
    Tree *root=NULL;
    insert_Tree(&root, 8);
    insert_Tree(&root, 3);
    insert_Tree(&root, 10);
    insert_Tree(&root, 1);
    insert_Tree(&root, 6);
    insert_Tree(&root, 14);
    insert_Tree(&root, 4);
    insert_Tree(&root, 7);
    insert_Tree(&root, 13);

    printf("\n--- Pre-Ordem ---\n");
    PrintPreOrder(root);

    printf("\n\n--- Em-Ordem ---\n");
    PrintInOrder(root);

    printf("\n\n--- Pos-Ordem ---\n");
    PrintPosOrder(root);

    printf("\n\n--- folhas ---\n");
    printLeaf(root);


    Bigest_key(root);
    Smaller_key(root);

    return 0;
}

void insert_Tree(Tree **root,int key){
    if(*root==NULL){
        *root=malloc(sizeof(Tree));
        (*root)->key=key;
        (*root)->right=NULL;
        (*root)->left=NULL;
    }
    else{
        if((*root)->key > key) insert_Tree(&(*root)->left,key);
        if((*root)->key < key) insert_Tree(&(*root)->right,key);
    }
}

void PrintPreOrder(Tree *root){
    if(root!=NULL){
        printf("|%d|",root->key);
        PrintInOrder(root->left);
        PrintInOrder(root->right);
    }
}
void PrintInOrder(Tree *root){
    if(root!=NULL){
        PrintInOrder(root->left);
        printf("|%d|",root->key);
        PrintInOrder(root->right);
    }
}
void PrintPosOrder(Tree *root){
        if(root!=NULL){
        PrintInOrder(root->left);
        PrintInOrder(root->right);
        printf("|%d|",root->key);
    }
}

void Bigest_key(Tree *root){
    if(root!=NULL){
        if(root->right==NULL) printf("\nmaior valor: %d\n",root->key);
        else Bigest_key(root->right);
    }
}
void Smaller_key(Tree *root){
    if(root!=NULL){
        if(root->left==NULL) printf("\nmenor valor: %d\n",root->key);
        else Smaller_key(root->left);
    }
}

void printLeaf(Tree *root){
    if(root!=NULL){
        if(root->right==NULL && root->left==NULL) printf("|%d|",root->key);
        else{
            printLeaf(root->left);
            printLeaf(root->right);
        }
    }
}

int lenght_Tree(Tree *root){
    return 0;
}