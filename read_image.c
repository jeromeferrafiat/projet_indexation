#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "rdjpeg.h"

#define BINS 4

int check(float value){
  float seuil = 255 / BINS;
  float palier = 0;
  int done = 0;

  while(done != 1){
    if(value <= seuil*(palier+1)) {
      done = 1;
    }
    elsec{
      palier++;
    }
  }

  return palier;
}

int main(int argc, char *argv[])
{
  int i,j,n,nx,ny,nb;
  CIMAGE cim;

  double hist[BINS][BINS][BINS];
  for(i = 0; i<BINS; i++){
    for(j = 0; j<BINS; j++){
      for(int k = 0; k<BINS; k++){
        hist[i][j][k] = 0;
      }
    }
  }
  /*------------------------------------------------*/
  /* lecture d'une image requ�te                    */
  /*------------------------------------------------*/
  read_cimage(argv[1],&cim);
  /*------------------------------------------------*/
  /* affichage des valeurs pour le premier bloc 8x8 */
  /* comme exemple de traitement                    */
  /*------------------------------------------------*/

  for(j = 0; j<cim.ny; j++){
    for(i = 0; i<cim.nx; i++){
      (hist[check(cim.r[i][j])][check(cim.g[i][j])][check(cim.b[i][j])])++;
    }
  }

  for(int k = 0; k<BINS; k++){
    for(j = 0; j<BINS; j++){
      for(i = 0; i<BINS; i++){
        hist[i][j][k] = hist[i][j][k] / (cim.ny*cim.nx);
        printf("%4lf ", hist[i][j][k]);
      }
      printf("\n");
    }
    printf("\n");
  }

  

  exit(0);
}
