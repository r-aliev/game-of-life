CC = gcc
CFLAGS= -Wall -g 

vpath %.c src
vpath %.h include
vpath %.o obj

main: main.o grille.o io.o jeu.o
	mkdir -p bin
	$(CC) $(CFLAGS) -o bin/$@ obj/main.o obj/jeu.o obj/io.o obj/grille.o
	
%.o: %.c
	mkdir -p obj
	$(CC) $(CFLAGS) -o obj/$@ -c $<

doc:
	mkdir -p doc
	doxygen Doxyfile
	mv html latex doc

clean :
	rm -f *.o && rm -f main
	rm -rf bin
	rm -rf obj
	rm -rf doc

cleanArchive:
	rm -rf *.tar.xz 

dist: 
	tar -J -cvf ALIEV_Rashid_v3.0.tar.xz $(src)/*.c include/*.h makefile Doxyfile