#include <stdio.h>
#include <stdlib.h>

typedef struct AVL {
    int id;
    int bf;
    struct AVL* left;
    struct AVL* right;

}AVL;

AVL* creationAVL(int id){
    AVL* new = malloc(sizeof(AVL));
    if( new == NULL){
        printf("creationAVL mallocfailed\n");
        exit (1);
    }   
    new -> bf = 0;
    new -> left = new -> right = NULL;
    new -> id = id;
    return new;
}

int max(int a,int b){
    return (a>b) ? a : b;
}

int min(int a,int b){
    return (a>b) ? b : a;
}

AVL* rotateLeft(AVL* avl){
    AVL* pivot;
    int ea,ep;
    if (avl == NULL){
        return avl;
    }
    pivot = avl->right;
    avl->right = pivot->left;
    pivot->left = avl;
    // Updating balance factor;
    ea = avl->bf;
    ep = pivot->bf;
   
    avl->bf = ea - max(ep,0) - 1;
    pivot->bf = min(ea - 2, min(ea+ep-2, ep-1));
    avl = pivot;
    return avl;
}

AVL* rotateRight(AVL* avl){
    AVL* pivot;
    int ea, ep;
    if (avl == NULL){
        return avl;
    }
    pivot = avl->left;
    avl->left = pivot->right;
    pivot->right = avl;
    // Updating balance factor;
    ea = avl->bf;
    ep = pivot->bf;
   
    avl->bf = ea - min(ep,0) + 1;
    pivot->bf = max(ea +2, max(ea+ep+2, ep+1));
    avl = pivot;
    return avl;
}

AVL* doubleR(AVL* avl){

avl -> left = rotateLeft(avl -> left);

return rotateRight(avl -> left);
    
}





int main(){
    printf("Hello world\n");
    return 0;
}
