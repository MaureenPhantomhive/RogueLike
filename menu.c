#include <stdio.h>
#include <stdlib.h>
//#include <menu.h>


/*fonction correspondant au menu qui n'entre pas dans le jeu avec un bouton nouvelle partie, 
charger une partie et quitter le jeu*/ 

void menu_exterieur(){
	int rep;			/*Choix du joueur */
	
	do {
		printf("\n Bienvenue dans le ROGUELIKE™ \n");
		printf("\n 1. Nouvelle Partie\n");
		printf("\n 2. Charger\n");
		printf("\n 3. Quitter\n");
		
		/*lecture et vérification du choix du joueur*/
		do {
			printf(" Veuillez choisir une option entre 1 et 3 \n");
			scanf("%d", &rep);
			if(rep < 1 || rep > 3)
				printf("Qu'est-ce que vous n'avez pas compris dans : entre 1 et 3 ?? \n");
		} while(rep <1 || rep > 3);
			
			/*traitement du choix du joueur*/
		switch (rep){
			case 1 :
				printf("de"); /*partie_dispo();*/ break;
			case 2 : 
				printf("Fonction à faire"); break; 
			case 3 : 
				printf("À bientôt dans ROGUELIKE™ \n!");break;
			
		}	
	}while(rep!=3);
}


/*fonction correspondant au menu qui se trouve dans le jeu et qui permet de sauvegarder la partie 
en cours et un bouton quitter la partie en cours*/

void menu_interieur(){

 	int choix;			/*choix du joueur*/
	do{
		printf("\n Menu \n");
		printf("\n 1. Sauvegarder \n");
		printf("\n 2. Quitter la partie en cours \n");
		
		/*lecture et vérification du choix de joueur*/
		do{
			printf("Que voulez-vous faire?\n");
			scanf("%d", &choix);
			if (choix <1 || choix > 2){
				printf("Veuillez recommencer \n");
			}
		}while(choix < 1 || choix > 3);
			
			switch(choix){
				case 1 :
					printf("Fonction à faire"); break;
				case 2 :
					menu_exterieur(); break;			/*lien pour retourner au menu du début*/
			}	
		}while(choix != 2);
}



int main(){
menu_interieur();
}
