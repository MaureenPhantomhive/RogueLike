#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "mapping.h"

int cpt_time = 0; 

void init_donjon(Dungeon_t d, int xsize,int ysize){
	int i;
	int j;
	
	for(i = 0; i < xsize; i++){
		for(j = 0; j< ysize; j++){
			d.dungeon_map[i][j] = 0;
		}
	}
}

void texture(Dungeon_t d, int x, int y, int celltype)
{
	  d.dungeon_map[x][y] = celltype;
}

int nbr_aleatoire(int min, int max)
{
	if(cpt_time == 0){
		srand(time(NULL)); /*Initialisation de rand*/
		cpt_time++;
	}	
	int i;
	int nbr_al_tmp, nbr_al;
	nbr_al_tmp=rand()%20000;
	nbr_al = nbr_al_tmp%(max - min) + min;
	return nbr_al;
}

int adr_cellule(Dungeon_t d, int x, int y)
{
	  return d.dungeon_map[x][y];
}

int makeCorridor(Dungeon_t d, int x, int y, int lenght, int direction, int ysize, int xsize)
{
	int len = nbr_aleatoire(2,lenght); /*Renvoie la taille du couloir*/
	printf("%i", len);
	int floor = clt_Corridor;
	
	int dir;
	
	if(direction > 0 && direction < 4){
		dir = direction;
	}
	
	int long_prov = 0;
	int larg_prov = 0;
	int i;
	int j;
	
	switch(dir){
	      case 0:
					{
						for(i = x; i < x + len; i++){
							texture(d, i, y, floor);
						}
					}
	}
//woot, we're still here! let's tell the other guys we're done!!
return 1;
}


/*int makeRoom(Dungeon_t d,int x, int y, int xlength, int ylength, int direction, int ysize, int xsize){
}

*/
void afficher_Donjon(Dungeon_t d, int xsize, int ysize){
	for (int x = 0; x < xsize; x++){
		for (int y = 0; y < ysize; y++){
			switch(adr_cellule(d, x, y)){
			case clt_None:
				printf(" ");
				break;
			case clt_Wall:
				printf("#");
				break;
			case clt_Floor:
				printf(".");
				break;
			case clt_Corridor:
				printf(".");
				break;
			case clt_Door:
				printf("+");
				break;
			case clt_Chest:
				printf("*");
				break;
			}
		}
		//if (xsize <= d.xmax) printf("\n");
	}
}

/*int createDungeon_t(Dungeon_t d,int inx, int iny, int inobj){

		}
	}
}*/

