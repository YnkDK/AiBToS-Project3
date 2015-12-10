#!/usr/bin/env bash
i=1
while read hp; do
    printf "${i}: ${hp} "

    DIRECTIONS=$(python hilbert.py ${hp})
    printf "${DIRECTIONS} "
    printf "\n"
    i=$((i+1))
done < hp_strings.txt