#ifndef GRAPHE_H
#define GRAPHE_H

#include <stdio.h>

struct boite{
    int nbrep;
    char * diag;
    struct reponse** rep;
};

struct reponse{
    char* text;
    int next;
};

struct boite* creaboite();
struct reponse* creareponse();
int stockage (FILE* f, struct boite*** ptgraphe);

void freerep(struct reponse* r);
void freeboite(struct boite* b);
void destockage(int c, struct boite** graphe);

#endif