#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

int main(int argc, char* argv[]){

// ./exe temp.dat $station_type $consumer_type $power_plant_id

    // File creation
    
    
    //const char* file_name = NULL;
    
   // if(strcmp(argv[2],"hvb") == 0 && argc<5){
      //  file_name = "../tmp/hvb_comp.dat";
   // }

    FILE* output_file = fopen(argv[1],"r");
    


    if ( output_file == NULL){
        printf("Error file");
        exit(1);
    }
    return 0;
}
