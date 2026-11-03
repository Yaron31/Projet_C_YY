#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "jeu.h"
#include "joueur.h"

int main(void)
{
    Carte paquet[52];
    Carte cachee;
    int position = 0;
    Joueur joueur;
    Joueur croupier;
    char nom[20];

    srand(time(NULL));

    printf("=== BLACKJACK ===\n");
    printf("Ton nom : ");
    scanf("%19s", nom);

    joueur_init(&joueur, nom);
    joueur_init(&croupier, "Croupier");

    creer_paquet(paquet);
    melanger(paquet);

    cachee = distribuer_croupier(&croupier, paquet, &position);

    tour_joueur(&joueur, paquet, &position);

    if (joueur.score <= 21)
    {
        tour_croupier(&croupier, cachee, paquet, &position);
    }

    afficher_resultat(&joueur, &croupier);

    return 0;
}