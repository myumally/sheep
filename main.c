#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "graphe.h"

#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include<SDL2/SDL_ttf.h>
#include "sdl.h"

#include "const.h"

/* VARIABLES GLOBALES */

SDL_Window   * window   = NULL; // fenetre utilisee par le programme
SDL_Renderer * renderer = NULL; // moteur de rendu SDL
SDL_Texture  * logo     = NULL; // image chargee
TTF_Font     * font1    = NULL; // polices de caracteres
TTF_Font     * font2    = NULL; 

struct boite** gra=NULL; //graphe

int main (){
    SDL_Init(SDL_INIT_EVERYTHING);
    TTF_Init();
    SDL_Window   * w=creafenetre();
    TTF_Font * font1=TTF_OpenFont(FONT, 72 );
    FILE* fichier=NULL;
    fichier=fopen(NOM_DU_FICHIER, "r");
    if (fichier){
        rungraphe_sdl(fichier, &gra, w, font1);
    }
    else{
        // On affiche un message d'erreur si on veut
        printf("Impossible d'ouvrir le fichier");
    }
    int fclose(FILE* fic);
    TTF_CloseFont(font1);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 2;
}
