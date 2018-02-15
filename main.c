//
//  main.c
//  roguelike
//
//  Created by Maureen Gallois on 15/02/2018.
//  Copyright © 2018 Maureen Gallois. All rights reserved.
//

#include "SDL/SDL.h"
#include "cell.h"
#include "perso.h"
#include "core.h"


int main ( int argc, char *argv[] )
{
    
    // Génère un quelconque tableau de cellules aux valeurs sans importance, et au placement aléatoire
    srand(time(NULL));
    int n=HAUTEUR_MAP/SPRITE_SIZE, m=LARGEUR_MAP/SPRITE_SIZE,k,z, clcount=0;
    cell_t *cell[n][m];
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++) {
            k=rand()%15000;
            clcount==1 ? (z=k%7+1) : (z=k%8);
            cell[i][j]=init_cell(z);
            if(cell[i][j]->id==clef && clcount < 1)
                clcount++;
        }
    // réattribution d'une valeur à fin de test : on veut un mur, la structure passée en paramètre n'a donc aucune importance
    change_cell(cell[0][15], cell[0][15]->id, mur, cell[0][15]->type);
    
    
    
    SDL_Surface *fenetre, *temp, *sprite, *surface;
    SDL_Rect perso, rcGrass;
    SDL_Event event;
    Uint8 *keystate;
    
    int colorkey, gameover;
    
    SDL_Init(SDL_INIT_EVERYTHING);
    
    // pose le titre de la fenêtre
    SDL_WM_SetCaption("SDL test", "SDL test");
    
    // crée la fenêtre
    fenetre = SDL_SetVideoMode(LARGEUR_MAP, HAUTEUR_MAP, 0, 0);
    
    // charge le sprite
    temp   = SDL_LoadBMP("sprites/sprite.bmp");
    sprite = SDL_DisplayFormat(temp);
    SDL_FreeSurface(temp);
    
    /* pose un code couleur : pur violet = transparent ; permet de rendre le contour du sprite transparent
     par ailleurs, encode grass.bmp selon l'algorithme RLE pour en diminuer le poids */
    colorkey = SDL_MapRGB(fenetre->format, 255, 0, 255);
    SDL_SetColorKey(sprite, SDL_SRCCOLORKEY | SDL_RLEACCEL, colorkey);
    
    // charge la surface
    temp  = SDL_LoadBMP("sprites/grass.bmp");
    surface = SDL_DisplayFormat(temp);
    SDL_FreeSurface(temp);
    
    // positionne le sprite à l'origine, en haut à gauche
    perso.x = 0;
    perso.y = 0;
    
    gameover = 0;
    
    
    while (!gameover)
    {
        // lancement de la recherche d'events
        if (SDL_PollEvent(&event)) {
            switch (event.type) { // implique qu'il y a eu un event
                    // SDL_QUIT : fermer la fenêtre, par Alt+F4 ou en cliquant sur la croix
                case SDL_QUIT:
                    gameover = 1;
                    break;
                    
                    // gestion simpliste du clavier : Q ou Echap = on quitte
                case SDL_KEYDOWN:
                    switch (event.key.keysym.sym) {
                        case SDLK_ESCAPE:
                        case SDLK_q:
                            gameover = 1;
                            break;
                        default:break;
                    }
                default:break;
            }
        }
        
        // gestion du mouvement du sprite / input de l'utilisateur
        keystate = SDL_GetKeyState(NULL);
        if (keystate[SDLK_LEFT] ) {
            perso.x -= VITESSE;
        }
        if (keystate[SDLK_RIGHT] ) {
            perso.x += VITESSE;
        }
        if (keystate[SDLK_UP] ) {
            perso.y -= VITESSE;
        }
        if (keystate[SDLK_DOWN] ) {
            perso.y += VITESSE;
        }
        // gère la collision avec les bords de la fenêtre
        if ( perso.x < 0 ) {
            perso.x = 0;
        }
        else if ( perso.x > LARGEUR_MAP-SPRITE_SIZE ) {
            perso.x = LARGEUR_MAP-SPRITE_SIZE;
        }
        if ( perso.y < 0 ) {
            perso.y = 0;
        }
        else if ( perso.y > HAUTEUR_MAP-SPRITE_SIZE ) {
            perso.y = HAUTEUR_MAP-SPRITE_SIZE;
        }
        
        if(cell[perso.y/SPRITE_SIZE][perso.x/SPRITE_SIZE]->id==mur) {
            perso.x-=SPRITE_SIZE;
            perso.y-=SPRITE_SIZE;
        }
        
        
        // dessine la surface (ici, grass.bmp ; typiquement, tirée d'un tileset)
        for (int x = 0; x < LARGEUR_MAP / SPRITE_SIZE; x++) {
            for (int y = 0; y < HAUTEUR_MAP / SPRITE_SIZE; y++) {
                rcGrass.x = x * SPRITE_SIZE;
                rcGrass.y = y * SPRITE_SIZE;
                SDL_BlitSurface(surface, NULL, fenetre, &rcGrass);
            }
        }
        // affiche le sprite
        SDL_BlitSurface(sprite, NULL, fenetre, &perso);
        
        // met la fenêtre à jour à chaque déplacement
        SDL_UpdateRect(fenetre, 0, 0, 0, 0);
    }
    // nettoyage et fermeture
    SDL_FreeSurface(sprite);
    SDL_FreeSurface(surface);
    SDL_Quit();
    
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            detruire_cell(cell[i][j]);
    return 0;
}
