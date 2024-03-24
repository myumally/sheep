#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_video.h>
#include <stdlib.h>
#include "const.h"
#include "graphe.h"
#include "sdl.h"

SDL_Window   * creafenetre(){
	SDL_Window   * window = SDL_CreateWindow("SDL2 Programme 0.1", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_RESIZABLE); 
	if (!window){
		fprintf(stderr, "Erreur d'initialisation de la SDL : %s\n", SDL_GetError());
	}
	return window;
}

SDL_Renderer * crearenderer(SDL_Window   * window){
	SDL_Renderer *renderer;
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED );
	if (renderer == 0) {
    	fprintf(stderr, "Erreur d'initialisation de la SDL : %s\n", SDL_GetError());
	}
	return renderer;
}

SDL_Rect* crearect(int x, int y, int width, int height){
	SDL_Rect* rect=(SDL_Rect*)malloc(sizeof(SDL_Rect)); //init le rect
	rect->x = x;
	rect->y = y; //origin rect
	rect->w = width; //largeur rect
	rect->h = height; //hauteur rect
	return rect;
}

void textrect(SDL_Renderer* renderer, int COULEUR_TEXT_R, int COULEUR_TEXT_G, int COULEUR_TEXT_B, int COULEUR_TEXT_A, TTF_Font * font, SDL_Rect* rect, char* chaine){
	SDL_Color couleur = {COULEUR_TEXT_R, COULEUR_TEXT_G, COULEUR_TEXT_B, COULEUR_TEXT_A};        
	SDL_Surface * surf = TTF_RenderText_Blended(font, chaine, couleur);
	SDL_Texture * text = SDL_CreateTextureFromSurface(renderer, surf);
	SDL_RenderCopy(renderer, text, NULL, rect);
}

void afficherrep(SDL_Renderer* renderer, struct reponse * r, int i, int j, TTF_Font * font){
	SDL_Rect* rep=crearect(i*WIDTH_REP,j*HEIGHT_REP+HEIGHT_DIAG, WIDTH_REP,HEIGHT_REP);
    SDL_RenderFillRect(renderer, rep);
	textrect(renderer,COULEUR_REP_TEXT_R, COULEUR_REP_TEXT_G, COULEUR_REP_TEXT_B, COULEUR_REP_TEXT_A, font, rep, r->text);
}

void affichage(SDL_Window * window, struct boite* b, TTF_Font * font){
	SDL_Renderer * renderer=crearenderer(window);
	SDL_RenderClear(renderer);
	SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
	SDL_SetRenderDrawColor(renderer, COULEUR_DIAG_R, COULEUR_DIAG_G, COULEUR_DIAG_B, COULEUR_DIAG_A);

	SDL_Rect* diag=crearect(0,0, WIDTH_DIAG, HEIGHT_DIAG);
    SDL_RenderFillRect(renderer,diag);
	textrect(renderer, COULEUR_DIAG_TEXT_R, COULEUR_DIAG_TEXT_G, COULEUR_DIAG_TEXT_B, COULEUR_DIAG_TEXT_A, font, diag, b->diag);
	
	SDL_SetRenderDrawColor(renderer, COULEUR_REP_R, COULEUR_REP_G, COULEUR_REP_B, COULEUR_REP_A);
	for (int i=0;i<3;i++){
		for (int j=0;j<3;j++){
			if((3*i+j)<b->nbrep){
				afficherrep(renderer, *((b->rep)+(3*i+j)), i, j, font);
			}
		}
    }
    SDL_RenderPresent(renderer);
	SDL_DestroyRenderer(renderer);
}

void boucle_evenements(SDL_Event event, SDL_Window * window, struct boite** cur, struct boite*** ptgraphe, TTF_Font * font){
	int running=1;
	while (running) {
		while (SDL_PollEvent(&event)){
			switch(event.type){
				case SDL_WINDOWEVENT:
					printf("window event\n");
					switch (event.window.event){
						case SDL_WINDOWEVENT_CLOSE:  
							printf("appui sur la croix\n");	
							break;
						default:
							affichage(window,*(cur),font);
					}   
			    	break;
				case SDL_MOUSEBUTTONDOWN:
					printf("Appui :%d %d\n", event.button.x, event.button.y);
					int x=event.button.x;
					int y=event.button.y;
					int i=0;
					int j=0;
					while (i<3){
						while (j<3){
							if((3*i+j)<(*cur)->nbrep){
								if((x>i*WIDTH_REP)&&(x<i*WIDTH_REP+WIDTH_REP)){
									if((y>j*HEIGHT_REP+HEIGHT_DIAG)&&(y<j*HEIGHT_REP+HEIGHT_DIAG+HEIGHT_REP)){
										cur=(*ptgraphe)+(*((((*cur)->rep)+(3*i+j))))->next;
										affichage(window,*(cur),font);
										i=3;
										j=3;
									}
								}
							}
							j++;
						}
						i++;
    				}
					break;
				case SDL_QUIT : 
					printf("on quitte\n");    
					running = 0;
			}
		}
		SDL_Delay(1); //  delai minimal
	}
}

void rungraphe_sdl(FILE* fichier, struct boite*** ptgraphe, SDL_Window   * window, TTF_Font * font){
    int c=stockage (fichier, ptgraphe);
	SDL_Event event;
	struct boite** cur=*ptgraphe;
	boucle_evenements(event, window, cur,ptgraphe, font);
    destockage(c,*ptgraphe);
}