# Projet_C_YY

Jeu de blackjack dans le terminal, réalisé en binôme dans le cadre de
la classe préparatoire aux fondamentaux du numérique.

## Auteurs

- Yannick Hu
- Yaron Marciano

## Règles du jeu

- Le but est de s'approcher de 21 sans le dépasser.
- Les cartes de 2 à 10 valent leur chiffre, les figures valent 10.
- Quand le joueur pioche un As, il choisit de le compter 1 ou 11.
- Le joueur et le croupier reçoivent 2 cartes au départ. Une seule
  carte du croupier est visible, l'autre est retournée à la fin.
- Le joueur pioche tant qu'il le souhaite (ou jusqu'à dépasser 21).
- Celui qui est le plus proche de 21 gagne. Qui dépasse 21 perd.
- Si le joueur et le croupier termine à 21, le joueur gagne.

## Compilation et lancement

Il faut avoir `gcc` installé. Depuis la racine du projet :

gcc -Wall -Wextra -Iinclude src/main.c src/jeu.c src/joueur.c -o blackjack

## Structure du projet

include/
joueur.h struct Joueur (nom, score)
jeu.h struct Carte (valeur, nom) et fonctions du jeu
src/
joueur.c fonctions du joueur
jeu.c paquet, tours de jeu, résultat
main.c lance la partie

## Les fonctions principales

- `creer_paquet` : remplit le paquet de 52 cartes.
- `melanger` : mélange le paquet.
- `piocher` : prend la prochaine carte du paquet.
- `distribuer_croupier` : donne 2 cartes au croupier, une visible.
- `tour_joueur` : le tour du joueur.
- `tour_croupier` : le tour du croupier.
- `afficher_resultat` : affiche le gagnant.

## Gestion de la mémoire

Le paquet de cartes est réservé avec `malloc` dans `main.c`, puis
libéré avec `free` à la fin de la partie.
