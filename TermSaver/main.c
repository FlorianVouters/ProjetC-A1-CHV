#include <stdio.h>
#include <stdlib.h>
#include "fonctionsCommunes.h"
#include "statique.h"
#include "heure.h"
#include "avion.h"
#include "lanceur.h"
#include "historique.h"


int main(){

    printf("%d \n",genRandom());
    vider();
    int saverAexe=0;
    int laDeche=0;
    lanceur(laDeche, saverAexe);


    //statique(0,15);
    //heure(2);
    //GetKeyboardInput(1);
    return 0;
}
