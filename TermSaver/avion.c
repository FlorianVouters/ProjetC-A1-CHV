#include <stdio.h>
#include <stdlib.h>
#include "avion.h"

#include "fonctionsCommunes.h"


void avion(int tabLongLarg[])

int iDirectionAvion;

int x; int y; //entiers qui seront utilisés pour attribuer et modifier les coordonées de l'affichage de l'avion



iDirectionAvion = (genRandom() % 4) + 1;

int sizeTerm[2]; // On créer un tableau qui aura la valeur de la fenêtre longueur et largeur

sizeTerm = getSizeTerm;

if (tabLongLarg[0] > itSizeTerm[0])     //On regarde si la position random ne met pas l'avion hors du tableau dans la position de la longueur
    talLongLarg[0] = itSizeTerm[0] - 6; //Si c'est le cas, on le décale

if (tabLongLarg[1] > itSizeTerm[1])     //On regarde si la position random ne met pas l'avion hors du tableau dans la position de la largeur
    tabLongLarg[1] = itSizeTerm[1] - 6; //Si c'est le cas, on le décale

x = tabLongLarg[0]; //On affecte la longueur et la largeur à des variables, plus simple à modifier par la suite.
y = tabLongLarg[1];

int iCoordAvion

iCoordAvion[x][y];

while (GetKeyboardInput(0) != 5) //x sera l'entier choisit pour détecter la touche entrée, on regarde si l'utilisateur n'appuie pas sur entrée, ce qui ferait quitter le programme
{                   //On envoie la valeur 0 à getKeyboardInput pour lui informer qu'on est sur l'application de l'avion.
    if(GetKeyboardInput(0) = 1) //x est l'entier pour définir la flèche du haut, qui permet donc d'orienter l'avion vers le haut
        {
        afficherImage(loadImg(11)); //On affiche alors l'image de l'avion qui est orienté au Nord
        iDirectionAvion = 1;
    }else if(GetKeyboardInput(0) = 2)//x est l'entier pour définir la flèche de droite, qui permet donc d'orienter l'avion vers la droite
            {
                afficherImage(loadImg(12));//On affiche alors l'avion qui est orienté à l'Est
                iDirectionAvion = 2;
    }else if(GetKeyboardInput(0) = 3)//x est l'entier pour définir la flèche du bas, qui permet donc d'orienter l'avion vers le bas
            {
                afficherImage(loadImg(13));// On affiche alors l'avion qui est orienté vers le Sud
                iDirectionAvion = 3;
    }else if(GetKeyboardInput(0)) = 4)//x est l'entier pour définir la flèche de gauche, qui permet donc d'orienter l'avion vers la gauche
            {
                afficherImage(loadImg(14));//On affiche alors l'avion qui est orienté vers l'Ouest
                iDirectionAvion = 4;
    }else{
            switch (iDirectionAvion)

            case 1 :
                    y++;
                    break;
            case 2 :
                    x++;
                    break;
            case 3 :
                    y--;
                    break;
            case 4 :
                    x--;
                    break;
            default :
                        printf("Erreur d'orientation de l'avion.\n");
                        exit(EXIT_FAILURE);
                        break;
    }



}
