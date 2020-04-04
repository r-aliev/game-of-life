/**
 * \brief pour la documentation des fonctions regarder \c ioCairo.h
 *
 * \file ioCairo.c
 * code source pour les entrées et sorties de mode graphique Cairo
 * \author ALIEV Rashid
 * \copyright GNU Public License.
 */

#include "ioCairo.h"

void affiche_grille_cairo(cairo_surface_t* surface, grille g)
{

	cairo_t *cr;
	cr=cairo_create(surface);	
    cairo_set_source_rgb (cr, 0.4, 0.0, 0.7);
	cairo_paint(cr);
    int l = g.nbl;
    int c = g.nbc;
    cairo_set_source_rgb(cr, 1.0, 1.0, 1.0);

    ////////////////////////////////////////
    for(int decale = 0 ; decale <= l ; decale++)
	{
		cairo_move_to (cr, MARGX, (decale*CELLSIZE) + MARGY);
		cairo_line_to(cr, (c*CELLSIZE) +  MARGX, (decale*CELLSIZE) + MARGY);
		cairo_set_line_width (cr, 1);
		cairo_stroke (cr);
	}
	for(int decale = 0 ; decale <= c ; decale++)
	{
		cairo_move_to (cr, (decale*CELLSIZE) + MARGX, MARGY);
		cairo_line_to(cr, (decale*CELLSIZE) + MARGX, MARGY + (l*CELLSIZE));
		cairo_set_line_width (cr, 1);
		cairo_stroke (cr);
	}
	for(int i = 0 ; i < l ; i++)
	for(int j = 0 ; j < c ; j++)
	{
		if(est_vivante(i,j,g))
		{
			int cell_vivante = (g.cellules[i][j] - 1);
			cairo_rectangle(cr, (j*CELLSIZE) + MARGX + 1, (i*CELLSIZE) + MARGY + 1, CELLSIZE - 4, CELLSIZE - 4);
			cairo_set_source_rgb (cr, (cell_vivante/6.0), 1 - (cell_vivante/6.0) , 0.0);
			cairo_fill(cr);
		}
		else if(g.cellules[i][j] == -1)
		{
			cairo_rectangle(cr, MARGX + (j * CELLSIZE) + 1 , MARGY + (i * CELLSIZE) + 1, CELLSIZE - 4, CELLSIZE - 4);
			cairo_set_source_rgb (cr, 1.0, 1.0, 1.0);
			cairo_fill(cr);
		}
	}
	cairo_destroy(cr);
}



void debut_jeu_cairo(grille *g, grille *gc)
{
	// X11 display
	Display *dpy;
	Window rootwin;
	Window win;
	XEvent e;
	int scr;
	int q = 0, v=0, i=0, c=1;
	char str[12];
	
	// init the display
	if(!(dpy=XOpenDisplay(NULL))) {
		fprintf(stderr, "ERROR: Could not open display\n");
		exit(1);
	}

	scr=DefaultScreen(dpy);
	rootwin=RootWindow(dpy, scr);

	win=XCreateSimpleWindow(dpy, rootwin, 1, 1, SIZEX, SIZEY, 0, 
			BlackPixel(dpy, scr), BlackPixel(dpy, scr));

	XStoreName(dpy, win, "Jeu de La Vie");
	XSelectInput(dpy, win, ExposureMask|ButtonPressMask|KeyPressMask | KeyReleaseMask);
	XMapWindow(dpy, win);
	//create cairo surface
	cairo_surface_t *cs; 
	cs=cairo_xlib_surface_create(dpy, win, DefaultVisual(dpy, 0), SIZEX, SIZEY);
	while(q == 0)
	{
		sprintf(str, "%d", i);
		affiche_grille_cairo(cs, *g);
    	cairo_t *cr = cairo_create(cs);
				cairo_select_font_face(cr, "Arial",
					CAIRO_FONT_SLANT_NORMAL,
					CAIRO_FONT_WEIGHT_BOLD);
				cairo_set_font_size(cr, 15);

		cairo_set_source_rgb (cr, 0.9, 0.9, 0.9);
    	cairo_move_to (cr, MARGX, MARGY - 30);
    	cairo_show_text (cr, "Temps d'évolution: ");
    	cairo_show_text (cr, str);
		//Cyclique ou pas
		cairo_show_text (cr, "    Cyclique : ");
		if(c)	cairo_show_text(cr, "OUI");
		else	cairo_show_text(cr, "NON");
		//Veilliesement est allumé ou pas
		cairo_show_text (cr, "    Vieillisement : ");
		if(v)	cairo_show_text(cr, "OUI");
		else cairo_show_text(cr, "NON");

		cairo_destroy(cr); // destroy cairo mask
	
			XNextEvent(dpy, &e);
			if (e.type == KeyPress) {
				switch(e.xkey.keycode){
					case  13: // touch enter (PROBLEM)
					{	
						i++;
						evolue(g,gc);
						break;
					}
					case 57: // touche n
					{
						char inputBuffer[256];
						printf("Entrez le chemin vers le fichier : ");
						scanf( " %99[^\n]", inputBuffer);

						libere_grille(g) ;
						init_grille_from_file(inputBuffer, g);

						libere_grille(gc) ;
						alloue_grille (g->nbl, g->nbc, gc);

						for(int j = 0 ; j < 1 ; j++)
							printf("\033[A\33[2K\r");
						i = 0 ;
						break ;
					}
					case 54: //touche c
					{
						c = (c+1)%2 ;
						if(c) compte_voisins_vivants = compte_voisins_vivants_cyclique ;
						else compte_voisins_vivants = compte_voisins_vivants_non_cyclique ;
						break;
					}
					case 55: //touche v
					{
						v =  (v+1)%2 ;
						if(v) pt_set_vivante = set_vivante_vieillissement ;
						else pt_set_vivante = set_vivante;
						break;
					}
					case 81: //touche q
					{
						q = 1;
						break;
					}
					case 32:
					{//o
						int o = oscillant(*g) ;
						cairo_t *cr = cairo_create(cs);

						cairo_select_font_face(cr, "Arial",
							CAIRO_FONT_SLANT_NORMAL,
							CAIRO_FONT_WEIGHT_BOLD);
						cairo_set_font_size(cr, 15);						
						cairo_set_source_rgb (cr, 1, 1, 1);
    					cairo_move_to (cr, MARGX, MARGY-50);
						switch(o)
						{
							case 0:
							{
								cairo_show_text (cr, "Non Oscillante.");
								break;
							}
							case -1:
							{
								cairo_show_text (cr, "Grille est Vide.");
								break;
							}
							case 1:
							{
								cairo_show_text(cr, "Grille est Statique.");
								break;
							}
							default:
							{
								cairo_show_text (cr, "Periode = ");
    							sprintf(str, "%d", o);
								cairo_show_text (cr, str);
								break;
							}
						}
						XNextEvent(dpy, &e);
						XNextEvent(dpy, &e);
						cairo_destroy(cr);
						break ;
					}

				}

			}else if(e.type == ButtonPress){
				switch(e.xbutton.button)
				{
					case 1:
					{
						i++;
						evolue(g,gc);
						break;
					}
					case 3:
					{
						q=1 ;
						break;
					}
				}
			}
		}
	cairo_surface_destroy(cs);
	XCloseDisplay(dpy);
	return ;
}

void paint(cairo_surface_t* surface)
{
	// create cairo mask
	cairo_t *cr;
	cr=cairo_create(surface);

	// background
	cairo_set_source_rgb (cr, 0.0, 0.0, 0.0);
	cairo_paint(cr);
	
	// line
	cairo_set_source_rgb (cr, 1.0, 0.0, 0.0);
	cairo_move_to (cr, 10.0, 50.0);
	cairo_line_to(cr, 100.0,50.0);
	cairo_set_line_width (cr, 1);
	cairo_stroke (cr);

	// filled rectangle
	cairo_rectangle(cr,30,30,50,50);
	cairo_set_source_rgb (cr, 0.0, 1.0, 0.0);
	cairo_fill(cr);	

	cairo_destroy(cr);
}

