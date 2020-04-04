/**
 * \brief déclarations des fonctions utilisées dans grille.c
 *
 * \file grille.h 
 * headers pour grille.c
 * \author ALIEV Rashid
 * \copyright GNU Public License.
 */
#ifndef __GRILLE_H
#define __GRILLE_H

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>


/**
 * \typedef  \c grille;
 * Déclaration de la structure de grille
 */
typedef struct {int nbl; int nbc; int** cellules;} grille;
 
/**
 * \fn void alloue_grille(int l, int c, grille* g)
 * \memberof grille
 * \param l int
 * \param c int
 * \param g* grille
 * \pre l et c > 0
 * \brief alloue une grille de taille l*c, et initialise toutes les cellules à 0
 *
 * \post les valeurs des cellules sont modifier
 * \ return void "arrgument grille modifié"
 */
void alloue_grille (int l, int c, grille* g);

/**
 * \fn void libere_grille (grille* g)
 * \memberof grille
 * \param g* grille
 * \brief libère une grille
 * \post grille en argument libre
 * \return void
 */
void libere_grille (grille* g);

/**
 * \fn void init_grille_from_file (char * filename, grille* g)
 * \memberof grille
 * \param filename* char
 * \param g* grille
 * \pre grille est libérée, sinon probléme de mémoire
 * \brief alloue et initalise la grille g à partir d'un fichier
 *
 * \return void "avec argument modifier"
 * \post la grille en argument est modifer
 */ 
void init_grille_from_file (char * filename, grille* g);

/**
 * \fn static inline void set_vivante (int i, int j, grille g)
 * \memberof grille
 * \param i int
 * \param j int
 * \param g grille
 * \pre i et j dans la grille
 * \brief rend vivante la cellule (i,j) de la grille g
 *
 * \return void "modifie la cellule (i,j) de la grille g"
 * \post modification d'une cellule de la grille en paramètre
 */ 
static inline void set_vivante(int i, int j, grille g){g.cellules[i][j] = 1;}

/**
 * \fn static inline void set_morte(int i, int j, grille g)
 * \memberof grille
 * \param i int
 * \param j int
 * \param g grille
 * \pre i et j dans la grille
 * \brief rend morte la cellule (i,j) de la grille g
 *
 * \return void "modifie une cellule du grille"
 * \post modification d'une cellule
 */ 
static inline void set_morte(int i, int j, grille g){g.cellules[i][j] = 0;}

/**
 * \fn static inline void set_vivante_vieillisement (int i, int j, grille g)
 * \memberof grille
 * \param i int
 * \param j int
 * \param g grille
 * \pre i et j dans la grille
 * \brief rend vivante la cellule (i,j) de la grille g
 *
 * même avec la fonction set_vivante, mais avec l'option de vieillisement
 * \return void "modifie la cellule (i,j) de la grille g"
 * \post modification d'une cellule de la grille en paramètre
 */ 
static inline void set_vivante_vieillissement(int i, int j, grille g)
{ 
	++g.cellules[i][j] ;
	g.cellules[i][j] %= 10 ;
}

/**
 * \fn static inline int est_vivante(int i, int j, grille g)
 * \memberof grille
 * \param i int
 * \param j int
 * \param g grille
 * \pre i et j dans la grille
 * \brief test si la cellule (i,j) de la grille g est vivante ou pas
 * \return test si la cellule (i,j) de la grille g est vivante ou pas (\c int)
 */ 
static inline int est_vivante(int i, int j, grille g){return g.cellules[i][j] > 0;}

/**
 * \fn void copie_grille (grille gs, grille gd)
 * \memberof grille
 * \param gs grille
 * \param gd grille
 * \pre les deux grilles doivent être de même taille
 * \brief  récopie gs dans gd (sans allocation)
 *
 * \return void "avec modification du grille gd"
 * \post la grille gd est modifié
 */
void copie_grille (grille gs, grille gd);



#endif
