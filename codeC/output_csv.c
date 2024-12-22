#include <stdio.h>
#include <stdlib.h>

#include "include/avl.h"

//---- Write the data from the AVL tree in the file with the format "id:capacity:load"
void write_csv(AVL* avl, FILE* file){
    if (avl == NULL){
        return;
    }
    //---- In-order traversal
    write_csv(avl->left, file); 
    fprintf(file, "%d:%lld:%lld\n",avl->id, avl->capacity, avl->load);
    write_csv(avl->right, file);
}