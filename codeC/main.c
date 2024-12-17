#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

int main(int argc, char* argv[]){

    for (int i = 0;i<argc;i++){
        printf("%d = %s\n",i,argv[i]);
    }
    
    const char* file_name = NULL;
    const char* head = NULL;
    file_name = argv[5];
    
    if(strcmp(argv[2],"hvb") == 0){ // HVB 
       head = "Station HV-B:Capacity:Consumption(company)";
    }
    if(strcmp(argv[2],"hva") == 0){ // HVA
       head = "Station HV-A:Capacity:Consumption(company)";
    }
    if (strcmp(argv[2], "lv") == 0 && strcmp(argv[3], "comp") == 0) { // LV Comp
        head = "Station LV:Capacity:Consumption(company)";
    }
    if (strcmp(argv[2], "lv") == 0 && strcmp(argv[3], "indiv") == 0) { // LV Indiv
        head = "Station LV:Capacity:Consumption(individuals)";
    }
    if (strcmp(argv[2], "lv") == 0 && strcmp(argv[3], "all") == 0) { // LV ALL
        head = "Station LV:Capacity:Consumption(all)";
    }    
    
    // Create the file 
    FILE* file = fopen(file_name, "w");
    if (file == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    // Write the head in  the file
    fprintf(file, "%s\n", head);

   // Others things to do here 
    
    // Close the file
    fclose(file);

    printf("File written: %s\n", file_name);
    return 0;
    
}
