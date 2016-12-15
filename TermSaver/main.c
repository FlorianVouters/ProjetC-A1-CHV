#include <stdio.h>
#include <stdlib.h>
#include "fonctionsCommunes.h"
#include "lanceur.h"
#include "statique.h"
#include "heure.h"
#include "avion.h"


int main(int argc, char *argv[])
{


    if (argc > 1){

        if (argv[1] != NULL){

          if (strcmp(argv[1], "-stats") ==0){


                printf("lancer l'historique\n");
               }
            else{
            printf("eh ben non\n");}


        }
    }

    if (argc==1){





        vider();
        lanceur(0,0);

}

    return 0;

}

/*
void main(){



lanceur(0,0);

}
*/
