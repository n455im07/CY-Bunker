#include <stdio.h>
#include <stdlib.h>

#include "include/avl.h"

void write_csv(AVL* pavl, FILE* file){
    if (pavl == NULL){
        return;
    }
    write_csv(pavl->left, file);
    fprintf(file, "%d:%lld:%lld\n",pavl->id, pavl->capacity, pavl->load);
    write_csv(pavl->right, file);
}

