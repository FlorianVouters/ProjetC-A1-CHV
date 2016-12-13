#ifndef LANCEUR_H_INCLUDED
#define LANCEUR_H_INCLUDED
#include <sys/types.h>
#include "fonctionsCommunes.h"

typedef struct historique{

int time;
int SaverLance;
int ImageLance;
int TailleTerm[2];
int coordAvion[2];
int affichageHistorique;


};


#endif // LANCEUR_H_INCLUDED
