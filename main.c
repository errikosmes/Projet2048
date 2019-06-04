#include "entete.h"


int main(){
  srand(time(NULL));
  int**  GRILLE=NULL;
  int** TEST=NULL;
  GRILLE=init_grille();
  afficher_grille(GRILLE);
  printf("\n");
  while(etat_du_jeu(GRILLE,TEST)==0){
    tour_de_jeu(GRILLE,TEST);
    printf("sortie");
    afficher_grille(GRILLE);
    printf("\n");
    pop_up(GRILLE);
    afficher_grille(GRILLE);
    printf("\n");
  }
  return 0;
}
