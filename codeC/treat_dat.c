#include <stdio.h>
#include <string.h> 
#include <stdlib.h>




int treatment(AVL* bidule){
    FILE* file = fopen("tmp/temp.dat","r+");
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
                if (column == 2){
                    id = atoi(token);
                }else if (column == 7){
                    capacity = atoll(token);
                }else if (column == 8){
                    load = atoll(token);
                }
                token = strtok(NULL, ";");
            }
            printf("id : %d, capacity : %lld, load : %lld\n",id,capacity,load);
            // APPEL AVL

        }
        fclose(file);
    }else{
        printf("Error opening file\n");
    }
    return 0;
}

int main(){
    return 0;
}