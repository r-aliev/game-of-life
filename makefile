CC = gcc

DOSEXE = bin
DOSC = src
DOSH = include
DOSO = obj
DOSDOC = doc
DOSLIB = lib

CPPFLAGS = -I/usr/include/cairo -Iinclude
LDFLAGS = -lcairo -lm -lX11 -ljeu -L lib/
ifeq ($(MODE),TEXTE)
CFLAGS += -DMODE=TEXTE
endif

CFLAGS = $(CPPFLAGS) -Wall -g

vpath %.c $(DOSC)
vpath %.h $(DOSH)
vpath %.o $(DOSO)

main: main.o jeu.o io.o grille.o ioCairo.o
	mkdir -p $(DOSEXE)
	mkdir -p $(DOSLIB)

	ar -crv $(DOSLIB)/libjeu.a $(DOSO)/jeu.o $(DOSO)/grille.o
	ranlib $(DOSLIB)/libjeu.a

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
	rm -rf $(DOSLIB)

cleanArchive:
	rm -rf *.tar.xz

dist:
	tar -J -cvf ALIEV_Rashid_v5.0.tar.xz makefile Doxyfile README.md include src