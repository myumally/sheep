#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "orage_sheep.h"

char* fic="orage_sheep_Beta.txt";

struct boite{
    int nbrep;
    char * diag;
    struct reponse** rep;
};

struct reponse{
    char* text;
    int next;
};

struct boite** arbre=NULL;

struct boite* creaboite(){
    struct boite* b=malloc(sizeof(struct boite));
    return b;
}

struct reponse* creareponse(){
    struct reponse* r=malloc(sizeof(struct reponse));
    return r;
}

void stockage (FILE* f){
    arbre=(struct boite*)malloc(sizeof(struct boite*)*999); //WARNING
    int c=0;
    char* chaine=(char*)malloc(sizeof(char)*9);
    char* rien=(char*)malloc(sizeof(char)*9);
    fgets(chaine,9,f);

    while(strcmp(chaine,"..fin\n")!=0){

        struct boite* b=creaboite();
        b->nbrep=fgetc(f);
        b->nbrep-=48;
        printf("nbrep=%d\n",b->nbrep);
        b->diag=(char*) malloc(sizeof(char)*999);
        fgets(b->diag,9,f); //pour s'occuper du \n
        fgets(b->diag,999,f);
        printf("diag=%s",b->diag);
        b->rep=(struct reponse*)malloc(sizeof(struct reponse*)*9); //WARNING

        char* next=(char*)malloc(sizeof(char)*5);
        char* nextbis=(char*)malloc(sizeof(char)*5);;

        for (int i=0;i<b->nbrep;i++){

            struct reponse* r=creareponse();




            //TODO modif le fgetc par un fgets
            fgets(next,5,f);
            printf("chainenext=%s\n",next);
            strncpy(nextbis,next,strlen(next)-1);
            printf("chainenextbis=%s\n",nextbis);
            r->next=atoi(nextbis);

            //r->next=fgetc(f); //parfois le nombre a plusieur caracteres !!!!
            //r->next-=48;
            printf("next=%d\n",r->next);
            




            r->text=(char*) malloc(sizeof(char)*999);
            //fgets(r->text,9,f);
            fgets(r->text,999,f);
            printf("text=%s",r->text);

            *((b->rep)+i)=r;
        }
        *(arbre+c)=b;
        //printf("arbre diag=%s",(*(arbre+c))->diag);
        c+=1;
        fgets(rien,9,f);
        fgets(chaine,9,f);
        printf("%s",chaine);
    }
}

void afficherboite(struct boite * b){
    printf("%s",b->diag);
    for (int i=0;i<b->nbrep;i++){
        printf("choix %d : %s",i,(*((b->rep)+i))->text);
    }
}

//Todo : fonction pour tout free

int main (){
    FILE* fichier=NULL;
    fichier=fopen(fic, "r");
        if (fichier != NULL){
            stockage (fichier);
            struct boite** cur=arbre;
            int nnn=0;
            while (nnn!=999){
                afficherboite(*(cur));
                printf("entrer le numero de votre choix (999 pour quitter)\n");
                scanf("%d",&nnn);
                if (nnn!=999){
                    cur=arbre+(*((((*cur)->rep)+nnn)))->next;
                }
            }
        }
        else{
            // On affiche un message d'erreur si on veut
            printf("Impossible d'ouvrir le fichier");
        }
    int fclose(FILE* fic);
    return 2;
}
