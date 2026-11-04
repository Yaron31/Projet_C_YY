#include <stdio.h>
#include <stdlib.h>
#include "jeu.h"

void creer_paquet(Carte paquet[])
{
    const char *couleurs[4] = {"Coeur", "Carreau", "Pique", "Trefle"};
    const char *rangs[13] = {"As", "2", "3", "4", "5", "6", "7",
                             "8", "9", "10", "Valet", "Dame", "Roi"};
    int valeurs[13] = {11, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10};
    int i = 0;
    int c;
    int r;

    for (c = 0; c < 4; c++)
    {
        for (r = 0; r < 13; r++)
        {
            paquet[i].valeur = valeurs[r];
            snprintf(paquet[i].nom, 20, "%s de %s", rangs[r], couleurs[c]);
            i++;
        }
    }
}

void melanger(Carte paquet[])
{
    int i;
    int j;
    Carte temp;

    for (i = 51; i > 0; i--)
    {
        j = rand() % (i + 1);
        temp = paquet[i];
        paquet[i] = paquet[j];
        paquet[j] = temp;
    }
}

Carte piocher(Carte paquet[], int *position)
{
    Carte carte;

    carte = paquet[*position];
    *position = *position + 1;

    return carte;
}

void tour_joueur(Joueur *j, Carte paquet[], int *position)
{
    Carte carte;
    char choix = 'o';
    int valeur_as;
    int nb_cartes = 0;

    j->score = 0;

    while (choix == 'o' && j->score < 21)
    {
        carte = piocher(paquet, position);
        nb_cartes = nb_cartes + 1;
        printf("Tu as pioche : %s\n", carte.nom);

        if (carte.valeur == 11)
        {
            printf("C'est un As ! Tu le comptes 1 ou 11 ? ");
            scanf("%d", &valeur_as);
            if (valeur_as == 1)
            {
                carte.valeur = 1;
            }
        }

        j->score = j->score + carte.valeur;
        printf("Ton score : %d\n", j->score);

        if (j->score < 21 && nb_cartes >= 2)
        {
            printf("Tu veux piocher une autre carte ? (o/n) ");
            scanf(" %c", &choix);
        }
    }

    if (j->score > 21)
    {
        printf("Tu depasses 21, tu as perdu !\n");
    }
}

void tour_croupier(Joueur *croupier, Carte cachee, Carte paquet[], int *position)
{
    Carte carte;

    printf("Le croupier retourne sa carte cachee : %s\n", cachee.nom);
    printf("Score du croupier : %d\n", croupier->score);

    while (croupier->score < 17)
    {
        carte = piocher(paquet, position);
        printf("Le croupier pioche : %s\n", carte.nom);

        if (carte.valeur == 11 && croupier->score + 11 > 21)
        {
            carte.valeur = 1;
        }

        croupier->score = croupier->score + carte.valeur;
        printf("Score du croupier : %d\n", croupier->score);
    }
}

void afficher_resultat(const Joueur *j, const Joueur *croupier)
{
    printf("\n--- Resultat ---\n");
    printf("%s : %d\n", j->nom, j->score);
    printf("%s : %d\n", croupier->nom, croupier->score);

    if (j->score > 21)
    {
        printf("Tu as depasse 21, le croupier gagne !\n");
    }
    else if (croupier->score > 21)
    {
        printf("Le croupier depasse 21, tu gagnes !\n");
    }
    else if (j->score > croupier->score)
    {
        printf("Tu gagnes !\n");
    }
    else if (j->score < croupier->score)
    {
        printf("Le croupier gagne !\n");
    }
    else
    {
        printf("Tu gagnes !\n");
    }
}

Carte distribuer_croupier(Joueur *croupier, Carte paquet[], int *position)
{
    Carte visible;
    Carte cachee;

    visible = piocher(paquet, position);
    cachee = piocher(paquet, position);

    printf("Carte du croupier : %s\n", visible.nom);

    croupier->score = visible.valeur;

    if (cachee.valeur == 11 && croupier->score + 11 > 21)
    {
        cachee.valeur = 1;
    }
    croupier->score = croupier->score + cachee.valeur;

    return cachee;
}