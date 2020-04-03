CC = gcc

DOSEXE = bin
DOSC = src
DOSH = include
DOSO = obj
DOSDOC = doc

CPPFLAGS = -I/usr/include/cairo -Iinclude
LDFLAGS = -lcairo -lm -lX11
ifeq ($(MODE),TEXTE)
CFLAGS1 += -DMODE=TEXTE
endif

CFLAGS = $(CPPFLAGS) -Wall -g

vpath %.c $(DOSC)
vpath %.h $(DOSH)
vpath %.o $(DOSO)

main: main.o jeu.o io.o grille.o ioCairo.o
	mkdir -p $(DOSEXE)
	$(CC) -DMODE$(MODE) $(CFLAGS) -o $(DOSEXE)/$@ $(DOSO)/main.o $(DOSO)/io.o  $(DOSO)/ioCairo.o $(LDFLAGS)

%.o: %.c
	mkdir -p $(DOSO)
	$(CC) -DMODE$(MODE) $(CFLAGS) -o $(DOSO)/$@ -c $<

doc:
	mkdir -p $(DOSDOC)
	doxygen Doxyfile
	mv html latex $(DOSDOC)

clean:
	rm -rf $(DOSO)
	rm -rf $(DOSEXE)
	rm -rf $(DOSDOC)

cleanArchive:
	rm -rf *.tar.xz

dist:
	mkdir -p dist
	tar -J -cvf ALIEV_Rashid_v4.0.tar.xz grilles makefile Doxyfile README.md include src