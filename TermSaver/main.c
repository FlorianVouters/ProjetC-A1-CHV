#include <sys/ioctl.h>
#include <stdio.h>
#include <stdlib.h>
#include "lanceur.c"
#include "loadImg.c"
#include "afficherImg.c"
#include "getSizeTerm.c"
#include "getScale.c"
#include "scaling.c"
#include "getKeyboardInput.c"
#include "dynamique.c"
#include "heure.c"
#include "avion.c"


int main (void)
{
    struct winsize w;
    printf("test");
    ioctl(0, TIOCGWINSZ, &w);

    printf ("lines %d\n", w.ws_row);
    printf ("columns %d\n", w.ws_col);
    return 0;
}
