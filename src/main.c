#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "jeu.h"
#include "joueur.h"

int main(void)
{
    Carte *paquet;
    Carte cachee;
    int position = 0;
    Joueur joueur;
    Joueur croupier;
    char nom[20];

    srand(time(NULL));

    paquet = malloc(52 * sizeof(Carte));
    if (paquet == NULL)
    {
        printf("Erreur : pas assez de memoire\n");
        return 1;
    }

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
    else
    {
        printf("La carte cachee du croupier etait : %s\n", cachee.nom);
    }

    afficher_resultat(&joueur, &croupier);

    free(paquet);

    return 0;
}