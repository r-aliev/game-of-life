CC = gcc
CFLAGS= -I$(DOSH) -Wall -g 

DOSEXE = bin
DOSC = src
DOSH = include
DOSO = obj
DOSDOC = doc

vpath %.c $(DOSC)
vpath %.h $(DOSH)
vpath %.o $(DOSO)

main: main.o grille.o io.o jeu.o
	mkdir -p $(DOSEXE)
	gcc $(CFLAGS) -o $(DOSEXE)/$@ $(DOSO)/main.o $(DOSO)/jeu.o $(DOSO)/io.o $(DOSO)/grille.o

%.o: %.c
	mkdir -p $(DOSO)
	gcc $(CFLAGS) -o $(DOSO)/$@ -c $<

doc:
	mkdir -p $(DOSDOC)
	doxygen Doxyfile
	mv html latex $(DOSDOC)

clean :
	rm -f *.o && rm -f main
	rm -rf $(DOSEXE)
	rm -rf $(DOSO)
	rm -rf $(DOSDOC)

cleanArchive:
	rm -rf *.tar.xz 

dist: 
	tar -J -cvf ALIEV_Rashid_v3.0.tar.xz $(src)/*.c include/*.h makefile Doxyfile