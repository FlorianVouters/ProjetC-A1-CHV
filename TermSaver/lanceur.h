#ifndef LANCEUR_H_INCLUDED
#define LANCEUR_H_INCLUDED
#include <sys/types.h>
#include "fonctionsCommunes.h"



//la merde pour la compil




//le vrai .h
typedef struct historique historique;
typedef struct pos pos;
typedef struct tm tm;

struct pos{

    int x;
    int y;
};

struct historique{

    tm heure;
    int typeEcran;
    int fichier;
    int tailleHeure;
    pos posAvion;
    historique *next;
};

void addStruct (historique historique);


#endif // LANCEUR_H_INCLUDED
