#ifndef HEURE_H_INCLUDED
#define HEURE_H_INCLUDED

#include <time.h>
#include <math.h>

typedef struct tm tm;

void heure (int n);
tm *getTime ();
void copyTableau (image *myImage, image imageCopie, int posX);
image fusionImage (image image1, image image2);
image fusionHeure ();


#endif // HEURE_H_INCLUDED
