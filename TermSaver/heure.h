#ifndef HEURE_H_INCLUDED
#define HEURE_H_INCLUDED

#include <time.h>
#include <math.h>
#include "fonctionsCommunes.h"

typedef struct tm tm;

tm *getTime ();
void heure (int n);
void copyTableau (image *myImage, image imageCopie, int posX);
image scale (image image1, int n);
image fusionImage (image image1, image image2);
image fusionHeure ();


#endif // HEURE_H_INCLUDED
