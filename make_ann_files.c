#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "rdjpeg.h"

char* replaceFirstChar(char* string, char* replacer){
  char* replacedString = malloc(sizeof(char) * (strlen(string)+strlen(replacer)-1));
  for(int i=0; i<strlen(replacer)-1; i++){
    replacedString[i] = replacer[i];
  }
  for(int i=strlen(replacer)-1; i<strlen(string); i++){
    replacedString[i] = string[i-(strlen(replacer)-2)];
  }
  return replacedString;
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

  if(argc<3) {
    printf("Not enough argument\n");
    exit(-1);
  }

  char nameColorSVM[80];
  strcpy(nameColorSVM, argv[1]);

  char nameAnn[80];
  //strcpy(nameAnn, "train/ann/");
  strcpy(nameAnn, argv[2]);

  char* color = remove_ext(argv[1], '.', '/');
  char* ann = remove_ext(argv[2], '.', '/');
  char* token = strtok(ann, "/");
  while(token != NULL){
    ann = token;
    token = strtok(NULL, "/");
  }
  char nameOutput[80];
  strcpy(nameOutput, "train/colorAnn/");
  strcat(nameOutput, color);
  strcat(nameOutput, "_");
  strcat(nameOutput, ann);
  strcat(nameOutput, ".svm");

  FILE *colorSVMFile = fopen(nameColorSVM, "r");
  FILE *annFile = fopen(nameAnn, "r");
  FILE *outputFile = fopen(nameOutput, "w+");
  if(colorSVMFile == NULL){
    printf("Error opening colors.svm file!\n");
    exit(1);
  }
  if(annFile == NULL){
    printf("Error opening ann file!\n");
    exit(1);
  }
  if(outputFile == NULL){
    printf("Error opening output file!\n");
    exit(1);
  }

  char colorLine[1024];
  char annLine[128];
  
  while (fgets(colorLine, sizeof(colorLine), colorSVMFile)) {
    printf("%s", colorLine);
    fgets(annLine, sizeof(annLine), annFile);
    char* token = strtok(annLine, " ");
    token = strtok(NULL, " ");
    char* outputLine = replaceFirstChar(colorLine, token);
    fprintf(outputFile, "%s\n", outputLine);
  }

  fclose(colorSVMFile);
  fclose(annFile);
  fclose(outputFile);
  exit(0);
}
