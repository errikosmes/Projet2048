#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <gtk/gtk.h>
#include <gdk/gdkkeysyms.h>


int rand_a_b(int a, int b);
void pop_up(int** GRILLE);
int** init_grille();
void affichage_grille(int** GRILLE);
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
void on_btn_hello_clicked();
void on_window_main_destroy();

GtkWidget *g_lbl_hello;
GtkWidget *g_lbl_count;
GtkWidget *g_lbl_grid_0_0;
GtkWidget *g_lbl_grid_0_1;
GtkWidget *g_lbl_grid_0_2;
GtkWidget *g_lbl_grid_0_3;
GtkWidget *g_lbl_grid_1_0;
GtkWidget *g_lbl_grid_1_1;
GtkWidget *g_lbl_grid_1_2;
GtkWidget *g_lbl_grid_1_3;
GtkWidget *g_lbl_grid_2_0;
GtkWidget *g_lbl_grid_2_1;
GtkWidget *g_lbl_grid_2_2;
GtkWidget *g_lbl_grid_2_3;
GtkWidget *g_lbl_grid_3_0;
GtkWidget *g_lbl_grid_3_1;
GtkWidget *g_lbl_grid_3_2;
GtkWidget *g_lbl_grid_3_3;


int SCORE;
int meilleur_score;
int **GRILLE;
