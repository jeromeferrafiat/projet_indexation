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
    else{
      palier++;
    }
  }

  return palier;
}

char *remove_ext (char* mystr, char dot, char sep) {
    char *retstr, *lastdot, *lastsep;

    if (mystr == NULL)
        return NULL;
    if ((retstr = malloc (strlen (mystr) + 1)) == NULL)
        return NULL;

    strcpy (retstr, mystr);
    lastdot = strrchr (retstr, dot);
    lastsep = (sep == 0) ? NULL : strrchr (retstr, sep);

    if (lastdot != NULL) {
        if (lastsep != NULL) {
            if (lastsep < lastdot) {
              *lastdot = '\0';
            }
        } else {
          *lastdot = '\0';
        }
    }
    return retstr;
}

int main(int argc, char *argv[]){
  int n,nx,ny,nb;
  CIMAGE cim;

  //function to remove extension
  //char* res = remove_ext(argv[1], '.', '/');

  if(argc<2) {
    printf("Not enough argument\n");
    exit(-1);
  }

  char name[80];
  strcpy(name, "out/");
  strcat(name, argv[2]);
  strcat(name, "_out");

  FILE *f = fopen(name, "a");
  if (f == NULL){
    printf("Error opening file!\n");
    exit(1);
  }

  /*------------------------------------------------*/
  /* initialisation du tableau hist                 */
  /*------------------------------------------------*/
  double hist[BINS][BINS][BINS];
  for(int i = 0; i<BINS; i++){
    for(int j = 0; j<BINS; j++){
      for(int k = 0; k<BINS; k++){
        hist[i][j][k] = 0;
      }
    }
  }

  /*------------------------------------------------*/
  /* lecture d'une image requête                    */
  /*------------------------------------------------*/
  read_cimage(argv[1],&cim);

  /*------------------------------------------------*/
  /* calcul des histogrammes                        */
  /*------------------------------------------------*/
  for(int j = 0; j<cim.ny; j++){
    for(int i = 0; i<cim.nx; i++){
      (hist[check(cim.r[i][j])][check(cim.g[i][j])][check(cim.b[i][j])])++;
    }
  }

  /*------------------------------------------------*/
  /* tranformation en proportion                    */
  /*------------------------------------------------*/
  for(int k = 0; k<BINS; k++){
    for(int j = 0; j<BINS; j++){
      for(int i = 0; i<BINS; i++){
        hist[i][j][k] = hist[i][j][k] / (cim.ny*cim.nx);
        //printf("%4lf ", hist[i][j][k]);
      }
      //printf("\n");
    }
    //printf("\n");
  }

  /*------------------------------------------------*/
  /* sauvegarde sous le format libsvm               */
  /*------------------------------------------------*/
  fprintf(f,"0 ");
  for(int i = 0; i<BINS; i++){
    for(int j = 0; j<BINS; j++){
      for(int k = 0; k<BINS; k++){
        fprintf(f,"%d : %4f ",i*16+j*4+(k+1), hist[i][j][k]);
      }
    }
  }
  fprintf(f,"\n");

  fclose(f);
  free_cimage(argv[1],&cim);
  exit(0);
}
