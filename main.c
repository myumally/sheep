#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "graphe.h"

#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include<SDL2/SDL_ttf.h>
#include "sdl.h"

#include "const.h"

struct boite** graphe=NULL; //graphe

int main (){
    SDL_Init(SDL_INIT_EVERYTHING);
    TTF_Init();
    SDL_Window   * window=creafenetre();
    TTF_Font * font=TTF_OpenFont(FONT, 72 );
    FILE* fichier=NULL;
    fichier=fopen(NOM_DU_FICHIER, "r");
    if (fichier){
        rungraphe_sdl(fichier, &graphe, window, font);
    }
    else{
        // On affiche un message d'erreur si on veut
        printf("Impossible d'ouvrir le fichier");
    }
    int fclose(FILE* fic);
    TTF_CloseFont(font);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 2;
}
