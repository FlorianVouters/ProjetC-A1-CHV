#ifndef AVION_H_INCLUDED
#define AVION_H_INCLUDED

#include "fonctionsCommunes.h"
#include <stdio.h>
#include <stdlib.h>

void avion(int tabLongLarg[]);
void tourDuMonde(int iDirection, int iLongueur, int iLargeur, int iSizeMax, int** tableau, image imTableau);
void poserTableauComplet(image imTableau, image myImage, int x, int y, int iSizeTermy);


#endif // AVION_H_INCLUDED
