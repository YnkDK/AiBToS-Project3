#!/usr/bin/env bash

# Setup the binary for this project
mkdir -p tmp/
mkdir -p bin/
cd tmp/
cmake ..
make
mv bin/AiBToS_Project3 ../bin/
cd ..

i=1
while read hp; do
    printf "${i}: ${hp} "

    DIRECTIONS=$(./bin/AiBToS_Project3 ${hp})
    printf "${DIRECTIONS} "
    python2 hpscore.py ${hp} ${DIRECTIONS}
    i=$((i+1))
done < hp_strings.txt