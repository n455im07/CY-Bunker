#!/bin/bash

# Check if the number of arguments is correct
if  [ $# -eq 0 ]; then
    echo "Error : No argument provided."
    exit 1
fi

file_csv=$1

# Check if file_csv is a file
if [ ! -f $file_csv ]; then
    echo "Error : File not found."
    exit 1
fi

# Station type

# Consumer type

# Power plant id

# Help option