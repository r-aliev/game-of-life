/**
 * \file
 * fichier main
 * \author ALIEV Rashid
 */
#include "grille.h"
#include "jeu.h"

#if MODE==TEXTE 
#include "io.h"
int main (int argc, char ** argv) {
	if (argc != 2 )
	{
		printf("usage : main <fichier grille>");
		return 1;
	}
	grille g, gc;
	init_grille_from_file(argv[1],&g);
	alloue_grille (g.nbl, g.nbc, &gc);
	affiche_grille(g);
	
	debut_jeu(&g, &gc);

	libere_grille(&g);
	libere_grille(&gc);
	return 0;
}
#else

#include "ioCairo.h"
int main (int argc, char ** argv) {
	if (argc != 2 )
	{
		printf("usage : main <fichier grille>");
		return 1;
	}
	grille g, gc;
	init_grille_from_file(argv[1], &g);
	alloue_grille (g.nbl, g.nbc, &gc);
	debut_jeu_cairo(&g, &gc);
	libere_grille( &g) ;
	libere_grille( &gc );

	return 0;
}
#endif