#!/bin/bash

rm -f out/colors.svm
rm -f colors.svm
rm -f train/colors.svm
rm -f val/colors.svm

liste_fichiers=`ls images/train/out/*_out`
for fichier in $liste_fichiers
do
    cat $fichier >> train/colors.svm
done

liste_fichiers=`ls images/val/out/*_out`
for fichier in $liste_fichiers
do
    cat $fichier >> val/colors.svm
done
