#ifndef JEU_H
#define JEU_H

#include "joueur.h"

typedef struct {
    int valeur;
    char nom[20];
} Carte;

void creer_paquet(Carte paquet[]);
void melanger(Carte paquet[]);
Carte piocher(Carte paquet[], int *position);
void tour_joueur(Joueur *j, Carte paquet[], int *position);
void tour_croupier(Joueur *croupier, Carte cachee, Carte paquet[], int *position);
void afficher_resultat(const Joueur *j, const Joueur *croupier);
Carte distribuer_croupier(Joueur *croupier, Carte paquet[], int *position);

#endif