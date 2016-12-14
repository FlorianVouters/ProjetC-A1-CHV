#include "avion.h"
#include "fonctionsCommunes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/ioctl.h>



void avion(int tabLongLarg[])
{


int x; int y; //entiers qui seront utilisés pour attribuer et modifier les coordonées de l'affichage de l'avion

int iDirectionAvion; int iEntreeClavier;

image myImage; //On initialise la variable myImage qui correspond à la structure de l'image


iDirectionAvion = (genRandom() % 4) + 1;

myImage = loadImg(iDirectionAvion + 10);


struct winsize wiTailleEcran; // On créer une variable de type winsize, qui permet de récupérer les valeurs de taille de la console
getSize(&wiTailleEcran); // On appelle la fonction qui récupère la taille totale de la console
int iSizeTermx = wiTailleEcran.ws_col; // Et on y affecte les bonnes valeurs
int iSizeTermy = wiTailleEcran.ws_row;
int iSizeTermMax;

if (tabLongLarg[0] > iSizeTermx)     //On regarde si la position random ne met pas l'avion hors du tableau dans la position de la longueur
    tabLongLarg[0] = iSizeTermx - 6; //Si c'est le cas, on le décale

if (tabLongLarg[1] > iSizeTermy)     //On regarde si la position random ne met pas l'avion hors du tableau dans la position de la largeur
    tabLongLarg[1] = iSizeTermy - 6; //Si c'est le cas, on le décale

if (iSizeTermx > iSizeTermy) // On met dans une variable la valeur maximale des deux pour avoir un buffer assez grand dans la fonction "tourDuMonde".
{
    iSizeTermMax = iSizeTermx;
}else{
    iSizeTermMax = iSizeTermy;
}

//x = tabLongLarg[0]; //On affecte la longueur et la largeur à des variables, plus simple à modifier par la suite.
//y = tabLongLarg[1];

x=45;y=15;

    image imTableau;
    imTableau.hauteur = iSizeTermy;
    imTableau.largeur = iSizeTermx;
    mallocTableau(&imTableau);

    int i = x; int j = y; int k = 0; int m = 0;
    for (;j<x+6;j++)
    {
        for(;i<y+6;i++)
        {
           imTableau.tableau[j][i] = myImage.tableau[m][k];
           k++;
        } m++; k=0;
    }m = 0;

int iCoordAvion[iSizeTermx][iSizeTermy]; //On déclare le tableau qui nous servira de repère

iCoordAvion[x][y] = 1; // On lui attribue les valeurs de l'emplace de l'avion
afficher(loadImg(iDirectionAvion + 10),x,y,iSizeTermy);

do//x sera l'entier choisit pour détecter la touche entrée, on regarde si l'utilisateur n'appuie pas sur entrée, ce qui ferait quitter le programme
{                   //On envoie la valeur 0 à getKeyboardInput pour lui informer qu'on est sur l'application de l'avion.
    iEntreeClavier = GetKeyboardInput(0);


    if(iEntreeClavier == 1) //x est l'entier pour définir la flèche du haut, qui permet donc d'orienter l'avion vers le haut
        {
        //afficher(loadImg(11),x,y,iSizeTermy); //On affiche alors l'image de l'avion qui est orienté au Nord
        iDirectionAvion = 1;
        myImage = loadImg(iDirectionAvion + 10);
        printf("Je suis vers le nord\n");
    }else if(iEntreeClavier == 2)//x est l'entier pour définir la flèche de droite, qui permet donc d'orienter l'avion vers la droite
            {
                //afficher(loadImg(12),x,y,iSizeTermy);//On affiche alors l'avion qui est orienté à l'Est
                iDirectionAvion = 2;
                myImage = loadImg(iDirectionAvion + 10);
                printf("Je suis vers l'est\n");
    }else if(iEntreeClavier == 3)//x est l'entier pour définir la flèche du bas, qui permet donc d'orienter l'avion vers le bas
            {
                //afficher(loadImg(12),x,y,iSizeTermy);// On affiche alors l'avion qui est orienté vers le Sud
                iDirectionAvion = 3;
                myImage = loadImg(iDirectionAvion + 10);
                printf("Je suis vers le sud\n");
    }else if(iEntreeClavier == 4)//x est l'entier pour définir la flèche de gauche, qui permet donc d'orienter l'avion vers la gauche
            {
                //afficher(loadImg(12),x,y,iSizeTermy);//On affiche alors l'avion qui est orienté vers l'Ouest
                iDirectionAvion = 4;
                myImage = loadImg(iDirectionAvion + 10);
                printf("Je suis vers l'ouest\n");
    }else{
            switch (iDirectionAvion){

            case 1 :
                    y--;
                    break;
            case 2 :
                    x++;
                    break;
            case 3 :
                    y++;
                    break;
            case 4 :
                    x--;
                    break;
            default :
                        printf("Erreur d'orientation de l'avion.\n");
                        exit(EXIT_FAILURE);
                        break;
    }
    }   printf("Taille max : %d", iSizeTermMax);
    poserTableauComplet(imTableau, myImage, x, y, iSizeTermy);
        if (x < 0 || x > iSizeTermx - 6)
        {
            tourDuMonde(iDirectionAvion, iSizeTermx, iSizeTermy, iSizeTermMax, myImage.tableau, imTableau);
        }else if (y < 0 || y > iSizeTermy - 6)
        {
            tourDuMonde(iDirectionAvion, iSizeTermx, iSizeTermy, iSizeTermMax, myImage.tableau, imTableau);
        }else{
        //printf("%d,%d,%d et Orientation : %d", x,y,iSizeTermy, iDirectionAvion);
        afficher(myImage,x,y,iSizeTermy);
        //sleep(2);
    }


} while (iEntreeClavier != 5);
}


void tourDuMonde(int iDirection, int iLongueur, int iLargeur, int iSizeMax, int** tableau, image imTableau) //envoyer image.tableau
{
    int iBuffer[iSizeMax];

    printf("Je rentre dans le tour du monde.\n");

    int i=0; int j=0;
    printf("Bonjour\n");

    switch (iDirection)
    {
    case 1 :
        for (; i<iLongueur; i++)
        {
            iBuffer[i] = imTableau.tableau[0][i];
            //printf("Je met la première ligne dans le buffer, j'en suis à la %d case\n", i);
        }
        i = 0;
        for(;j<iLargeur-1;j++)
        {
            for (;i<iLongueur;i++)
            {
                imTableau.tableau[j][i] = imTableau.tableau[j+1][i];
                //printf("Je met la ligne suivante dans celle au dessus, j'en suis à la %d case\n", i);
            }
            i=0;
            //printf("Je change de colonne, je fais la %d colonne\n", j);
        }
        i = 0; j = 0;
        for (;i<iLongueur-1; i++)
        {
            imTableau.tableau[iLargeur-1][i] = iBuffer[i];
            //printf("Je remet le buffer dans le tableau, j'en suis à la %d case\n", i);
        }
        afficher(imTableau, 0, 0, iLargeur-1);
        break;

    /*case 2 :
        for (;j<iLargeur;j++)
        {
            iBuffer[j] = imTableau.tableau[j][iLongueur];
        }
        j=0;i=iLongueur;
        for (;i>0;i--)
        {
            for(;j<iLargeur;j++)
            {
                imTableau.tableau[i][j] = imTableau.tableau[i-1][j];
            }
            j = 0;
        }j=0;
        for (;j<iLargeur;i++)
        {
            imTableau.tableau[0][j] = iBuffer[j];
        }
        afficher(imTableau, 0, 0, iLargeur);
        break;

    case 3 :
        for (; i<iLongueur; i++)
        {
            iBuffer[i] = imTableau.tableau[i][iLargeur];
        }
        i = 0;j=iLargeur;
        for(;j<0;j--)
        {
            for (;i<iLongueur;i++)
            {
                imTableau.tableau[i][j] = imTableau.tableau[i][j-1];
            }
            i=0;
        }
        i = 0; j = 0;
        for (;i<iLongueur; i++)
        {
            imTableau.tableau[i][0] = iBuffer[i];
        }
        afficher(imTableau, 0, 0, iLargeur);
        break;

    case 4 :
        for (;j<iLargeur;j++)
        {
            iBuffer[j] = imTableau.tableau[0][j];
        }
        j=0;i=0;
        for (;i<iLongueur-1;i++)
        {
            for(;j<iLargeur;j++)
            {
                imTableau.tableau[i][j] = imTableau.tableau[i+1][j];
            }
            j = 0;
        }j=0;
        for (;j>0;i++)
        {
            imTableau.tableau[iLongueur][j] = iBuffer[j];
        }
        afficher(imTableau, 0, 0, iLargeur);
        break;*/

    default :
                printf("Erreur de gestion de mouvement de l'avion.\n");
                exit(EXIT_FAILURE);
                break;
    }

}

void poserTableauComplet(image imTableau, image myImage, int x, int y, int iSizeTermy)
{

int k = 0; int m =0; int i= x; int j = y;
        for (;j<x+6;j++)
        {
            for(;i<y+6;i++)
            {
                imTableau.tableau[i][j] = myImage.tableau[k][m];
                k++;
            } m++; k=0;
        }m = 0;

        //afficher(imTableau,0,0,iSizeTermy);
}
