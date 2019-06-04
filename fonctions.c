#include <stdio.h>
#include <stdlib.h>
#include "entete.h"

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
  /*Fonction faisant apparaitre un 2 (9 chances sur 10) ou un 4 (1 chance sur 10) au hasard dans la GRILLE*/

  int num;
  int i=0;
  int j=0;
  int k=rand_a_b(0,20);

  if(k<18) num=2;
  else num=4;
  while(k!=0){
	if(GRILLE[i][j]==0){
	  k--;
	}
	i++;
	if(i==4){
	  i=0;
	  j++;  
	}
	if(j==4)
	  j=0;
   }
   if(i!=0){
     i--;
   }
   else {
     j--;
     i=3;
   }

   
   GRILLE[i][j]=num;
}

   /*Fonction faisant apparaitre un 2 (7 chances sur 8) ou un 4 (1 chance sur 8) au hasard dans la GRILLE*/
   /*
  int num, i=0, j=0, indice_case=0;
  int k=rand_a_b(0,19);
  
  if(k<18) num=2;
  else num=4;
  
  while(k!=0){
	if(GRILLE[i][j]==0){
	  k--;
	}
	
	j++;
	if(j==4){
	  j=0;
	  i++;  
	}
	if(i==4)
	  i=0;
  }
  GRILLE[i][j]=num;

<<<<<<< HEAD
	while(indice_case<k){
		for(i=0; i<4; i++){
			for(j=0; j<4; j++){
				if (indice_case == k ){
					if (GRILLE[i][j]!=0) {
						GRILLE[i][j]=num;
						return;
					}
					else k++;
				}
				indice_case++; 
=======
	for(i=0; i<4; i++){
		for(j=0; j<4; j++){
			if (case_a_popup == indice_case) {	
				GRILLE[i][j]=num;
>>>>>>> parent of dca5174... fix cas ou le pop up est dans une case pas vide
			}
		}
	}
}*/



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

void afficher_grille(int** GRILLE){
  /*Fonction affichant la GRILLE*/
	int i,j;
  	for(i=0;i<4;i++){
		for(j=0;j<4;j++){
	  	printf("| %d ",GRILLE[i][j]);
	}
	printf("|\n");
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


void tour_de_jeu(int** GRILLE, int** TEST){
		printf("ok");
         switch(getchar()) { // the real value
			case 'z':
				printf("up\n");
				if (deplacement_possible_haut(GRILLE,TEST)){
					printf("dep possible haut");
					deplacement_haut(GRILLE, TEST);
				}
				else {
					printf("dep impossible haut");
					getchar();
					tour_de_jeu(GRILLE, TEST);
				}
				break;
			case 's':
				printf("down\n");
				if (deplacement_possible_bas(GRILLE,TEST)){
					printf("dep possible bas");
					deplacement_bas(GRILLE, TEST);
					printf("deplacem bas ok");
				}
				else {
					printf("dep impossible bas");
					getchar();
					tour_de_jeu(GRILLE, TEST);
				}
				break;
			case 'd':
				printf("right\n");
				if (deplacement_possible_droite(GRILLE,TEST)){
					printf("dep possible droite");
					deplacement_droite(GRILLE,TEST);
				}
				else {
					printf("dep impossible droite");
					getchar();
					tour_de_jeu(GRILLE, TEST);
				}
				break;
			case 'q':
				printf("left\n");
				if (deplacement_possible_gauche(GRILLE,TEST)){
					printf("dep possible gauche");
					deplacement_gauche(GRILLE, TEST);
				}
				else {
					printf("dep impossible gauche");
					getchar();
					tour_de_jeu(GRILLE, TEST);
				}
				break;
			default:
				printf("erreur");
				getchar();
				tour_de_jeu(GRILLE, TEST);
				break;

			
		}
		
		/*getchar();*/
printf("ok2");

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
