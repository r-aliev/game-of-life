# Projet : Jeu de la Vie

Implémentation en C du jeu de la vie, l'automate cellulaire de John Conway. 


## Description

**Le Jeu de la Vie (ou Game of Life)** est, en réalité, un automate cellulaire défini en 1970
par le mathématicien anglais **John Conway** afin de tenter de résoudre un problème soulevé par un
mathématicien, père de l’informatique, **John Von Neumann**.
Ce n’est pas à proprement parler un jeu : il ne nécessite pas l’intervention d’un joueur humain, hormis
pour fixer les conditions initiales du jeu. Il se compose d’un univers dans lequel évoluent des cellules
vivantes suivant des règles d’évolution précises.
Dans la version originale décrite par John Conway, l’univers est défini sur une grille à deux dimen-
sions, de taille variable, où chaque case est une cellule pouvant prendre deux états différents : morte ou
vivante. Le passage d’un état à l’autre est guidé par les règles d’évolution suivantes :
  * Une cellule morte au temps t devient vivante au temps t + 1 si et seulement si elle a exactement 3
cellules vivantes dans son voisinage.
  * Une cellule vivante au temps t reste vivante au temps t + 1 si et seulement si elle a exactement 2
ou 3 cellules vivantes dans son voisinage, sinon elle meurt.
  * Le voisinage utilisé est le 8-voisinage : pour une cellule donnée, ses voisines sont les 8 cellules
qui l’entourent

Structure des fichiers
----------------------
- / racine
	- include/ contient toutes les en-têtes de fonctions et structures du programme (*.h)
	- src/ contient toutes les sources (*.c)
	- grilles/ contient l'ensemble des grilles disponibles

Commandes importantes
---------------------

### Compiler le programme

~~~{.sh}
make
~~~
Le fichier exécutable se trouve au chemin suivant : /bin/main
Par défaut, le programme est compilé en mode graphique (Cairo et X requis).

Pour compiler en mode texte :
~~~{.sh}
make MODE=TEXTE
~~~

**ATTENTION :** Il est impératif de nettoyer les artefacts de compilation en passant du mode textuel au mode graphique et vice versa.


### Exécuter le programme

~~~{.sh}
./bin/main grilles/grilleX.txt
~~~

Les grilles se trouvent dans le répertoire /grilles/ et ont comme nom de fichier "grilleX.txt", X indiquant le numéro de la grille.

Exemple :
~~~{.sh}
./bin/main grilles/grille4.txt
~~~

### Générer la documentation (Doxygen)

~~~{.sh}
make doc
~~~
Il suffit ensuite d'ouvrir le fichier doc/html/index.html pour accéder à l'intégralité de la documentation

### Générer une archive du programme

~~~{.sh}
make dist
~~~
L'archive sera crée dans le répertoire /dist

### Nettoyer les artefacts de compilation

~~~{.sh}
make clean
~~~

### Version
- v5.0 : Niveau 5 terminé
- v4.0 : Niveau 4 terminé (GUI)
- v3.0 : Niveau 3 terminé
- v2.0 : Niveau  2 terminé
- v1.0 : Niveau  1 terminé
