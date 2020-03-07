/**
 * \brief pour la documentation des fonctions regarder \c jeu.h
 *
 * \file jeu.c 
 * code source pour les grilles, contient les fonctions de manipulations
 * \author ALIEV Rashid
 * \copyright GNU Public License.
 */


#include "jeu.h"

/**
 * \param i int
 * \param j int
 * \param g* grille
 * \rerturn \int nombre des voisins vivantes  
 * \brief compte le nombre de voisins vivants de la cellule (i,j) | les bords sont cycliques.
 */ 
int compte_voisins_vivants_cyclique (int i, int j, grille g){
	int v = 0, l=g.nbl, c = g.nbc;
	v+= est_vivante(modulo(i-1,l),modulo(j-1,c),g);
	v+= est_vivante(modulo(i-1,l),modulo(j,c),g);
	v+= est_vivante(modulo(i-1,l),modulo(j+1,c),g);
	v+= est_vivante(modulo(i,l),modulo(j-1,c),g);
	v+= est_vivante(modulo(i,l),modulo(j+1,c),g);
	v+= est_vivante(modulo(i+1,l),modulo(j-1,c),g);
	v+= est_vivante(modulo(i+1,l),modulo(j,c),g);
	v+= est_vivante(modulo(i+1,l),modulo(j+1,c),g);

	return v; 
}

/**
 * \param i int
 * \param j int
 * \param g* grille
 * \result \c int le nombre de voisins vivants 
 * \brief les bords sont non cycliques.
 */ 
int compte_voisins_vivants_non_cyclique (int i, int j, grille g){
	int v = 0, l=g.nbl, c = g.nbc;
	
	int a,b;
	for (a=-1;a <=1;a++)
	{
		for (b = -1;b <= 1;b++)
		{
	    	if (a!=0 || b!=0)
			{
		      	if (a+i>=0 && a+i< l && b+j>=0 && b+j< c)
				{
					v += est_vivante(a+i, b+j, g);
		        }
	    	}
  		}
	}
	return v;
}

/**
 * \param i int
 * \param j int
 * \param g* grille
 * \return \c int le nombre de voisins vivants 
 * \brief pointeur de fonction utilisé pour faire marcher button 'c'
 */ 
int (*compte_voisins_vivants) (int, int, grille) = compte_voisins_vivants_cyclique ;
/**
 * \param i int
 * \param j int
 * \param g* grille
 * \return void modification du grille 
 * \brief pointeur de fonction utilisé pour faire marcher button 'v'
 */ 
void (*pt_set_vivante) (int, int, grille) = set_vivante ;


/**
 * \param g grille*
 * \param gc grille*
 * \return void  fait évoluer la grille g d'un pas de temps
 */
void evolue (grille *g, grille *gc){
	copie_grille (*g,*gc); // copie temporaire de la grille
	int i,j,l=g->nbl, c = g->nbc,v;
	for (i=0; i<l; i++)
	{
		for (j=0; j<c; ++j)
		{
			v = compte_voisins_vivants (i, j, *gc);
			if (est_vivante(i,j,*g)) 
			{ // evolution d'une cellule vivante
				if ( v!=2 && v!= 3 ) set_morte(i,j,*g);
			}
			else 
			{ // evolution d'une cellule morte
				if ( v==3 ) set_vivante(i,j,*g);
			}
		}
	}
	return;
}
