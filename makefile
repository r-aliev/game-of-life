main: main.o grille.o io.o jeu.o
	gcc -o main main.o grille.o io.o jeu.o

main.o : main.c grille.h io.h jeu.h
	gcc -c main.c

grille.o : grille.c grille.h
	gcc -c grille.c

jeu.o : jeu.c jeu.h
	gcc -c jeu.c

io.o : io.c io.h grille.h jeu.h
	gcc -c io.c
clean :
	rm -f *.o && rm -f main
dist: 
	tar -J -cvf RashidALIEV.tar.xz *.c *.h makefile doxyfile
