/**
 * \brief Déclarations des fonctions de io.c
 *
 * \file io.h 
 * headers pour io.c
 * \author Rashid ALIEV
 * \copyright GNU Public License.
 */
#ifndef __IO_H
#define __IO_H

#include <stdio.h>
#include "grille.h"
#include "jeu.h"

/**
 * \fn void affiche_trait(int c)
 * \memberof grille
 * \param c int
 * \pre c positif
 * \return void 
 * \post affichage d'un trait horizontal
 * \brief affiche un trait horizontal 
 */
void affiche_trait (int c);

/**
 * \fn void affiche_ligne (int c)
 * \memberof grille
 * \param c int
 * \parm ligne int*
 * \pre c positif
 * \pre ligne de taille c
 * \post affichage d'une ligne de la grille
 * \return void 
 * \brief affichage d'une ligne de la grille
 */
void affiche_ligne (int c, int* ligne);

/**
 * \fn void affiche_grille (grille g)
 * \memberof grille
 * \param g grille
 * \post affichage d'une grille
 * \return void
 * \brief pour utiliser d'autres fonctions d'affichage pour affichage d'une grille 
 */ 
void affiche_grille (grille g);

/**
 * \fn void efface grille(grille g)
 * \memberof grille
 * \param g grille
 * \post effacement d'une grille
 * \return void
 * \brief efface la grille
 * 
 * efface pas complétement, mais échange la position du tête d'écriture, ne marchera pas pour les grilles appelé aprés
 */
void efface_grille (grille g);

/**
 * \fn void debut_jeu(grille *g, grille *gc)
 * \memberof grille
 * \param g grille*
 * \param gc grille*
 * \pre les deux grilles de même tailles
 * \post debute le jeu
 * \return void
 * \brief la foncion principale pour debuter le jeu
 *
 * appelle la plupart des autres fonction 
 */
void debut_jeu(grille *g, grille *gc);

#endif
