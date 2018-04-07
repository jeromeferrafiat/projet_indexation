#!/bin/bash

rm -f out/colors.svm
rm -f colors.svm

liste_fichiers=`ls out/*.jpg_out`
for fichier in $liste_fichiers
do
    cat $fichier >> colors.svm
done
