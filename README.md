#Projet : Jeu de la Vie

Implémentation en C du jeu de la vie, l'automate cellulaire de John Conway.

## description

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
