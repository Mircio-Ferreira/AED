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

//remocao
void remove_root(Tree **root,int key_remove);
Tree *maior_direita(Tree **root);

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


    printf("\n\n--- Removendo nós ---\n");

    printf("\nRemovendo 1 (folha)\n");
    remove_root(&root, 1);
    PrintInOrder(root);

    printf("\n\nRemovendo 14 (1 filho)\n");
    remove_root(&root, 14);
    PrintInOrder(root);

    printf("\n\nRemovendo 3 (2 filhos)\n");
    remove_root(&root, 3);
    PrintInOrder(root);

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
    
    if(root==NULL) return -1;

    int left = lenght_Tree(root->left);
    int right = lenght_Tree(root->right);

    if(left>right) left++;
    else right++;
    
}




Tree *maior_direita(Tree **root){
    if((*root)->right==NULL){
        Tree *aux=*root;
        if((*root)->left!=NULL){
            *root=(*root)->left;         
        }
        else *root=NULL;
        return aux;
    }
    else return maior_direita(&(*root)->right); 
}


void remove_root(Tree **root,int key_remove){
    if(*root==NULL) return;
    
    else if((*root)->key > key_remove) remove_root(&(*root)->left,key_remove);
    else if((*root)->key < key_remove) remove_root(&(*root)->right,key_remove);

    else{
        if((*root)->right==NULL && (*root)->left==NULL ){// sem filhos
            free(*root);
            *root=NULL;
        }
        else if((*root)->right==NULL ^ (*root)->left==NULL){ // 1 filho
            Tree *aux=*root;
            if((*root)->right!=NULL) *root=(*root)->right;
            else *root=(*root)->left;
            free(aux);
        }
        else{
            Tree *aux=maior_direita(&(*root)->left);
            aux->right=(*root)->right;
            aux->left=(*root)->left;
            free(*root);
            *root=aux;
        }
    }
}

