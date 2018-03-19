#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#include "rdjpeg.h"

int main(int argc, char *argv[])
{
  char buff[255];

  if(argc<2) {
    printf("Not enough argument\n");
    exit(-1);
  }

  FILE *fout = fopen("out.txt", "w");
  FILE *f = fopen(argv[1], "r");
  if (f == NULL || fout == NULL){
    printf("Error opening file!\n");
    exit(1);
  }

  /*------------------------------------------------*/
  /* récupère toutes les urls                       */
  /*------------------------------------------------*/
  while(fgets(buff, 255, (FILE*)f)!=NULL){
    strtok(buff,"\n");

    char url[255];
    strcpy(url, buff);

    //TODO change to dynamic out directory
    char img[] = "--output images/train/";
    strcat(img, &url[strlen(url)-15]);

    const char *my_arg[64] = {"curl", url, img, NULL };
    fprintf(fout,"%s %s %s\n", my_arg[0], my_arg[1], my_arg[2]);
  }

  fclose(f);
  fclose(fout);

  exit(0);
}
