#include <stdio.h>
#include <string.h> 
#include <stdlib.h>

int main(){

    FILE* file = fopen("tmp/temp.dat","r+");
    char chaine[100]="";
    double truc[2]={0};

    //i/f (file!=NULL){
        
        //fscanf(file, "%d;%d;%d;%d;%d;%d;%lf",&chaine[0],&chaine[1],&chaine[2],&chaine[3],&chaine[4],&chaine[5],&truc[0]);
        //printf("%d", chaine[1]);

        //while (fgets(chaine, sizeof(file), file) != NULL){
        //    printf("%s",chaine);
        //}
        
        //fclose(file);

    //}





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
    }
fclose(file);

                    

                                                                     

        
    return 0;
}