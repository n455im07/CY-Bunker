#include <stdio.h>
#include <stdlib.h>

#include "include/avl.h"


void write_csv(AVL* avl, FILE* file){
    if (avl == NULL){
        return;
    }
    write_csv(avl->left, file);
    fprintf(file, "%d:%lld:%lld\n",avl->id, avl->capacity, avl->load);
    write_csv(avl->right, file);
}

void write_csv_minmax(AVL* avl, FILE* file) {
    if (avl == NULL || file == NULL) {
        return;
    }

    AVL* current = avl;
    
    for (int i = 0; i < 10 && current != NULL; i++) {
        // Store initial values
        long long max = current->load;
        long long min = current->load;
        AVL* maxAVL = NULL;
        AVL* minAVL = NULL;

        // Find max and min nodes
        maxConsAVL(current, &max, &maxAVL);
        minConsAVL(current, &min, &minAVL);

        // Validate found nodes
        if (maxAVL == NULL || minAVL == NULL) {
            break;
        }

        // Store node info before removal
        int maxId = maxAVL->id;
        int minId = minAVL->id;
        long long maxLoad = maxAVL->load;
        long long minLoad = minAVL->load;
        long long maxCap = maxAVL->capacity;
        long long minCap = minAVL->capacity;

        // Write to file
        fprintf(file, "%d:%lld:%lld\n", maxId, maxCap, maxLoad);
        fprintf(file, "%d:%lld:%lld\n", minId, minCap, minLoad);

        // Remove nodes with validation
        int h = 0;
        current = removeAVL(current, maxId, &h);
        if (current == NULL) break;
        
        current = removeAVL(current, minId, &h);
        if (current == NULL) break;
    }
}
