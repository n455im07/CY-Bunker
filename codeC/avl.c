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
    if(new==NULL){
        exit(1);
    }
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

int max(int a, int b){
    if (a > b){
        return a;
    }
    return b;
}

int min(int a, int b){
    if (a < b){
        return a;
    }
    return b;
}

AVL* rotationL (AVL* avl){
    AVL* pivot;
    int balA,balP;
    pivot = avl->right;
    avl->right=pivot->left;
    balA = avl->balance;
    balP = pivot->balance;
    avl->balance = balA - max(balP,0) - 1;
    pivot->balance = min(balA - 2,min(balA+balP -2,balP-1));
    avl = pivot;
    return avl;
}

AVL* rotationR (AVL* avl){
    AVL* pivot;
    int balA,balP;
    pivot = avl->left;
    avl->left=pivot->right;
    balA = avl->balance;
    balP = pivot->balance;
    avl->balance = balA - min(balP,0) + 1;
    pivot->balance = max(balA + 2,max(balA+balP + 2,balP+1));
    avl = pivot;
    return avl;
}

AVL* rotationDL (AVL* avl){
    avl->right = rotationDL(avl->right);
    return rotationL(avl);
}

AVL* rotationDR (AVL* avl){
    avl->left = rotationDR(avl->left);
    return rotationR(avl);
}

AVL* balanceAVL(AVL* avl){
    if (avl->balance >= 2){
        if (avl->right->balance >= 0){
            return rotationL(avl);
        }else{
            return rotationDL(avl);
        }
    }else if ( avl->balance <= -2){
        if (avl->left->balance <= 0){
            return rotationR(avl);
        }else{
            return rotationDR(avl);
        }
    }
    return avl;
}

AVL* insertAVL (AVL* avl, int data,int* h){
    if (avl==NULL){
        *h=1;
        return createAVL(data);
    }else if(data < avl->data){
        avl->left = insertAVL(avl->left,data,h);
        *h=-*h;
    }else if(data > avl->data){
        avl->right = insertAVL(avl->right,data,h);
    }else{
        *h=0;
        return avl;
    }if (*h != 0){
        avl->balance = avl->balance + *h;
        avl = balanceAVL(avl);
        if (avl->balance == 0){
            *h=0;
        }else{
            *h=1;
        }
    }
    return avl;
}

AVL* supprAVL(AVL* avl, int data, int* h){

    return avl;
}

void infixe(AVL* avl){
    if (avl != NULL){
        infixe(avl->left);
        printf("%d\n",avl->data);
        infixe(avl->right);
    }
}


int main(){
    AVL* root = NULL;
    root = createAVL(10);
    int h = 0;
    root = insertAVL(root,5,&h);
    root = insertAVL(root,15,&h);
    root = insertAVL(root,3,&h);
    root = insertAVL(root,7,&h);
    root = insertAVL(root,12,&h);
    root = insertAVL(root,17,&h);
    root = insertAVL(root,2,&h);
    root = insertAVL(root,4,&h);
    infixe(root);
    return 0;
}
