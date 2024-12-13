#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

int main(int argc, char* argv[]){

// ./exe temp.dat $station_type $consumer_type $power_plant_id

    // File creation
    
    for (int i = 0;i<argc;i++){
        printf("%d = %s\n",i,argv[i]);
    }
    const char* file_name = NULL;
    
    if(strcmp(argv[2],"hvb") == 0 && argc<5){ // HVB and no PP
       file_name = "tmp/hvb_comp.dat";
    }
    
    FILE* file = fopen(file_name, "w");

    if ( file == NULL){
        printf("Error");
        exit(1);
    }

   fprintf(file, "Station HV-B:Capacity:Consumption(company)");





    return 0;
}
