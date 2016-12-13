#include "avion.h"


void avion(int tabLongLarg[])

int iDirectionAvion = 0;

int x; int y; //entiers qui seront utilisés pour attribuer et modifier les coordonées de l'affichage de l'avion

image myImage = loadImg(iDirection + 10); //On initialise la variable myImage qui correspond à la structure de l'image

iDirectionAvion = (genRandom() % 4) + 1;

struct winsize wiTailleEcran; // On créer une variable de type winsize, qui permet de récupérer les valeurs de taille de la console
getSize(&wiTailleEcran); // On appelle la fonction qui récupère la taille totale de la console
int iSizeTermx = wiTailleEcran.col; // Et on y affecte les bonnes valeurs
int iSizeTermy = wiTailleEcran.row;
int iSizeTermMax = 0;

if (tabLongLarg[0] > iSizeTermx)     //On regarde si la position random ne met pas l'avion hors du tableau dans la position de la longueur
    talLongLarg[0] = iSizeTermx - 6; //Si c'est le cas, on le décale

if (tabLongLarg[1] > iSizeTermy)     //On regarde si la position random ne met pas l'avion hors du tableau dans la position de la largeur
    tabLongLarg[1] = iSizeTermy - 6; //Si c'est le cas, on le décale

if (iSizeTermx > iSizeTermy) // On met dans une variable la valeur maximale des deux pour avoir un buffer assez grand dans la fonction "tourDuMonde".
{
    iSizeTermMax = iSizeTermx;
}else{
    iSizeTermMax = iSizeTermy;
}

x = tabLongLarg[0]; //On affecte la longueur et la largeur à des variables, plus simple à modifier par la suite.
y = tabLongLarg[1];

int iCoordAvion; //On déclare le tableau qui nous servira de repère

iCoordAvion[x][y]; // On lui attribue les valeurs de l'emplace de l'avion

afficher(loadImg(iDirectionAvion + 10),x,y,iSizeTermy)

while (GetKeyboardInput(0) != 5) //x sera l'entier choisit pour détecter la touche entrée, on regarde si l'utilisateur n'appuie pas sur entrée, ce qui ferait quitter le programme
{                   //On envoie la valeur 0 à getKeyboardInput pour lui informer qu'on est sur l'application de l'avion.
    if(GetKeyboardInput(0) = 1) //x est l'entier pour définir la flèche du haut, qui permet donc d'orienter l'avion vers le haut
        {
        afficherImage(loadImg(11),x,y,iSizeTermy); //On affiche alors l'image de l'avion qui est orienté au Nord
        iDirectionAvion = 1;
        myImage = loadImg(iDirection + 10)
    }else if(GetKeyboardInput(0) = 2)//x est l'entier pour définir la flèche de droite, qui permet donc d'orienter l'avion vers la droite
            {
                afficherImage(loadImg(12),x,y,iSizeTermy);//On affiche alors l'avion qui est orienté à l'Est
                iDirectionAvion = 2;
                myImage = loadImg(iDirection + 10)
    }else if(GetKeyboardInput(0) = 3)//x est l'entier pour définir la flèche du bas, qui permet donc d'orienter l'avion vers le bas
            {
                afficherImage(loadImg(13),x,y,iSizeTermy);// On affiche alors l'avion qui est orienté vers le Sud
                iDirectionAvion = 3;
                myImage = loadImg(iDirection + 10)
    }else if(GetKeyboardInput(0)) = 4)//x est l'entier pour définir la flèche de gauche, qui permet donc d'orienter l'avion vers la gauche
            {
                afficherImage(loadImg(14),x,y,iSizeTermy);//On affiche alors l'avion qui est orienté vers l'Ouest
                iDirectionAvion = 4;
                myImage = loadImg(iDirection + 10)
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
        if (x < 6 || x > iSizeTermx - 6)
        {
            tourDuMonde(iDirection, iSizeTermx, iSizeTermy, iSizeTermMax, myImage.tableau);
        }else if (y < 6 || y > iSizeTermy - 6)
        {
            tourDuMonde(iDirection, iSizeTermx, iSizeTermy, iSizeTermMax, myImage.tableau);
        }
        afficher(myImage,x,y,iSizeTermy);

}


void tourDuMonde(int iDirection, int iLongueur, int iLargeur, int iSizeMax, int** tableau) //envoyer image.tableau
{
    int iBuffer[iSizeMax];
    int i = 0; int j = 0;


    switch (iDirection)

    case 1 :
        for (; i<iLongueur; i++)
        {
            iBuffer[i] = tableau[i][0];
        }
        i = 0;
        for(;j<iLargeur;j++)
        {
            for (;i<iLongueur;i++)
            {
                tableau[i][j] = tableau[i][j-1];
            }
            i=0;
        }
        i = 0; j = 0;
        for (;i<iLongueur; i++)
        {
            tableau[i][iLargeur] = iBuffer[i];
        }

    case 2 :
        for (;j<iLargeur;j++)
        {
            iBuffer[j] = tableau[iLongueur][j];
        }
        j=0;i=iLongueur;
        for (;i>0;i--)
        {
            for(;j<iLargeur;j++)
            {
                tableau[i][j] = tableau[i-1][j];
            }
            j = 0;
        }j=0;
        for (;j<iLargeur;i++)
        {
            tableau[0][j] = iBuffer[j];
        }

    case 3 :
        for (; i<iLongueur; i++)
        {
            iBuffer[i] = tableau[i][iLargeur];
        }
        i = 0;j=iLargeur;
        for(;j<0;j--)
        {
            for (;i<iLongueur;i++)
            {
                tableau[i][j] = tableau[i][j-1];
            }
            i=0;
        }
        i = 0; j = 0;
        for (;i<iLongueur; i++)
        {
            tableau[i][0] = iBuffer[i];
        }
    case 4 :
        for (;j<iLargeur;j++)
        {
            iBuffer[j] = tableau[0][j];
        }
        j=0;i=0;
        for (;i<iLongueur-1;i++)
        {
            for(;j<iLargeur;j++)
            {
                tableau[i][j] = tableau[i+1][j];
            }
            j = 0;
        }j=0;
        for (;j>0;i++)
        {
            tableau[iLongueur][j] = iBuffer[j];
        }

    default :
                printf("Erreur de gestion de mouvement de l'avion.\n");
                exit(EXIT_FAILURE);
                break;

}
