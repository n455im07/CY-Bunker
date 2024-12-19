#!/bin/bash
printf '\033[1;32;32m'
speed=0.1

# Défine the audio file 
audio_file="/mnt/data/CY-Bunker-master/CY-Bunker-master/codeShell/Stuka Dive Sound.mp3"  

# Vérifying if the audio file existe and if its not lisible
if [ ! -f "$audio_file" ]; then
    echo "Error : the audio file is not existing or not lisible"
    exit 1
else
    echo "audio file found: $audio_file"
fi

# begin the audio
mpv --no-video --loop "$audio_file" &  

# recover the PID to kill the sound after
audio_pid=$!

p="    ╔════════════════════════════════════════════════════════════════╗
    ║                                                                ║
    ║                       ⛤          ⛤                             ║
    ║                                               ⛤                ║
    ║             ⛤                                                  ║
    ║                                                                ║
    ║                                                                ║
    ║       ⛤                                                        ║
    ║                                                        ⛤       ║
                                                                      
  ██████╗██╗   ██╗     ██████╗ ██╗   ██╗███╗   ██╗██╗  ██╗███████╗██████╗ 
 ██╔════╝╚██╗ ██╔╝     ██╔══██╗██║   ██║████╗  ██║██║ ██╔╝██╔════╝██╔══██╗
 ██║      ╚████╔╝█████╗██████╔╝██║   ██║██╔██╗ ██║█████╔╝ █████╗  ██████╔╝
 ██║       ╚██╔╝ ╚════╝██╔══██╗██║   ██║██║╚██╗██║██╔═██╗ ██╔══╝  ██╔══██╗
 ╚██████╗   ██║        ██████╔╝╚██████╔╝██║ ╚████║██║  ██╗███████╗██║  ██║
  ╚═════╝   ╚═╝        ╚═════╝  ╚═════╝ ╚═╝  ╚═══╝╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝
    ║                                                                ║
    ║    ✘ Управление бункером®                                      ║
    ║                                                         ⛤      ║
    ║                    ╦   ╔═╗ ╔═╗ ╔╦╗ ╦ ╔╗╔ ╔═╗                   ║
    ║                    ║   ║ ║ ╠═╣  ║║ ║ ║║║ ║ ╦                   ║
    ║                    ╩═╝ ╚═╝ ╩ ╩ ═╩╝ ╩ ╝╚╝ ╚═╝         ⛤         ║
  "


p1=$p"  ║       ⛤       ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓               ║\n"
p2="    ║               ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛               ║
    ║                                                                ║
    ║             ⛤                                ⛤                 ║
    ║                      ⛤             ⛤                           ║
    ║                                                                ║
    ║                                                                ║
    ║              --- -.   -- . .-. .. - .   ..--- -----            ║
    ╚════════════════════════════════════════════════════════════════╝"

while true; do

	printf "$p1" 
	printf "    ║               ┃░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░┃               ║\n"
	printf "$p2" 
	sleep $speed
	clear
	##
	printf "$p1" 
	printf  "    ║               ┃████░░░░░░░░░░░░░░░░░░░░░░░░░░░░┃               ║\n"
	printf "$p2" 
	sleep $speed
	clear
	##
	printf "$p1" 
	printf  "    ║               ┃████████░░░░░░░░░░░░░░░░░░░░░░░░┃               ║\n"
	printf "$p2" 
	sleep $speed
	clear
	##
	printf "$p1" 
	printf  "    ║               ┃░░░░████████░░░░░░░░░░░░░░░░░░░░┃               ║\n"

	printf "$p2" 
	sleep $speed
	clear
	##
	printf "$p1" 
	printf  "    ║               ┃░░░░░░░░████████░░░░░░░░░░░░░░░░┃               ║\n"

	printf "$p2" 
	sleep $speed
	clear
	##
	printf "$p1" 
	printf  "    ║               ┃░░░░░░░░░░░░████████░░░░░░░░░░░░┃               ║\n"
	printf "$p2" 
	sleep $speed
	clear
	##
	printf "$p1" 
	printf  "    ║               ┃░░░░░░░░░░░░░░░░████████░░░░░░░░┃               ║\n"
	printf "$p2" 
	sleep $speed
	clear
	##
	printf "$p1" 
	printf  "    ║               ┃░░░░░░░░░░░░░░░░░░░░████████░░░░┃               ║\n" 
	printf "$p2" 
	sleep $speed
	clear
	##
	printf "$p1" 
	printf  "    ║               ┃░░░░░░░░░░░░░░░░░░░░░░░░████████┃               ║\n" 
	printf "$p2" 
	sleep $speed
	clear
	##
	printf "$p1" 
	printf  "    ║               ┃░░░░░░░░░░░░░░░░░░░░░░░░░░░░████┃               ║\n" 
	printf "$p2" 
	sleep $speed
	clear
	##
done

##
# Kill the audio when the loading is done
kill $audio_pid
printf '\033[0m'

