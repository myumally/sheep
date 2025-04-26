#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "graphe.h"
#include "const.h"


struct boite* creaboite(){
    struct boite* b=malloc(sizeof(struct boite));
    return b;
}

struct reponse* creareponse(){
    struct reponse* r=malloc(sizeof(struct reponse));
    return r;
}

int stockage (FILE* f, struct boite*** ptgraphe){

    *ptgraphe=(struct boite**)malloc(sizeof(struct boite*)*NOMBRE_MAX_DE_BOITE_DE_DIALOGUE);
    int c=0;
    char* chaine=(char*)malloc(sizeof(char)*9);
    char* rien=(char*)malloc(sizeof(char)*9);
    char* next=(char*)malloc(sizeof(char)*5);
    fgets(chaine,9,f);

    while(strcmp(chaine,"..fin\n")){

        struct boite* b=creaboite();
        b->nbrep=fgetc(f);
        b->nbrep-=48;
        //printf("nbrep=%d\n",b->nbrep);
        b->diag=(char*) malloc(sizeof(char)*NOMBRE_MAX_DE_CARACTERE_PAR_BOITE_DE_DIALOGUE);
        fgets(b->diag,9,f); //pour s'occuper du \n
        fgets(b->diag,NOMBRE_MAX_DE_CARACTERE_PAR_BOITE_DE_DIALOGUE,f);
        //printf("diag=%s",b->diag);
        b->rep=(struct reponse**)malloc(sizeof(struct reponse*)*NOMBRE_MAX_DE_REPONSE_POSSIBLE);

        for (int i=0;i<b->nbrep;i++){

            struct reponse* r=creareponse();

            fgets(next,5,f);
            //printf("chainenext=%s\n",next);
            r->next=atoi(next);
            //printf("next=%d\n",r->next);
            
            r->text=(char*) malloc(sizeof(char)*NOMBRE_MAX_DE_CARACTERE_PAR_REPONSE);
            fgets(r->text,NOMBRE_MAX_DE_CARACTERE_PAR_REPONSE,f);
            //printf("text=%s",r->text);

            *((b->rep)+i)=r;
        }
        *((*ptgraphe)+c)=b;
        //printf("graphe diag=%s",(*(graphe+c))->diag);
        c+=1;
        fgets(rien,9,f);
        fgets(chaine,9,f);
        //printf("%s",chaine);
    }
    free(chaine);
    free(rien);
    free(next);
    return c;
}


void freerep(struct reponse* r){
    free(r->text);
    free(r);
}

void freeboite(struct boite* b){
    free(b->diag);
    for (int i=0;i<b->nbrep;i++){
        freerep(*((b->rep)+i));
    } 
    free(b->rep);
    free(b);
}

void destockage(int c, struct boite** graphe){
    for (int i=0;i<c;i++){
        freeboite(*(graphe+i));
    }
    free(graphe);
}
