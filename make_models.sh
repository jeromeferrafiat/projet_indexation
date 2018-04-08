#!/bin/bash

rm -rf train/model
mkdir train/model

concepts=`cat concepts.txt`

for concept in $concepts
do
    echo $concept
    ../libsvm-3.22/svm-train -w+1 19 -g 1.0 -b 1 -h 0 train/colorAnn/colors_$concept.svm train/model/colors_$concept.model
done
