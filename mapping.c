#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "mapping.h"
#include "fonction_donjon.h"

 

int main()
{
	Dungeon_t donjon;
	init_donjon(donjon, N, M);
	
	int i, j;
	for(i = 40; i< N; i++){
		for(j = 40; j< M; j++){
			printf("%i", donjon.dungeon_map[i][j]);
		}
	}

	//makeCorridor(donjon, 10,7,9,0,5,4);

	/*afficher_Donjon(donjon, xsize, ysize);*/
}

/*(Dungeon_t d, int x, int y, int lenght, int direction, int ysize, int xsize)*/

