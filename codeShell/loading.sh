#!/bin/bash
printf '\033[1;32;32m'
speed=0.1

# Définir un fichier audio par défaut à jouer
audio_file="codeShell/Stuka Dive Sound.mp3"  # Remplacez par le chemin vers votre fichier audio

# Vérifier si le fichier audio existe et est lisible
if [ ! -f "$audio_file" ]; then
    echo "Erreur : Le fichier audio par défaut n'existe pas ou n'est pas lisible."
    exit 1
else
    echo "Le fichier audio trouvé : $audio_file"
fi

# Lire l'audio en arrière-plan
mpv --no-video --loop "$audio_file" &  # Utilisez --loop si vous souhaitez que l'audio se répète

# Récupérer le PID du processus audio pour pouvoir le tuer plus tard
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
# Après avoir terminé l'animation de chargement, vous pouvez tuer le processus audio
kill $audio_pid
printf '\033[0m'

