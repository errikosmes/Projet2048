#include "entete.h"


int main(){
  srand(time(NULL));
  int**  GRILLE=NULL;
  GRILLE=init_grille();
  afficher_grille(GRILLE);
  printf("\n");
  while(etat_du_jeu(GRILLE)==0){
    printf("ok");
    tour_de_jeu(GRILLE);
    pop_up(GRILLE);
    afficher_grille(GRILLE);
    printf("\n");
  }
  return 0;
}
