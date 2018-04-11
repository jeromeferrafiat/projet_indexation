#!/bin/bash

make clean
make
rm -rf out
rm -rf images/train/out
rm -f images/train/*_out

mkdir images/train/out

liste_fichiers=`ls images/train/*.jpg`
echo "Converting images from train..."
for fichier in $liste_fichiers
do
    ./read_image $fichier images/train/out
done
echo "Done !"
rm -rf images/val/out
mkdir images/val/out

liste_fichiers=`ls images/val/*.jpg`
echo "Converting images from val..."
for fichier in $liste_fichiers
do
    ./read_image $fichier images/val/out
done
echo "Done !"
