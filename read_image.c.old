#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include "rdjpeg.h"

#define BINS 4
#define SEUIL 255/BINS


//fonction qui détermine dans quel BINS est la valeur
int categorise(int entree)
{
  printf("%d\n",entree);
  printf("%d\n",SEUIL);
 // int t = entree/SEUIL;
  return 0;//t;
}

int main(int argc, char *argv[])
{
  int i,j,n,nx,ny,nb;
  //histogramme
  double h[BINS][BINS][BINS];
  CIMAGE cim;
  /*------------------------------------------------*/
  /* lecture d'une image requête                    */
  /*------------------------------------------------*/
  read_cimage(argv[1],&cim);
  /*------------------------------------------------*/
  /* affichage des valeurs pour le premier bloc 8x8 */
  /* comme exemple de traitement                    */
  /*------------------------------------------------*/
  printf("Largeur de l'image : %d\n",cim.nx);
  printf("Heuteur de l'image : %d\n",cim.ny);

  printf("Plan rouge du premier bloc 8x8 :\n");
  for (j = 0; j < 8; j++) {       /* ligne par ligne */
    printf("  ");
    for (i = 0; i < 8; i++) {   /* pixel par pixel */
      printf("%4d",cim.r[i][j]);
    }
    printf("\n");
  }
  printf("Plan vert du premier bloc 8x8 :\n");
  for (j = 0; j < 8; j++) {       /* ligne par ligne */
    printf("  ");
    for (i = 0; i < 8; i++) {   /* pixel par pixel */
      printf("%4d",cim.g[i][j]);
    }
    printf("\n");
  }
  printf("Plan bleu du premier bloc 8x8 :\n");
  for (j = 0; j < 8; j++) {       /* ligne par ligne */
    printf("  ");
    for (i = 0; i < 8; i++) {   /* pixel par pixel */
      printf("%4d",cim.b[i][j]);
    }
    printf("\n");
  }
  /*------------------------------------------------*/

  for ( j = 0; j < 8; j++){
    printf(" ");
    for (i = 0; i < 8; i++){
      int cat_r = categorise(cim.r[i][j]);
      int cat_g = categorise(cim.g[i][j]);
      int cat_b = categorise(cim.b[i][j]);
      printf("%d %d %d\n",cat_r,cat_g,cat_b);
    }
  }


  exit(0);
}
