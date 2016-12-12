#ifndef FONCTIONSCOMMUNES_H_INCLUDED
#define FONCTIONSCOMMUNES_H_INCLUDED
#include <string.h>
#include <stdio.h>


typedef struct image image;
struct image    {

    int **tableau;
    int largeur;
    int hauteur;
};

image loadImg(int path);
void afficher (image myImage, int posX, int posY, int nbLignes);
void mallocTableau(image *myImage);

#endif // FONCTIONSCOMMUNES_H_INCLUDED
