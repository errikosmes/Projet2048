#include <gtk/gtk.h>
#include <gdk/gdkkeysyms.h>
#include <string.h>

gboolean on_key_press (GtkWidget *widget, GdkEventKey *event, gpointer user_data);
void on_btn_hello_clicked();
void on_window_main_destroy();
int** init_grille();
void affichage_grille(int** GRILLE);

int rand_a_b(int a, int b);
void pop_up(int** GRILLE);
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

int **GRILLE;
int **TEST;
int SCORE;

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

int main(int argc, char *argv[]){
    GtkBuilder      *builder;
    GtkWidget       *window;

    gtk_init(&argc, &argv);

    builder = gtk_builder_new();
    gtk_builder_add_from_file (builder, "glade/window_main.glade", NULL);
    window = GTK_WIDGET(gtk_builder_get_object(builder, "window_main"));
    gtk_builder_connect_signals(builder, NULL);

    // get pointers to the labels
    g_lbl_hello = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_hello"));
    g_lbl_count = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_count"));
    g_lbl_grid_0_0 = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_grid_0_0"));
    g_lbl_grid_0_1 = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_grid_0_1"));
    g_lbl_grid_0_2 = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_grid_0_2"));
    g_lbl_grid_0_3 = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_grid_0_3"));
	g_lbl_grid_1_0 = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_grid_1_0"));
    g_lbl_grid_1_1 = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_grid_1_1"));
    g_lbl_grid_1_2 = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_grid_1_2"));
    g_lbl_grid_1_3 = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_grid_1_3"));
	g_lbl_grid_2_0 = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_grid_2_0"));
    g_lbl_grid_2_1 = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_grid_2_1"));
    g_lbl_grid_2_2 = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_grid_2_2"));
    g_lbl_grid_2_3 = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_grid_2_3"));
	g_lbl_grid_3_0 = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_grid_3_0"));
    g_lbl_grid_3_1 = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_grid_3_1"));
    g_lbl_grid_3_2 = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_grid_3_2"));
    g_lbl_grid_3_3 = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_grid_3_3"));

    GRILLE = init_grille();
    affichage_grille(GRILLE);
    SCORE = 0;
    
    g_object_unref(builder);

    g_signal_connect (G_OBJECT (window), "key_press_event", G_CALLBACK (on_key_press), NULL);

    gtk_widget_show(window);

    gtk_main();

    return 0;
}

gboolean on_key_press (GtkWidget *widget, GdkEventKey *event, gpointer user_data){
    char str_label[30] = {0};
    
    switch (event->keyval){
        case GDK_KEY_z:
            printf("key pressed: %s\n", "z");
            if (deplacement_possible_haut(GRILLE,TEST)){
					deplacement_haut(GRILLE, TEST);
                    pop_up(GRILLE);
			}
            affichage_grille(GRILLE);
            break;
        
        case GDK_KEY_q:
            printf("key pressed: %s\n", "q");
            if (deplacement_possible_gauche(GRILLE,TEST)){
					deplacement_gauche(GRILLE, TEST);
                    pop_up(GRILLE);
			}
            affichage_grille(GRILLE);

            break;
        
        case GDK_KEY_s:
            printf("key pressed: %s\n", "s");
            if (deplacement_possible_bas(GRILLE,TEST)){
					deplacement_bas(GRILLE, TEST);
                    pop_up(GRILLE);
			}
            affichage_grille(GRILLE);
            break;
        
        case GDK_KEY_d:
            printf("key pressed: %s\n", "d");
            if (deplacement_possible_droite(GRILLE,TEST)){
				deplacement_droite(GRILLE,TEST);
                pop_up(GRILLE);
			}
            affichage_grille(GRILLE);
            break;
        
        default:
            return FALSE; 
  	}
  	return FALSE;
}

// called when button is clicked
void on_btn_hello_clicked(){
    static unsigned int count = 0;
    char str_count[30] = {0};

    printf("Entered");

    gtk_label_set_text(GTK_LABEL(g_lbl_hello), "Hello, world!");
    count++;
    sprintf(str_count, "%d", count);
    gtk_label_set_text(GTK_LABEL(g_lbl_count), str_count);

    gtk_label_set_text(GTK_LABEL(g_lbl_grid_0_0), str_count);
}

// called when window is closed
void on_window_main_destroy(){
    gtk_main_quit();
}

int** init_grille(){
  /*Fonction initialisant la GRILLE avec deux nombres (2 ou 4) et des 0 ailleurs*/

  int** GRILLE=(int**)malloc((4)*sizeof(int*));
  int i,j;
	for(i=0;i<4;i++){
	GRILLE[i]=(int*)malloc((4)*sizeof(int));
	}
  for(i=0;i<4;i++){
	for(j=0;j<4;j++){
	    GRILLE[i][j]=0;
	}
  }

    pop_up(GRILLE);
    pop_up(GRILLE);

  return GRILLE;
}

void affichage_grille(int** GRILLE){
    char str_label[30] = {0};
    printf("affichage");

	sprintf(str_label, "%d", GRILLE[0][0]);
    if (strcmp(str_label,"0") == 0) strcpy(str_label, " ");
	gtk_label_set_text(GTK_LABEL(g_lbl_grid_0_0), str_label);
	sprintf(str_label, "%d", GRILLE[0][1]);
    if (strcmp(str_label,"0") == 0) strcpy(str_label, " ");
	gtk_label_set_text(GTK_LABEL(g_lbl_grid_0_1), str_label);
	sprintf(str_label, "%d", GRILLE[0][2]);
    if (strcmp(str_label,"0") == 0) strcpy(str_label, " ");
	gtk_label_set_text(GTK_LABEL(g_lbl_grid_0_2), str_label);
	sprintf(str_label, "%d", GRILLE[0][3]);
    if (strcmp(str_label,"0") == 0) strcpy(str_label, " ");
	gtk_label_set_text(GTK_LABEL(g_lbl_grid_0_3), str_label);

	sprintf(str_label, "%d", GRILLE[1][0]);
    if (strcmp(str_label,"0") == 0) strcpy(str_label, " ");
	gtk_label_set_text(GTK_LABEL(g_lbl_grid_1_0), str_label);
	sprintf(str_label, "%d", GRILLE[1][1]);
    if (strcmp(str_label,"0") == 0) strcpy(str_label, " ");
	gtk_label_set_text(GTK_LABEL(g_lbl_grid_1_1), str_label);
	sprintf(str_label, "%d", GRILLE[1][2]);
    if (strcmp(str_label,"0") == 0) strcpy(str_label, " ");
	gtk_label_set_text(GTK_LABEL(g_lbl_grid_1_2), str_label);
	sprintf(str_label, "%d", GRILLE[1][3]);
    if (strcmp(str_label,"0") == 0) strcpy(str_label, " ");
	gtk_label_set_text(GTK_LABEL(g_lbl_grid_1_3), str_label);

	sprintf(str_label, "%d", GRILLE[2][0]);
    if (strcmp(str_label,"0") == 0) strcpy(str_label, " ");
	gtk_label_set_text(GTK_LABEL(g_lbl_grid_2_0), str_label);
	sprintf(str_label, "%d", GRILLE[2][1]);
    if (strcmp(str_label,"0") == 0) strcpy(str_label, " ");
	gtk_label_set_text(GTK_LABEL(g_lbl_grid_2_1), str_label);
	sprintf(str_label, "%d", GRILLE[2][2]);
    if (strcmp(str_label,"0") == 0) strcpy(str_label, " ");
	gtk_label_set_text(GTK_LABEL(g_lbl_grid_2_2), str_label);
	sprintf(str_label, "%d", GRILLE[2][3]);
    if (strcmp(str_label,"0") == 0) strcpy(str_label, " ");
	gtk_label_set_text(GTK_LABEL(g_lbl_grid_2_3), str_label);

	sprintf(str_label, "%d", GRILLE[3][0]);
    if (strcmp(str_label,"0") == 0) strcpy(str_label, " ");
	gtk_label_set_text(GTK_LABEL(g_lbl_grid_3_0), str_label);
	sprintf(str_label, "%d", GRILLE[3][1]);
    if (strcmp(str_label,"0") == 0) strcpy(str_label, " ");
	gtk_label_set_text(GTK_LABEL(g_lbl_grid_3_1), str_label);
	sprintf(str_label, "%d", GRILLE[3][2]);
    if (strcmp(str_label,"0") == 0) strcpy(str_label, " ");
	gtk_label_set_text(GTK_LABEL(g_lbl_grid_3_2), str_label);
	sprintf(str_label, "%d", GRILLE[3][3]);
    if (strcmp(str_label,"0") == 0) strcpy(str_label, " ");
	gtk_label_set_text(GTK_LABEL(g_lbl_grid_3_3), str_label);
}

void fusion (int** GRILLE,int i1, int j1, int i2, int j2){
	/* cette fonction met la case deux dans la case 1. si dans la case 1 il y a une 0, on décale juste le nombre, sinon on le multiplie par deux*/

	/*si la fusion n'est pas possible*/
	if (GRILLE[i1][j1]!=0 && GRILLE[i1][j1]!=GRILLE[i2][j2]){
		return;
	}

	/*si on fait un dépalcement dans une case vide*/
	if (GRILLE[i1][j1]==0){
		GRILLE[i1][j1]=GRILLE[i2][j2];
		GRILLE[i2][j2]=0;
	}

	/* sinon fait une fusion avec une autre case et augmentation du score*/
	else {
		GRILLE[i1][j1]=GRILLE[i2][j2]+GRILLE[i1][j1];
		GRILLE[i2][j2]=0;
		SCORE +=  GRILLE[i1][j1];
	}
}



/*-------------------------------------------------------------------*/

void deplacement_case_bas(int** GRILLE, int i, int j, int** TEST){
	/* cette fonction effectue si nessesaire le déplacement ou la fusion de la case placé en parametre*/
	int i1=i+1;
	if (i1>3 || (GRILLE[i1][j]==0 && GRILLE[i][j]==0) || (GRILLE[i1][j]!=0 && GRILLE[i][j]!=GRILLE[i1][j]) || TEST[i1][j]==1){
		return;
	}else if ((GRILLE[i][j]==GRILLE[i1][j])){
		fusion(GRILLE,i1,j,i,j);
		TEST[i1][j]=1;
		return;
	}
	else {
		fusion(GRILLE,i1,j,i,j);
		deplacement_case_bas(GRILLE,i1,j, TEST);
	}
}


void deplacement_bas(int **GRILLE, int** TEST){
	/* cette fonction effectue le parcours d'une grille placé en parametre*/
	TEST=init_test();
	int i,j;
	for(j=0; j<4; j++){
		for(i=3; i>=0; i--){
			deplacement_case_bas(GRILLE, i, j, TEST);
		}
	}
	free_test(TEST);
}

/*-------------------------------------------------------------------*/

void deplacement_case_haut(int** GRILLE, int i, int j,int** TEST){
	/* cette fonction effectue si nessesaire le déplacement ou la fusion de la case placé en parametre*/
	int i1=i-1;
	if (i1<0 || (GRILLE[i1][j]==0 && GRILLE[i][j]==0) || (GRILLE[i1][j]!=0 && GRILLE[i][j]!=GRILLE[i1][j])  || TEST[i1][j]==1){
		return;
	}else if (GRILLE[i][j]==GRILLE[i1][j]){
		fusion(GRILLE,i1,j,i,j);
		TEST[i1][j]=1;
		return;
	}else {
		fusion(GRILLE,i1,j,i,j);
		deplacement_case_haut(GRILLE,i1,j,TEST);
 	}
}

void deplacement_haut(int **GRILLE,int** TEST){
	/* cette fonction effectue le parcours d'une grille placé en parametre*/
	TEST=init_test();
	int i,j;

	for(j=0; j<4; j++){
		for(i=0; i<4; i++){
			deplacement_case_haut(GRILLE, i, j,TEST);
		}
	}
	free_test(TEST);
}

/*-------------------------------------------------------------------*/

void deplacement_case_gauche(int** GRILLE, int i, int j,int** TEST){
	/* cette fonction effectue si nessesaire le déplacement ou la fusion de la case placé en parametre*/
	int j1=j-1;
	if (j1<0 || (GRILLE[i][j1]==0 && GRILLE[i][j]==0) ||(GRILLE[i][j1]!=0 && GRILLE[i][j]!=GRILLE[i][j1]) || TEST[i][j1]==1){
		return;
	}else if (GRILLE[i][j]==GRILLE[i][j1]){
		fusion(GRILLE,i,j1,i,j);
		TEST[i][j1]=1;
		return;
	}else {
		fusion(GRILLE,i,j1,i,j);
		deplacement_case_gauche(GRILLE,i,j1,TEST);
	}
}


void deplacement_gauche(int **GRILLE,int** TEST){
	/* cette fonction effectue le parcours d'une grille placé en parametre*/
	TEST=init_test();
	int i,j;

	for(i=0; i<4; i++){
		for(j=0; j<4; j++){
			deplacement_case_gauche(GRILLE, i, j,TEST);
		}
	}
	free_test(TEST);
}


/*-------------------------------------------------------------------*/

void deplacement_case_droite(int** GRILLE, int i, int j,int** TEST){
	/* cette fonction effectue si nessesaire le déplacement ou la fusion de la case placé en parametre*/
	int j1=j+1;
	if (j1>3 || (GRILLE[i][j1]==0 && GRILLE[i][j]==0) || (GRILLE[i][j1]!=0 && GRILLE[i][j]!=GRILLE[i][j1]) || TEST[i][j1]==1){
		return;
	}else if (GRILLE[i][j]==GRILLE[i][j1]){
		fusion(GRILLE,i,j1,i,j);
		TEST[i][j1]=1;
		return;
	}else {
		fusion(GRILLE,i,j1,i,j);
		deplacement_case_droite(GRILLE,i,j1, TEST);
	}
}


void deplacement_droite(int **GRILLE,int** TEST){
	/* cette fonction effectue le parcours d'une grille placé en parametre*/
	TEST=init_test();
	int i,j;

	for(i=0; i<4; i++){
		for(j=3; j>=0; j--){
			deplacement_case_droite(GRILLE, i, j,TEST);
		}
	}
	free_test(TEST);
}



/*-------------------------------------------------------------------*/






int rand_a_b(int a, int b){
	/*Fonction générant un nombre random entre a et b*/
	return rand()%(b-a) +a;
}


void pop_up(int** GRILLE){
	/*Fonction faisant apparaitre un 2 (7 chances sur 8) ou un 4 (1 chance sur 8) au hasard dans la GRILLE*/
	int num, i=0, j=0, indice_case=0, nb_cases_vides=0, case_a_popup;
  int k=rand_a_b(0,20);

  if(k<18) num=2;
  else num=4;

	for(i=0; i<4; i++){
		for(j=0; j<4; j++){
			if (GRILLE[i][j] == 0) nb_cases_vides++;
		}
	}

	case_a_popup = rand_a_b(0,nb_cases_vides);

	for(i=0; i<4; i++){
		for(j=0; j<4; j++){
			if (case_a_popup == indice_case && GRILLE[i][j]!= 0) case_a_popup++;
			else if (case_a_popup == indice_case) {
				GRILLE[i][j]=num;
			}
			indice_case++;
		}
	}
}


int etat_du_jeu(int** GRILLE, int** TEST){
	/*fonction qui envoie:
	- 0 jeux est en cours
	- 1 gagné
	- -1 perdu*/
	int i,j;

	/*Cas gagné*/
  	for(i=0;i<4;i++){
		for(j=0;j<4;j++){
	  		if (GRILLE[i][j] == 2048) return 1;
		}
	}

	/*Cas perdu*/
	if ((deplacement_possible_gauche(GRILLE,TEST) != 1) && (deplacement_possible_droite(GRILLE,TEST) != 1)
	    && (deplacement_possible_bas(GRILLE, TEST) != 1) && (deplacement_possible_haut(GRILLE,TEST) != 1)){
		return -1;
	}

	/*Cas en cours*/
	return 0;

}


/*Fonction qui retourne 1 si le déplacement à droite est possible, 0 sinon*/

int deplacement_possible_gauche(int** GRILLE,int** TEST){
  int** COPIE=NULL;
  COPIE=cree_copie(GRILLE);
  deplacement_gauche(COPIE,TEST);
  return !matrices_egales(COPIE,GRILLE);
}


/*Fonction qui retourne 1 si le déplacement à droite est possible, 0 sinon*/

int deplacement_possible_droite(int** GRILLE,int** TEST){
  int** COPIE=NULL;
  COPIE=cree_copie(GRILLE);
  deplacement_droite(COPIE,TEST);
  return !matrices_egales(COPIE,GRILLE);
}

/*Fonction qui retourne 1 si le déplacement à haut est possible, 0 sinon*/

int deplacement_possible_haut(int** GRILLE,int** TEST){
  int** COPIE=NULL;
  COPIE=cree_copie(GRILLE);
  deplacement_haut(COPIE,TEST);
  return !matrices_egales(COPIE,GRILLE);
}


/*Fonction qui retourne 1 si le déplacement à bas est possible, 0 sinon*/

int deplacement_possible_bas(int** GRILLE, int** TEST){
  int** COPIE=NULL;
  COPIE=cree_copie(GRILLE);
  deplacement_bas(COPIE, TEST);
  return !matrices_egales(COPIE,GRILLE);
}

/*Fonction qui retourne 1 si les deux matrices sont égales, 0 sinon*/

int matrices_egales(int**COPIE,int** GRILLE){
  int i,j;
  int b=1;
  for(i=0;i<4;i++){
    for(j=0;j<4;j++){
      if(COPIE[i][j]!=GRILLE[i][j]){
	b=0;
      }
    }
  }
  return b;
}


/*Fonction qui renvoie une matrice copie de celle en paramètre*/

int** cree_copie(int** GRILLE){
  int** COPIE=(int**)malloc((4)*sizeof(int*));
  int i,j;
  for(i=0;i<4;i++){
      COPIE[i]=(int*)malloc((4)*sizeof(int));
  }
  for(i=0;i<4;i++){
    for(j=0;j<4;j++){
      COPIE[i][j]=GRILLE[i][j];
    }
  }
  return COPIE;
}


int** init_test(){
	int** TEST=(int**)malloc((4)*sizeof(int*));
	int i,j;
	for(i=0;i<4;i++){
	TEST[i]=(int*)malloc((4)*sizeof(int));
	}
	for(i=0;i<4;i++){
		for(j=0;j<4;j++){
			TEST[i][j]=0;
		}
	}
	return TEST;
}

void free_test(int** TEST){
	int i;
		for(i=0;i<4;i++){
			free(TEST[i]);
		}
	free(TEST);
}




