#include <stdio.h>
#include <string.h>
#include "joueur.h"

void joueur_init(Joueur *j, const char *nom)
{
    strncpy(j->nom, nom, 19);
    j->nom[19] = '\0';
    j->score = 0;
}

void joueur_afficher(const Joueur *j)
{
    printf("%s : %d\n", j->nom, j->score);
}