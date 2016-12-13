#include <stdio.h>
#include <stdlib.h>
#include "fonctionsCommunes.h"
#include "lanceur.h"
#include "statique.h"
#include "heure.h"
#include "avion.h"


int main(){

    printf("%d \n",genRandom());
    //vider();
   int direction = GetKeyboardInput(0);
    printf("%d",direction);
  //  GetKeyboardInput(1);
    return 0;
}
