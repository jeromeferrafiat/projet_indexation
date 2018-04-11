#!/bin/bash

rm -rf train/colorAnn/

mkdir train/colorAnn/

liste_fichiers=`ls train/ann/*.ann`
for fichier in $liste_fichiers
do
    echo $fichier
    ./make_ann_files train/colors.svm "$fichier"
done
