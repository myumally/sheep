#ifndef SDL_H
#define SDL_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_ttf.h>

SDL_Window   * creafenetre();
SDL_Renderer * crearenderer(SDL_Window   * window);
SDL_Rect* crearect(int x, int y, int width, int height);

void textrect(SDL_Renderer* renderer, int COULEUR_TEXT_R, int COULEUR_TEXT_G, int COULEUR_TEXT_B, int COULEUR_TEXT_A, TTF_Font * font, SDL_Rect* rect, char* chaine);
void afficherrep(SDL_Renderer* renderer, struct reponse * r, int i, int j, TTF_Font * font);
void affichage(SDL_Window * window, struct boite* b, TTF_Font * font);
void boucle_evenements(SDL_Event event, SDL_Window   * window, struct boite** cur,struct boite*** ptgraphe, TTF_Font * font);
void rungraphe_sdl(FILE* fichier, struct boite*** ptgraphe, SDL_Window   * window, TTF_Font * font);

#endif