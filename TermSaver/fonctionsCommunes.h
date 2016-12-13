#ifndef FONCTIONSCOMMUNES_H_INCLUDED
#define FONCTIONSCOMMUNES_H_INCLUDED
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <sys/ioctl.h>

typedef struct winsize winsize;
typedef struct image image;
struct image    {

    int **tableau;
    int largeur;
    int hauteur;
};

void getSize(winsize *tailleEcran);
image loadImg(int path);
void afficher (image myImage, int posX, int posY, int nbLignes);
void mallocTableau(image *myImage);


#endif // FONCTIONSCOMMUNES_H_INCLUDED
