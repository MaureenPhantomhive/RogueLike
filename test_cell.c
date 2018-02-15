#include "cell.h"


int main(void) {
	
	// On initialise selon une ID arbitraire, disons "clef" : la cellule est crée
	cell_t *cell=init_cell(clef);

	printf("cell contient une clef d'ID %i. Elle ouvre la porte en (%i, %i).\n", cell->id, cell->type->clef->xporte, cell->type->clef->yporte);
	
	// Structure quelconque - ce n'est pas un pointeur
	arme_t *random_arme=malloc(sizeof *random_arme);
	random_arme->degats=151;
	random_arme->portee=50;
	
	change_cell(cell,clef,arme, random_arme);
			
	printf("Pour Dieu sait quelle raison, la clef est remplacée par une arme (dégâts 151, portée 50) sur cette cellule. cell contient maintenant la structure aux caractéristiques suivantes :\nID : %i\nDégâts : %i\nPortée : %i\n",cell->id, cell->type->arme->degats,cell->type->arme->portee);

	puts("Mais l'arme est récupérée par notre bon héros, et à la place, par la magie du test, c'est un piège qui apparaît !");
	
	// Structure quelconque - c'est un pointeur 
	piege_t *random_piege=malloc(sizeof *random_piege);
	random_piege->degats=25;
	random_piege->xdebut=5;
	random_piege->ydebut=25;
	random_piege->xfin=5;
	random_piege->yfin=35;
		

	change_cell(cell,arme,piege, random_piege);
	
	printf("Ainsi, cell devient un piège qui commence en (%i,%i), s'étend sur un rectangle de dimensions %i*%i, et inflige %i points de dégâts\n", cell->type->piege->xdebut,cell->type->piege->ydebut,cell->type->piege->xfin-cell->type->piege->xdebut+1,cell->type->piege->yfin-cell->type->piege->ydebut+1,cell->type->piege->degats);

	// On doit penser à le free ensuite
	free(random_piege);
	detruire_cell(cell);
	
	
	/* Techniquement, tout marche bien. Un détail malheureux est qu'au changement de type, on tente de free() le type précédent (A) avant d'allouer de la mémoire au type suivant (B). Concrètement, ça marche sans problème si le type A est un pointeur ; s'il ne l'est pas, on tente de free() de l'espace mémoire statique. Ça n'est pas dramatique, mais ça n'est pas propre non plus. */

return 0;
}
