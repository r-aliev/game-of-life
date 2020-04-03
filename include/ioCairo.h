#ifndef __IOCAIRO_H__
#define __IOCAIRO_H__
#include <stdio.h>
#include <stdlib.h>
#include "jeu.h"
#include "grille.h"
#include <cairo.h>
#include <cairo-xlib.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#define SIZEX 650
#define SIZEY 650
#define CELLSIZE 40
#define MARGX 20
#define MARGY 100
#define CELLSIZE 40

void affice_grille_cairo(cairo_surface_t* surface, grille g);
void debut_jeu_cairo(grille *g, grille* gc);
void paint(cairo_surface_t* surface);

#endif