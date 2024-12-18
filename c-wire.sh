#!/bin/bash
clear

bash codeShell/fakeloading.sh

##################################################################################################	
##### F O N C T I O N S ##########################################################################
##################################################################################################


	function slow_print(){
		printf '\033[1;32;32m'
		local phrase="$1"
		for ((i=0;i<${#phrase};i++)); do
			echo -n "${phrase:i:1}"
			sleep 0.015
		done
		echo
		printf '\033[0m'
	}


	function help_manual() {
		slow_print "User manual : " 
		slow_print "   #1 : CSV File"
		slow_print "   #2 : Station type ( hva, hvb, lv )" 
		slow_print "   #3 : Consumer type ( comp, indiv, all )   Note : hva and hvb only works with comp !"
		slow_print "   #4 : Power plant id > 0"
		slow_print "Option : -h : Display help manual"
		slow_print "   -h : Display help manual"
		sleep 1
	}
	
	
##################################################################################################	
##### O T H E R S ################################################################################
##################################################################################################




##################################################################################################	
##### V E R I F I C A T I O N ####################################################################
##################################################################################################


#----Help if -h option is used
	for arg in "$@";do
		if [ "$arg" == "-h" ];then
			help_manual
			sleep 1
			exit 1
		fi
	done

#----Check if the number of arguments is correct

	if  [ $# -eq 0 ]; then
	    slow_print "/!\ Error : No argument provided."
	    echo
	    help_manual
	    exit 1
	fi

#----Check if file_csv is a file and is readable

	file_csv=$1
	
	if [ ! -f $file_csv ]; then
	    slow_print "/!\ Error : File not found."
	    echo
	    help_manual
	    exit 1
	fi
	
	if [ ! -r $file_csv ]; then
	    slow_print "/!\ Error : File unreadable."
	    echo
	    help_manual
	    exit 1
	fi

#----Station type

	station_type=$2
	
	if [ "$station_type" != "hvb" ] && [ "$station_type" != "hva" ] && [ "$station_type" != "lv" ]; then
	    slow_print "/!\ Error : Station type not valid."
	    echo
	    help_manual
	    exit 1
	fi

#----Consumer type

	consumer_type=$3
	
	if [ "$consumer_type" != "comp" ] && [ "$consumer_type" != "indiv" ] && [ "$consumer_type" != "all" ]; then
	    slow_print "/!\ Error : Consumer type not valid."
	    echo
	    help_manual
	    exit 1
	fi
	
	if [ "$consumer_type" != "comp" ] && [ $station_type != "lv" ]; then
	    slow_print "/!\ Error : Forbidden option, only comp are linked to HV-B and HV-A stations."
	    echo
	    help_manual
	    exit 1
	fi

#----Power plant id (optional)

	power_plant_id=$4 
	if [ ! -z "$power_plant_id" ]; then
		if [ "$power_plant_id" -le 0 ] || [[ ! "$power_plant_id" =~ ^[0-9]+$ ]]; then
			slow_print "/!\ Error : Power plant id must be a positive number"
			echo
			help_manual
			exit 1
		fi
	fi

bash codeShell/loading.sh&
loading_pid=$!
#----Check if the executable exists

	if [ ! -x exe ]; then
	    slow_print "/!\ Error : Executable doesn't exist. Compiling..."
	    echo
	    make clean -C codeC
	    make -s -C codeC
	fi

#----Check if tmp directory exists

	if [ ! -d tmp ]; then
	    mkdir tmp
	else 
	    rm -rf tmp/*
	fi

#----Check if graphs directory exists

	if [ ! -d graphs ]; then
	    mkdir graphs
	fi

# IF ERROR TIME ELAPSED = 0s
# Initialize duration
start_timer=$(date +%s)

input_csv=$file_csv
output_csv="tmp/temp.csv"


# HVB COMP
 if [ "$station_type" == "hvb" ]; then
	tail -n +2 $input_csv | awk -F ";" '$2 != "-" && $3 == "-" {print $0}' > "$output_csv"
fi

# HVA COMP
if [ "$station_type" == "hva" ]; then
	tail -n +2 $input_csv | awk -F ";" '$3 != "-" && $4 == "-" {print $0}' > "$output_csv"
fi

# LV COMP
if [ "$station_type" == "lv" ]; then
	if [ "$consumer_type" == "comp" ]; then
	tail -n +2 $input_csv | awk -F ";" '$4 != "-" && $6 == "-" {print $0}' > "$output_csv"
	fi
	# LV INDIV
	if [ "$consumer_type" == "indiv" ]; then
	tail -n +2 $input_csv | awk -F ";" '$4 != "-" && $5 == "-" {print $0}' > "$output_csv"
	fi
	# LV ALL
	if [ "$consumer_type" == "all" ]; then
	tail -n +2 $input_csv | awk -F ";" '$4 != "-" {print $0}' > "$output_csv"
	fi
fi

if [ ! -z "$power_plant_id" ]; then
    awk -F ";" -v id="$power_plant_id" '$1 == id {print $0}' "$output_csv" > "${output_csv}.tmp" # -v = variable
    mv "${output_csv}.tmp" "$output_csv"
else
	power_plant_id=0
fi

output_file_name=""
if [ $power_plant_id -eq 0 ];then
	output_file_name="tmp/${station_type}_${consumer_type}.csv"
else
	output_file_name="tmp/${station_type}_${consumer_type}_${power_plant_id}.csv"
fi

touch "$output_file_name"

if [ $station_type == "lv" ] && [ $consumer_type == "all" ]; then
	touch "tmp/lv_allminmax.csv"
fi


# C PROGRAMM

chmod 777 tmp

make -s -C codeC 

./exe $station_type $consumer_type $power_plant_id $output_file_name 
kill $loading_pid
clear
sleep 0.1




# Sort for LV ALL MIN MAX


end_time=$(date +%s)
duration=$(($end_time - $start_timer)) #bc convert nano to seconds 

# Remove .o files in codeC/

find codeC -type f -name "*.o" -exec rm -f {} \;

#print Treatment time

slow_print "Treatment Time: $duration seconds"
notify-send "Treatment finished!" "File $output_file_name generated sucessfully."
slow_print "Treatment finished! File $output_file_name generated sucessfully."
if [ $station_type == "lv" ] && [ $consumer_type == "all" ]; then
	notify-send "Treatment finished!" "File tmp/lv_allminmax.csv generated sucessfully"
        slow_print "Treatment finished! File tmp/lv_allminmax.csv generated sucessfully."
fi


