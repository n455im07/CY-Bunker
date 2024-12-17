#include <stdio.h>
#include <string.h> 
#include <stdlib.h>

#include "include/avl.h"

AVL* treatment(AVL* pavl, char* stationType){
    FILE* file = fopen("tmp/temp.csv","r+");
    char chaine[50]="";

    if (file != NULL){
        while (fgets(chaine, sizeof(chaine), file) != NULL){
            int id = 0;
            long long capacity = 0;
            long long load = 0;
            char* token;
            token = strtok(chaine, ";");
            int column = 0;
            while (token != NULL){
                column++;
                if (strcmp(stationType, "hvb") == 0    && column == 2){
                    id = atoi(token);
                }
                if (strcmp(stationType, "hva") == 0    && column == 3){
                    id = atoi(token);
                }
                if (strcmp(stationType, "lv") == 0    && column == 4){
                    id = atoi(token);
                }
                else if (column == 7){
                    capacity = atoll(token);
                }else if (column == 8){
                    load = atoll(token);
                }
                token = strtok(NULL, ";");
            }
            // Calling AVL
            int h = 0;
            pavl = insertAVL(pavl, id, &h, capacity, load);
        }
        fclose(file);
    }else{
        printf("Error opening file\n");
    }
    infixe(pavl);
    return pavl;
}