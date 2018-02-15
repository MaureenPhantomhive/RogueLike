#include "cell.h"
#include "core.h"

void free_cell_type(cell_t* cell, int id) { // helper qui évitera de répéter dix fois la même chose
	switch(id) {
	case clef: FREE(cell->type->clef); break;
	case levier: FREE(cell->type->levier); break;
	case arme: FREE(cell->type->arme); break;
	case tresor: FREE(cell->type->tresor); break;
	case piege: FREE(cell->type->piege); break;	
	default: break;
	}
}



/** Wrapper : initialise une cellule selon une id donnée (= type de la cellule))
* L'id sera fournie par une fonction qui récupère dans le layout de la map le 
* chiffre correspondant à une valeur donnée, 
* de telle sorte que la valeur d'une tile soit l'id correspondante */ 

cell_t* init_cell(const int id) {
	cell_t *cell=malloc(sizeof *cell);
	cell->type=malloc(sizeof(cell_type));
	
	switch(id) { // aka "overloading du pauvre"
	case clef: init_cell_clef(cell); break;
	case levier: init_cell_levier(cell); break;
	case arme: init_cell_arme(cell); break;
	case tresor: init_cell_tresor(cell); break;
	case piege: init_cell_piege(cell); break;
	default: init_cell_defaut(cell, id); break;	
	}
	return cell;	
}

/** Sous-fonction d'initialisation au comportement unique :

* Elle peut prendre plusieurs types et récupère donc l'id fournie 
	dans init_cell, là où les autres savent ce qu'elles font. 
* En l'état, init_cell_defaut() est à appeler pour créer : 
  un mur, une porte, ou une cellule vide 
* Puisqu'il faut donner une valeu à .type, on lui attribue arbitrairement -1 */
void init_cell_defaut(cell_t *cell, int id) {
	cell->id=id;
	cell->type->cell_defaut=-1;
}

/** Initialise une cellule contenant une clef 
* Les valeurs données seront arbitraires dans un premier temps */
void init_cell_clef(cell_t *cell) {
	cell->id=clef;
	cell->type->clef=malloc(sizeof(clef_t));
	cell->type->clef->xporte=5;
	cell->type->clef->yporte=8;
	cell->type->clef->statut=active;
}
/** Initialise une cellule contenant une arme 
* Les valeurs données seront arbitraires dans un premier temps */
void init_cell_arme(cell_t *cell) {
	cell->id=arme;
	cell->type->arme=malloc(sizeof(arme_t));
	cell->type->arme->degats=15;
	cell->type->arme->portee=25;
}

/** Initialise une cellule contenant un trésor 
* Les valeurs données seront arbitraires dans un premier temps */
void init_cell_tresor(cell_t *cell) {
	cell->id=tresor;
	cell->type->tresor=malloc(sizeof(tresor_t));
	cell->type->tresor->score=50;
}

/** Initialise une cellule contenant un piège
* Les valeurs données seront arbitraires dans un premier temps */
void init_cell_piege(cell_t *cell) {
	piege_t tmp={5,5,7,5,20};
	cell->type->piege=malloc(sizeof(piege_t));
	cell->id=piege;
	*(cell->type->piege)=tmp;
}



/** Initialise une cellule contenant un levier
* Les valeurs données seront arbitraires dans un premier temps ; 
	en pratique, chaque levier devra se référer à un piège donné
* On pourra loop dans la fonction pour chercher un piège, ou avoir un tableau de tous les pièges initialisé à la création de la map dans lequel chaque levier pourra trouver son piège 
* Un levier a en attributs les coordonnées du début du piège et son état ; quand le levier est désactivé, le piège l'est aussi 
* On devra utiliser une fonction pour générer un piège de ses coordo de départ (x,y) à ses coordo d'arrivée (x', y') ; on pourra en réemployer une variante ici.
*/
void init_cell_levier(cell_t* cell) {
	cell->id=levier;
	cell->type->levier=malloc(sizeof(levier_t));
	cell->type->levier->xpiege=15;
	cell->type->levier->ypiege=51;
	cell->type->levier->statut=active;
}



/** modifie le type d'une cellule selon une id et une structure adéquate (id=arme, struct arme_s, typiquement)
* Si on veut simplement modifier les valeurs de la structure au sein de la cellule sans en changer le type, il suffit de reprendre l'id qu'elle avait au départ 
Exemple : change_cell(cell[i][j], cell[i][j]->id, [structure de remplacement]) */ 

void change_cell(cell_t* cell, int old_id, const int new_id, void* const struc) {
	
	free_cell_type(cell, old_id);
	
	
	cell->id=new_id;

	switch(new_id) {
	case clef: cell->type->clef=struc; break;
	case levier: cell->type->levier=struc; break;
	case arme: cell->type->arme=struc; break;
	case tresor: cell->type->tresor=struc; break;
	case piege: cell->type->piege=struc; break;
	default: cell->type->cell_defaut=-1; break;	
	}

}

void detruire_cell(cell_t *cell) {
	free_cell_type(cell, cell->id);
	free(cell->type);
	free(cell);
}
	

// Démonstration dans test_cell.c

