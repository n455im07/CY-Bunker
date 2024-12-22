#include <stdio.h>
#include <string.h> 
#include <stdlib.h>

#include "include/avl.h"

//---- Treat the CSV file and insert the data in the AVL tree
AVL* treatment(AVL* pavl, char* stationType){ 
    FILE* file = fopen("tmp/temp.csv","r+"); // Open the file
    char chaine[50]=""; // Initialize the string

    if (file != NULL){ 
        while (fgets(chaine, sizeof(chaine), file) != NULL){ // Read the file line by line
            //---- Get the data from the CSV file to insert in the AVL tree
            int id = 0;
            long long capacity = 0;
            long long load = 0;
            //---- Split the string to get the data we need separated by ";"
            char* token;
            token = strtok(chaine, ";");
            int column = 0; 
            while (token != NULL){ // While we didn't reach the end of the string
                column++;
                if (strcmp(stationType, "hvb") == 0 && column == 2){
                    id = atoi(token); // Convert the string to an integer
                }
                if (strcmp(stationType, "hva") == 0 && column == 3){
                    id = atoi(token); // Convert the string to an integer
                }
                if (strcmp(stationType, "lv") == 0 && column == 4){
                    id = atoi(token); // Convert the string to an integer
                }
                else if (column == 7){
                    capacity = atoll(token); // Convert the string to a long long
                }else if (column == 8){
                    load = atoll(token); // Convert the string to a long long
                }
                token = strtok(NULL, ";"); // Get the next data
            }
            //---- Insert the data in the AVL tree
            int h = 0; // Initialize balance variable
            pavl = insertAVL(pavl, id, &h, capacity, load); // Insert each data in the AVL tree
        }
        fclose(file); // Close the file
    }else{
        printf("Error opening file\n");
    }
    return pavl;
}