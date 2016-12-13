#include <stdio.h>
#include <stdlib.h>
#include "fonctionsCommunes.h"
#include "lanceur.h"
#include "statique.h"
#include "heure.h"
#include "avion.h"


int main(){

    printf("%d \n",genRandom());
    vider();
    int saverAlancer[1];
lanceur(saverAlancer[0]);
   // statique(0,1);
    //heure(2);
  //  GetKeyboardInput(1);
    return 0;
}
