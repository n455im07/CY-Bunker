#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

#include "include/avl.h"
#include "include/treat_dat.h"

int main(int argc, char* argv[]){

    for (int i = 0;i<argc;i++){
        printf("%d = %s\n",i,argv[i]);
    }
    const char* file_name = NULL;
    const char* head = NULL;
    file_name = argv[4];
    
    if(strcmp(argv[1],"hvb") == 0){ // HVB 
       head = "Station HV-B:Capacity:Consumption(company)";
    }
    if(strcmp(argv[1],"hva") == 0){ // HVA
       head = "Station HV-A:Capacity:Consumption(company)";
    }
    if (strcmp(argv[1], "lv") == 0 && strcmp(argv[2], "comp") == 0) { // LV Comp
        head = "Station LV:Capacity:Consumption(company)";
    }
    if (strcmp(argv[1], "lv") == 0 && strcmp(argv[2], "indiv") == 0) { // LV Indiv
        head = "Station LV:Capacity:Consumption(individuals)";
    }
    if (strcmp(argv[1], "lv") == 0 && strcmp(argv[2], "all") == 0) { // LV ALL
        head = "Station LV:Capacity:Consumption(all)";
    }    

    FILE* file = fopen(file_name, "w"); // Create the file 
    if (file == NULL) {
        printf("Error opening file\n");
        exit(1);
    }
    
    fprintf(file, "%s\n", head); // Write the head in the file
    fclose(file);
  
  

    AVL* avl = treatment(avl);
  
  
  
   // Others things to do here 



   
    return 0;
    
}
