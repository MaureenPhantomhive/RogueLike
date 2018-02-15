#include <stdio.h>
#include <stdlib.h>
#include <menu.h>

void (*partie_dipso)(){
	int partie;					/*choix de la partie*/
	
	do{
		printf("\n Sélectionner un monde \n");
		printf("\n Partie 1 \n");
		printf("\n Partie 2 \n");
		printf("\n Partie 3 \n");
		printf("\n Retour \n");
		
		/*Le joueur choisi une des parties */
		do{
			printf("Choix de la partie?" );
			scanf("%d", &partie);
			if (partie < 1 || partie > 4){
				printf("Partie non existante");
			}
		}while(partie < 1 || partie > 4);
		
		/*traitement du choix de la partie*/
		switch(partie) {
			case 1 :
				printf("Chatgement de la map");break;
			case 2 :
				printf("Chatgement de la map");break;
			case 3 :
				printf("Chatgement de la map");break;
			case 4 :
				menu_exterieur()  ;break;
		}
	}while(partie != 4);
	
}