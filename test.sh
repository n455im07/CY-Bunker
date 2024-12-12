#!/bin/bash

# Initialize duration
start_timer=$(date +%s)

input_csv="CSV.dat"
output_csv="tmp/test.dat"



# HVB COMP 
tail -n +2 $input_csv | awk -F ";" '$2 != "-" && $3 == "-" {print $0}' "$input_csv" > "$output_csv"

# HVA COMP
tail -n +2 $input_csv | awk -F ";" '$3 != "-" && $4 == "-" {print $0}' "$input_csv" > "$output_csv"

# LV COMP
tail -n +2 $input_csv | awk -F ";" '$4 != "-" && $6 == "-" {print $0}' "$input_csv" > "$output_csv"

# LV INDIV
tail -n +2 $input_csv | awk -F ";" '$4 != "-" && $5 == "-" {print $0}' "$input_csv" > "$output_csv"

# LV ALL
tail -n +2 $input_csv | awk -F ";" '$4 != "-" {print $0}' "$input_csv" > "$output_csv"


end_time=$(date +%s)
duration=$(($end_time - $start_timer)) #bc convert nano to seconds 


#print Treatment time
echo "Treatment time: $duration seconds"