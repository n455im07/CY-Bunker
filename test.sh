#!/bin/bash

# Initialize duration
start_timer=$(date +%s)

file_csv=$1


cut -f2 -d ";" file_csv > tmp/test.dat






end_time=$(date +%s)
duration=$(($end_time - $start_timer)) #bc convert nano to seconds 


#print Treatment time
echo "Treatment time: $duration seconds"