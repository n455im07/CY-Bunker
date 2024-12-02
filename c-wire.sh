#!/bin/bash

if [ $# -eq 0 ]; then
    echo "Usage: $0 chemin_du_fichier.csv"
    exit 1
fi


fichier_csv="$1"


if [ ! -f "$fichier_csv" ]; then
    echo "Erreur : Le fichier $fichier_csv n'existe pas."
    exit 1
fi


