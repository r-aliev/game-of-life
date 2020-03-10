/**
 * \brief pour la documentation des fonctions regarder \c io.h
 *
 * \file io.c
 * code source pour les entrées et sorties
 * \author ALIEV Rashid
 * \copyright GNU Public License.
 */
#include "io.h"

/**
 * \param c int  nombre de cellules du trait
 * \return void "affiche"
 */
void affiche_trait (int c){
	int i;
	for (i=0; i<c; ++i) printf ("|---");
	printf("|\n");
	return;
}

/**
 * \param c int nombre de cellules de la ligne
 * \parm ligne int* ligne tableau qui indique si la cellule est morte ou vivante
 * \return void "Affichage d'une ligne de la grille"
 */
void affiche_ligne (int c, int* ligne){
	int i;
	for (i=0; i<c; ++i) 
		if (ligne[i] == 0 ) printf ("|   "); else printf ("| %d ",ligne[i]);
	printf("|\n");
	return;
}
/**
 * \param g grille
 * \return void "Affichage d'une grille
 */
void affiche_grille (grille g){
	int i, l=g.nbl, c=g.nbc;
	printf("\n");
	affiche_trait(c);
	for (i=0; i<l; ++i) {
		affiche_ligne(c, g.cellules[i]);
		affiche_trait(c);
	}	
	printf("\n"); 
	return;
}
/**
 * \param g grille à effacer
 * \return void  "Effacement d'une grille"
 */
void efface_grille (grille g){
	printf("\n\e[%dA",g.nbl*2 + 5); 
}
/**
 * \param g pointeur sur la grille
 * \param gc pointeur sur la copie de la grille
 * \return void  "Debute le jeu"
 */
void debut_jeu(grille *g, grille *gc){
	char c = getchar();
	int tempsDeEvolution = 0;
	int cyclique = 1;
	int vieillissement = 0;
	while (c != 'q') // touche 'q' pour quitter
	{ 
		switch (c) 
		{
			case 'c':
			{
				if(cyclique == 1)
				{
					compte_voisins_vivants = compte_voisins_vivants_non_cyclique ;
					cyclique = 0;
				}else{
					compte_voisins_vivants = compte_voisins_vivants_cyclique ;
					cyclique=1;
				}
				break ;
			}
			case 'v':
			{
				if(vieillissement == 1)
				{
					pt_set_vivante = set_vivante;
					vieillissement = 0;
				}else{
					pt_set_vivante = set_vivante_vieillissement;
					vieillissement = 1;
				}

				break;
			}
			case '\n' : 
			{ // touche "entree" pour évoluer
				evolue(g,gc);
				efface_grille(*g);
				for(int j = 0 ; j < 1 ; j++)
					printf("\033[A\33[2K\r");

				printf("\n\nTemps d'évolution du grille est %d\n\t", ++tempsDeEvolution);
				if(cyclique == 1 )
				{
					printf("cyclique = Activé \n\t");
				}else{
					printf("cyclique = Désactivé \n\t");
				}
				if(vieillissement == 1 )
				{
					printf("vieillissement = Activé \n\t");
				}else{
					printf("vieillissement = Désactivé \n\t");
				}
				affiche_grille(*g);
				break;
			}
			case 'n':
			{
				libere_grille(gc);
				char ng[255];
				printf("Donne le nom du fichier: ");
				scanf("%s",ng);
				init_grille_from_file(ng,g);
				//printf("BraBraBra\n");
				//printf("BraBraBra2\n");
				//
				alloue_grille(g->nbl, g->nbc, gc);
				printf("\n");
				tempsDeEvolution = 0;
				getchar();
				break;
			}
			default : 
			{ // touche non traitée
				printf("\n\e[1A");
				break;
			}
		}
		c = getchar(); 
	}
	return;	
}
