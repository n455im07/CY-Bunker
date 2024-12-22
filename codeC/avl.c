#include <stdio.h>
#include <stdlib.h>

// Structure for AVL Tree Node
typedef struct AVL {
    int id;             // Value of the node
    long long capacity; // Capacity of the node
    long long load;     // Load of the node
    int bf;             // Balance Factor
    struct AVL* left;   // Pointer to left child
    struct AVL* right;  // Pointer to right child
} AVL;

//---- Create a new AVL node with the given values
AVL* creationAVL(int id, long long capacity , long long load){
    AVL* new = malloc(sizeof(AVL));
    if( new == NULL){
        printf("creationAVL malloc failed\n");
        exit (1);
    }   
    new->bf = 0;
    new->left = NULL;
    new->right = NULL;
    new->id = id;
    new->capacity= capacity;
    new->load=load;
    return new;
}

int max(int a,int b){
    return (a>b) ? a : b; // If a is greater than b, return a, else return b
}

int min(int a,int b){
    return (a>b) ? b : a; // If a is greater than b, return b, else return a
}

AVL* rotateLeft(AVL* avl){
    AVL* pivot;
    int ea,ep;
    if (avl == NULL){
        return avl;
    }
    //---- Rotate
    pivot = avl->right;
    avl->right = pivot->left;
    pivot->left = avl;
    
    //---- Updating balance factor
    ea = avl->bf;
    ep = pivot->bf;
    avl->bf = ea - max(ep,0) - 1; // Balance factor of the avl
    pivot->bf = min(ea - 2, min(ea+ep-2, ep-1)); // Balance factor of the pivot
    
    avl = pivot;
    return avl;
}

AVL* rotateRight(AVL* avl){
    AVL* pivot;
    int ea, ep;
    if (avl == NULL){
        return avl;
    }
    //---- Rotate
    pivot = avl->left;
    avl->left = pivot->right;
    pivot->right = avl;

    //---- Updating balance factor
    ea = avl->bf;
    ep = pivot->bf;
    avl->bf = ea - min(ep,0) + 1; // Balance factor of the avl
    pivot->bf = max(ea +2, max(ea+ep+2, ep+1)); // Balance factor of the pivot
    
    avl = pivot;
    return avl;
}

AVL* doubleRight(AVL* avl){ // Left rotation on the left child and right rotation on the avl
    avl -> left = rotateLeft(avl->left);
    return rotateRight(avl);
}

AVL* doubleLeft(AVL* avl){ // Right rotation on the right child and left rotation on the avl
    avl->right = rotateRight(avl->right);
    return rotateLeft(avl);
}


//---- Balance the AVL tree if the balance factor is greater than 2 or less than -2
AVL* balanceAVL(AVL* avl){
    if ( avl->bf >= 2){
        if ( avl->right != NULL && avl->right->bf >= 0){ // If same sign
            return rotateLeft(avl);
        }
        else{ // If different sign
            return doubleLeft(avl);
        }
    }
    if ( avl->bf <= -2){
        if ( avl->left != NULL && avl -> left -> bf <= 0){ // If same sign
            return rotateRight(avl);
        }
        else{ // If different sign
            return doubleRight(avl);
        }
    }
  return avl;
}


//---- Insert a new node in the AVL tree
AVL* insertAVL(AVL* avl,int id,int* h, long long capacity, long long load){
    if (avl==NULL){
        *h=1;
        return creationAVL(id,capacity,load); // If the AVL node doesn't exist, create it
    } else if (id < avl->id){
        avl->left = insertAVL(avl->left,id,h,capacity,load); // Recursive call to insert the node with AVL logic
        *h=-*h;
    } else if (id > avl->id){
        avl->right = insertAVL(avl->right,id,h,capacity,load); // Recursive call to insert the node with AVL logic
    }
    else{
        *h=0;
        avl->load+=load; // If the node already exists, sum the load
        return avl;
    }
   
    if (*h!=0){ // If the balance variable is different from 0
        //---- Update the balance factor and balance the AVL tree
        avl->bf+=*h;
        avl = balanceAVL(avl);
        *h = (avl->bf==0) ? 0 : 1 ; // *h = 0 if the balance factor is 0, else *h = 1
    }
    return avl;
}

AVL* freeAVL(AVL* avl) { // Free the AVL tree
    if (avl == NULL) {
        return NULL;
    }
    // Free children using recursion
    freeAVL(avl->left);
    freeAVL(avl->right);

    // Free the node
    free(avl);
    return NULL;
}