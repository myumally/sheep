#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "graphe.h"
#include "const.h"

#include <emscripten.h>

struct boite** graphe=NULL; //graphe

int main (int argc, char **argv){

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

				rep = EM_ASM_INT({
					return Asyncify.handleSleep(function(wakeUp) {
						// Laisse le temps au navigateur d'afficher les textes avant la popup
						setTimeout(function() {
							const result = prompt("Votre choix ?");
							if (typeof clearDisplay === 'function') clearDisplay();
							wakeUp(parseInt(result));
						}, 50); // 50ms suffisent
					});
				});
				
				
                if(rep){
                    cur=(graphe)+(*((((*cur)->rep)+(rep-1))))->next;
                    b=*(cur);
                }
            }

            destockage(c,graphe);
        }

        else{
            // On affiche un message d'erreur si on veut
            printf("Impossible d'ouvrir le fichier\n");
        }

        int fclose(FILE* fic);
    return 0;
}