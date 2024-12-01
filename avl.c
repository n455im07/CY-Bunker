#include <stdio.h>
#include <stdlib.h>

typedef struct AVL{
    int balance;
    int data;
    struct AVL* left;
    struct AVL* right;
} AVL;

AVL* createAVL(int data){
    AVL* new = malloc(sizeof(AVL));
    new->data = data;
    new->balance = 0;
    new->left = NULL;
    new->right = NULL;
    return new;
}

int searchAVL(AVL* avl,int data){
    if (avl == NULL){
        return 0;
    }
    if (avl->data == data){
        return 1;
    }
    if (avl->data < data && avl->right != NULL){
        return searchAVL(avl->right,data);
    }
    if (avl->data > data && avl->left !=NULL){
        return searchAVL(avl->left,data);
    }
}

int main(){

    return 0;
}