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
                        function handler(event) {
                            var result = parseInt(event.target.id,10);
                            if (typeof clearDisplay === 'function') clearDisplay();
                            wakeUp(parseInt(result));
                            document.querySelectorAll('.button').forEach(button => {
                                button.removeEventListener('click', handler);
                            });
                        }

                        document.querySelectorAll('.button').forEach((button, index) => {
                            if (index < $0) {
                                button.addEventListener('click', handler);
                            }
                        });

                        
                    });
                }, b->nbrep);

                if(rep){
                    cur=(graphe)+(*((((*cur)->rep)+(rep-1))))->next;
                    b=*(cur);
                }
            }

            destockage(c,graphe);
        }

        else{
            printf("Impossible d'ouvrir le fichier\n");
        }

        fclose(fichier);
    return 0;
}
