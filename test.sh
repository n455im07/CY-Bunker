#!/bin/bash

# Initialize duration
start_timer=$(date +%s)

input_csv="CSV.dat"
output_csv="tmp/test.dat"


#Enlever ligne 1



# HVB COMP
# awk -F ";" '$2 != "-" && $3 == "-" {print $0}' "$input_csv" > "$output_csv"

# HVA COMP
# awk -F ";" '$3 != "-" && $4 == "-" {print $0}' "$input_csv" > "$output_csv"

# LV COMP
# awk -F ";" '$4 != "-" && $6 == "-" {print $0}' "$input_csv" > "$output_csv"

# LV INDIV
# awk -F ";" '$4 != "-" && $5 == "-" {print $0}' "$input_csv" > "$output_csv"

# LV ALL
# awk -F ";" '$4 != "-" {print $0}' "$input_csv" > "$output_csv"


end_time=$(date +%s)
duration=$(($end_time - $start_timer)) #bc convert nano to seconds 


#print Treatment time
echo "Treatment time: $duration seconds"