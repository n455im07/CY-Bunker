#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

int main(int argc, char* argv[]){

    for (int i = 0;i<argc;i++){
        printf("%d = %s\n",i,argv[i]);
    }

    
    
    const char* file_name = NULL;
    const char* head = NULL;
    
    if(strcmp(argv[2],"hvb") == 0 && argc<5){ // HVB and no PP
       file_name = "tmp/hvb_comp.dat";
       head = "Station HV-B:Capacity:Consumption(company)";
    }
    else if (strcmp(argv[2], "hva") == 0 && argc < 5){ // HVA and no PP
       file_name = "tmp/hva_comp.dat";
       head = "Station HV-A:Capacity:Consumption(company)";
    }
    else if (strcmp(argv[2], "lv") == 0 && strcmp(argv[3], "comp") == 0 && argc < 5) { // LV and Comp and no PP
        file_name = "tmp/lv_comp.dat";
        head = "Station LV:Capacity:Consumption(company)";
    }
    else if (strcmp(argv[2], "lv") == 0 && strcmp(argv[3], "indiv") == 0) { // LV and Indiv and no PP
        file_name = "tmp/lv_indiv.dat";
        head = "Station LV:Capacity:Consumption(individuals)";
    }
    else if (strcmp(argv[2], "lv") == 0 && strcmp(argv[3], "all") == 0) { // LV ALL and no PP
        file_name = "tmp/lv_all.dat";
        head = "Station LV:Capacity:Consumption(all)";
    }





    
  // Create the file 
    FILE* file = fopen(file_name, "w");

    if (file == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    // Write the head in  the file
    fprintf(file, "%s\n", header);

   // Others things to do here 



    
    // Close the file
    fclose(file);

    printf("File written: %s\n", file_name);
    return 0;
    
}
