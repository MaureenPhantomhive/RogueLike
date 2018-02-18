#include <stdlib.h>
#include <stdio.h>
#include "commun.h"

void texture(Dungeon_t d,int x, int y, int celltype); //Donne une texture à une cellule
int adr_cellule(Dungeon_t d, int x, int y); //Renvoie l'adresse d'une cellule
int nbr_aleatoire(int max); //Renvoie un nombre aléatoire comprise entre min et max
int makeCorridor(Dungeon_t d, int x, int y, int lenght, int direction, int ysize, int xsize); //Met en place un couloir de taille length vers direction
int makeRoom(Dungeon_t d,int x, int y, int xlength, int ylength, int direction, int ysize, int xsize); //Crée une salle 
void afficher_Donjon(Dungeon_t d, int xsize, int ysize); //Affiche le donjon 
int createDungeon(Dungeon_t d, int inx, int iny, int inobj); //Crée le donjon
void init_donjon(Dungeon_t d,int xsize,int ysize);

