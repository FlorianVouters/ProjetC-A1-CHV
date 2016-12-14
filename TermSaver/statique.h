#ifndef STATIQUE_H_INCLUDED
#define STATIQUE_H_INCLUDED

#include "fonctionsCommunes.h"

 /* ajout qui fait bug mais necessaire pour la compilation pour le moment

typedef struct image image;
struct image    {

    int **tableau;
    int largeur;
    int hauteur;
};

void afficher (image myImage, int posX, int posY, int nbLignes);
int GetKeyboardInput(int TypeTerm);
void mallocTableau (image *myImage);
image loadImg(int path);


 */


void statique(int TypeTerm, int imageAlancer);

#endif // STATIQUE_H_INCLUDED
