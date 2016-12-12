#ifndef FONCTIONSCOMMUNES_H_INCLUDED
#define FONCTIONSCOMMUNES_H_INCLUDED
#include <string.h>
#include <stdio.h>

void afficherImg(int **tableau, int posX, int posY, int nbLignes);
//void vider(); /*fonction simpliste vidant la console mais qu'on va réutiliser*/
//int genRandom();/*Génère un random dont on utilisera le modulo pour faire des randoms sur des intervales*/
int ** loadImg(char* path);



#endif // FONCTIONSCOMMUNES_H_INCLUDED
