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

int main (int argc, char **argv){

	if(argc==2){
        if(strcmp(argv[1], "sdl") == 0){

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

            fclose(fichier);

            TTF_CloseFont(font);
            SDL_DestroyWindow(window);
            SDL_Quit();
        }
    }
    

    else if (argc==1){

        FILE* fichier=NULL;
        fichier=fopen(NOM_DU_FICHIER, "r");

        if (fichier){

            int c=stockage (fichier, &graphe);
            struct boite** cur=graphe;

            struct boite* b=*(cur);
            struct reponse* r=NULL;

            int rep=1;

            while(rep){
                printf("%s",b->diag);
                for (int i=0;i<b->nbrep;i++){
                    r=*((b->rep)+(i));
                    printf("%d : %s", i+1, r->text);
                }
                scanf("%d", &rep);
                if(rep){
                    cur=(graphe)+(*((((*cur)->rep)+(rep-1))))->next;
                    b=*(cur);
                }
            }

            destockage(c,graphe);
        }

        else{
            // On affiche un message d'erreur si on veut
            printf("Impossible d'ouvrir le fichier");
        }

        fclose(fichier);
    }
    return 0;
}
