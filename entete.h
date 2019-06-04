#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rand_a_b(int a, int b);
void pop_up(int** GRILLE);
int** init_grille();
void afficher_grille(int** GRILLE);
int deplacement_possible_gauche(int** GRILLE, int** TEST);
int deplacement_possible_droite(int** GRILLE, int** TEST);
int deplacement_possible_haut(int** GRILLE, int** TEST);
int deplacement_possible_bas(int** GRILLE, int** TEST);
void fusion (int** GRILLE,int i1, int j1, int i2, int j2);
void deplacement_case_bas(int** GRILLE, int i, int j, int** TEST);
void deplacement_case_haut(int** GRILLE, int i, int j, int** TEST);
void deplacement_case_gauche(int** GRILLE, int i, int j, int** TEST);
void deplacement_case_droite(int** GRILLE, int i, int j, int** TEST);
void deplacement_bas(int **GRILLE, int** TEST);
void deplacement_haut(int **GRILLE, int** TEST);
void deplacement_gauche(int **GRILLE, int** TEST);
void deplacement_droite(int **GRILLE, int** TEST);
int** cree_copie(int** GRILLE);
int matrices_egales(int**COPIE,int** GRILLE);
int etat_du_jeu(int** GRILLE, int** TEST);
void tour_de_jeu(int** GRILLE, int** TEST);
int** init_test();
void free_test(int** TEST);


int SCORE;
int meilleur_score;
