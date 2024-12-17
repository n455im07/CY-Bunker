#ifndef AVL_H
#define AVL_H

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


// Function Prototypes
AVL* creationAVL(int id, long long capacity, long long load);
int max(int a, int b);
int min(int a, int b);
AVL* rotateLeft(AVL* avl);
AVL* rotateRight(AVL* avl);
AVL* doubleRight(AVL* avl);
AVL* doubleLeft(AVL* avl);
AVL* balanceAVL(AVL* avl);
AVL* insertAVL(AVL* avl, int id, int* h, long long capacity, long long load);
void infixe(AVL* avl);

#endif // AVL_H
