/**
 * \brief contient les declarations des fonctions utilisées dans jeu.c
 *
 * \file jeu.h 
 * headers pour jeu.c
 * \author ALIEV Rashid
 * \copyright GNU Public License.
 */
#ifndef __JEU_H
#define __JEU_H

#include "grille.h"

/**
 * \fn static inline int modulo(int i, int m)
 * \param i int
 * \param m int
 * \retrun \c int i mod m
 * \brief  modulo modifié pour traiter correctement les bords i=0 et j=0 | dans le calcul des voisins avec bords cycliques
 */ 
static inline int modulo(int i, int m) {return (i+m)%m;}

/**
 * \fn int compte_voisins_vivants_cyclique (int i, int j, grille g)
 * \memberof grille
 * \param i int
 * \param j int
 * \param g* grille
 * \pre i et j dans la grille g
 * \result \c int le nombre de voisins de la cellule compte le nombre de voisins vivants de la cellule (i,j)
 * \brief compte le nombre de voisins vivants de la cellule (i,j) | les bords sont cycliques.
 */ 

int compte_voisins_vivants_cyclique (int i, int j, grille g);

/**
 * \fn int compte_voisins_vivants_non_cyclique (int i, int j, grille g)
 * \memberof grille
 * \param i int
 * \param j int
 * \param g* grille
 * \pre i et j dans la grille g
 * \result \c int le nombre de voisins de la cellule compte le nombre de voisins vivants de la cellule (i,j)
 * \brief compte le nombre de voisins avec les bords non cycliques.
 */  
int compte_voisins_vivants_non_cyclique (int i, int j, grille g);

/**
 * \fn void evolue (grille *g, grille *gc)
 * \memberof grille
 * \param g grille*
 * \param gc grille*
 * \pre les deux grilles doivent étre de même taille
 * \brief fait évoluer la grille g d'un pas de temps
 *
 * \post les deux grilles change
 * \return void avec l'evolution du g et le changement du gc
 */
void evolue (grille *g, grille *gc);

/**
 * \fn int (*compte_voisins_vivants) (int, int, grille)
 * \brief pointeur vers fontion compte_voisins_vivants_non_cyclique
 * \memberof grille
 * \param int
 * \param int
 * \param grille
 * \pre les deux entiers represent les coordonées d'une grille
 * \return void
 * le pointeur est utilisé afin de changer facilement entre les deux choix cyclique ou pas 
 * point vers \c compte_voisins_vivants_cyclique ou \c compte_voisins_vivants_non_cyclique
 */
int (*compte_voisins_vivants) (int, int, grille)  ;

/**
 * \fn void (*pt_set_vivante) (int, int, grille)
 * \brief pointeur vers fontion set_vivante ou set_vivante_avec_vieillisement
 * \memberof grille
 * \param int
 * \param int
 * \param grille
 * \pre les deux entiers represent les coordonées d'une grille
 * \return void
 * le pointeur est utilisé afin de changer facilement entre les deux choix vieillisemet ou pas 
 * point vers \c set_vivante ou \c set_vivante_avec_vieillisement
 */
void (*pt_set_vivante) (int, int, grille);


#endif
