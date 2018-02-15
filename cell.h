#ifndef CELL_H
#define CELL_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "perso.h"


typedef enum {clef,vide,mur,porte,arme,piege,tresor,levier} type;
typedef enum {deactive,active} etat;

typedef struct cell_s cell_t;
typedef struct clef_s clef_t;
typedef struct tresor_s tresor_t;
typedef struct piege_s piege_t;
typedef struct levier_s levier_t;

struct levier_s {
	int xpiege;
	int ypiege;
	etat statut;
};
struct clef_s {
	int xporte;
	int yporte;
	etat statut;
};


struct tresor_s {
	int score;
};

struct piege_s {
	int xdebut;
	int ydebut;
	int xfin;
	int yfin;
	int degats;
};

typedef union {
	type cell_defaut;
	clef_t* clef;
	arme_t* arme;
	tresor_t* tresor;
	piege_t* piege;
	levier_t* levier;
	
} cell_type;

struct cell_s {
	type id;
	cell_type *type;
};



cell_t* init_cell(const int); 
void init_cell_arme(cell_t*);
void init_cell_tresor(cell_t*);
void init_cell_defaut(cell_t*, const int);
void init_cell_piege(cell_t*);
void init_cell_clef(cell_t*);
void init_cell_levier(cell_t*);



void change_cell(cell_t*, int, const int, void*const);
void detruire_cell(cell_t *cell);



#endif




