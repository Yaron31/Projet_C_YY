#indef JOUEUR_H
#define JOUEUR_H

typedef struct {
    char nom [20];
    int score;
} Joueur;

void joueur_init(Joueur *j, const char *nom);
void joueur_afficher(const Joueur *j);

#endif