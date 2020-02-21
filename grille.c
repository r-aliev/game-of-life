#include "grille.h"

void init_grille_from_file (char * filename, grille* g){
	FILE * pfile = NULL;
	pfile = fopen(filename, "r");
	assert (pfile != NULL);
	
	int i,j,n,l,c,vivantes=0;
	
	fscanf(pfile, "%d", & l);
	fscanf(pfile, "%d", & c);
	
	alloue_grille(l,c,g);
	
	fscanf(pfile, "%d", & vivantes);
	for (n=0; n< vivantes; ++n){
		fscanf(pfile, "%d", & i);
		fscanf(pfile, "%d", & j);
		set_vivante(i,j,*g);
	}
	
	fclose (pfile);
	return;
}


void copie_grille (grille gs, grille gd){
	int i, j;
	for (i=0; i<gs.nbl; ++i) for (j=0; j<gs.nbc; ++j) gd.cellules[i][j] = gs.cellules[i][j];
	return;	
}

void alloue_grille (int l, int c, grille* g){
	g->nbl = l;
	g->nbc = c;
	g->cellules =(int**) malloc(l * sizeof(int*));
	for(int i = 0;i < l; i++){
		g->cellules[i] =(int*) calloc(c , sizeof(int));
	}
}

void libere_grille(grille* g){
	for(int i = 0; i < g->nbl; i++){
		free(g->cellules[i]);
	}
	free(g->cellules);
}

/*
int main(int argc, char const *argv[])
{
	grille* g  = malloc(sizeof(grille));
	init_grille_from_file("grilles/grille3.txt" , g);
	printf("%d\n",g->cellules[5][5]);
	
	for(int i =0 ; i< g->nbc ; i++){
		for(int j=0 ;j< g->nbl ; j++){
			printf("%d ",g->cellules[i][j] );
		}
		printf("\n");
	}
	
	grille gn  ;
	alloue_grille(g->nbl , g->nbc , &gn);
	copie_grille(*g , gn);
	printf("%d\n",gn.cellules[5][5]);
	
	return 0;
}
*/


