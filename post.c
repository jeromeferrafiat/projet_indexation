/*-------------------------*/
/* Fichier : post4.c       */
/* Auteur : Georges Qu�not */
/*-------------------------*/

#include <stdio.h>
#include <stdlib.h>

#include "cgiu.h"

#define  DEBUG 1

main(int argc, char *argv[])
{
    int x,m;
    char *qs,*nom,*info;
    entry *entries;

    /* r�cup�ration de la cha�ne de param�tres */
    qs = get_query_string(argc,argv);

    /* r�cup�ration des couples (nom,valeur) */
    entries = get_entries(qs,&m);

    /* �mission de l'ent�te */
    print_html_head("R&eacute;sultat");

    /* affichage �ventuel des informations de debug */
    if (DEBUG) print_debug_query(entries,m,qs,argc,argv);

    /* r�cup�ration des param�tres */
    nom  = getparam(entries,m,"NOM");
    info = getparam(entries,m,"INFO");

    /* affichage des param�tres */
    printf("<H1>Param&egrave;tres re&ccedil;u(s) en entr&eacute;e</H1>\n");
    printf("<ul>\n");
    if (nom != NULL) {
        printf("<li> Nom de la personne recherch�e : <code>%s</code>\n",nom);
    }
    if (info != NULL) {
        printf("<li> Information recherch�e : <code>%s</code>\n",info);
    }
    printf("</ul>\n");

    /* �mission de la fin de corps et de document */
    print_html_tail();
}
