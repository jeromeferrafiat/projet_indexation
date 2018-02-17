#!/bin/sh

for f in /u/m/mulhemp/sift/train/*.sift
do
  echo "Traitrement de $f"
  sed -n '4,$p' $f | tr -d ";" | sed 's/<CIRCLE [1-9].*> //' > ./trav.sift
  R --slave --no-save --no-restore --no-environ --args centers256.txt 256 ./trav.sift ./res.sift < 1nn.R
  mv ./res.sift sift/train/1nn/`basename $f`
done

\rm -f ./trav.sift ./res.sift

