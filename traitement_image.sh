#!/bin/bash

make clean
make
rm -rf out

cp read_image images/train

cd images/train
mkdir out

liste_fichiers=`ls *.jpg`

for fichier in $liste_fichiers
do
    ./read_image $fichier out
done

rm read_image

mv out ../..