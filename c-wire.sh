#!/bin/bash

# Check if the number of arguments is correct
if  [ $# -eq 0 ]; then
    echo "Error : No argument provided."
    exit 1
fi

# Check if file_csv is a file and is readable
file_csv=$1
if [ ! -f $file_csv ]; then
    echo "Error : File not found."
    exit 1
fi
if [ ! -r $file_csv ]; then
    echo "Error : File unreadable."
    exit 1
fi

# Station type
station_type=$2
if [ "$station_type" != "hvb" ] && [ "$station_type" != "hva" ] && [ "$station_type" != "lv" ]; then
    echo "Error : Station type not valid."
    exit 1
fi

# Consumer type
consumer_type=$3
if [ "$consumer_type" != "comp" ] && [ "$consumer_type" != "indiv" ] && [ "$consumer_type" != "all" ]; then
    echo "Error : Consumer type not valid."
    exit 1
fi
if [ "$consumer_type" != "comp" ] && [ $station_type != "lv" ] ; then
    echo "Error : Forbidden option, only comp are linked to HV-B and HV-A stations."
    exit 1
fi

# Power plant id (optional)
power_plant_id=$4

# Help option (optional)
# ?bool ? (-h) ## DOIT S'AFFICHER SI Y'A UNE ERREUR QUELCONQUE