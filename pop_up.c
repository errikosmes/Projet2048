void pop_up(int** GRILLE){
  /*Fonction faisant apparaitre un 2 (7 chances sur 8) ou un 4 (1 chance sur 8) au hasard dans la GRILLE*/

  int num, i=0, j=0, indice_case=0;
  int k=rand_a_b(0,19);
  
  if(k<18) num=2;
  else num=4;
  
  /*while(k!=0){
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
  GRILLE[i][j]=num;*/

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
			}
		}
	}
}