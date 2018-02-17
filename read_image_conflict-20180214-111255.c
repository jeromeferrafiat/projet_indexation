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
/*  do{
    if(value <= seuil*(palier+1))
      done = 1;
    else
      palier++;
  }while(done != 1);
  */

  while(done != 1){
    if(value <= seuil*(palier+1))
    {
      done = 1;
    }
    else
    {
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
        //printf("%lf\n", hist[i][j][k]);
      }
    }
  }
  /*------------------------------------------------*/
  /* lecture d'une image requête                    */
  /*------------------------------------------------*/
  read_cimage(argv[1],&cim);
  /*------------------------------------------------*/
  /* affichage des valeurs pour le premier bloc 8x8 */
  /* comme exemple de traitement                    */
  /*------------------------------------------------*/
  
  // printf("Largeur de l'image : %d\n",cim.nx);
  // printf("Heuteur de l'image : %d\n",cim.ny);
  // printf("Plan rouge du premier bloc 8x8 :\n");
  // for (j = 0; j < 8; j++) {       /* ligne par ligne */
  //   printf("  ");
  //   for (i = 0; i < 8; i++) {   /* pixel par pixel */
  //     printf("%4d",cim.r[i][j]);

  //   }
  //   printf("\n");
  // }
  // printf("Plan vert du premier bloc 8x8 :\n");
  // for (j = 0; j < 8; j++) {       /* ligne par ligne */
  //   printf("  ");
  //   for (i = 0; i < 8; i++) {   /* pixel par pixel */
  //     printf("%4d",cim.g[i][j]);
  //   }
  //   printf("\n");
  // }
  // printf("Plan bleu du premier bloc 8x8 :\n");
  // for (j = 0; j < 8; j++) {       /* ligne par ligne */
  //   printf("  ");
  //   for (i = 0; i < 8; i++) {   /* pixel par pixel */
  //     printf("%4d",cim.b[i][j]);
  //   }
  //   printf("\n");
  // }
  /*------------------------------------------------*/

  for(j = 0; j<cim.ny; j++){
    for(i = 0; i<cim.nx; i++){
      //printf("rouge : %d\n",check(cim.r[i][j]) );
      //printf("vert : %d\n",check(cim.g[i][j]) );
      //printf("bleu :%d\n\n",check(cim.b[i][j]) );
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