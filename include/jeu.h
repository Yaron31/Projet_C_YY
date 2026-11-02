#indef JEU_H
#define JEU_H

#include "joueur.h"

typedef struct {
    int valeur;
    char nom[20]
} Carte;

void jeu_creer_paquet(Carte paquet[]);
void jeu_melanger(Carte paquet[]);
Carte jeu_piocher(Carte paquet[], int *position);
void jeu_tour_joueur(Joueur *j, Carte paquet[], int *position);
void jeu_tour_croupier(Joueur *croupier, Carte paquet[], int *position);
void jeu_afficher_resultat(const Joueur *j, const Joueur *croupier);

#endif