#include <sys/ioctl.h>
#include <stdio.h>
#include <stdlib.h>
#include "fonctionsCommunes.c"
#include "lanceur.c"
#include "statique.c"
#include "heure.c"
#include "avion.c"


int main(){

    printf("%d \n",genRandom());
    //vider();
   int direction = GetKeyboardInput(0);
    printf("%d",direction);
  //  GetKeyboardInput(1);
    return 0;
}
