#include "heure.h"

void heure (int n)
{
    winsize tailleEcran;
    getSize(&tailleEcran);
    afficher(fusionHeure(getTime()), 2,2,10);
}

image fusionHeure ()
{
    tm *tempsActuel = getTime();
    image heure = fusionImage(loadImg(floor(tempsActuel->tm_hour/10)),loadImg(tempsActuel->tm_hour%10));
    image minutes = fusionImage(loadImg(floor(tempsActuel->tm_min/10)),loadImg(tempsActuel->tm_min%10));
    image secondes = fusionImage(loadImg(floor(tempsActuel->tm_sec/10)),loadImg(tempsActuel->tm_sec%10));
    image heureFinale = fusionImage(fusionImage(fusionImage(heure,loadImg(10)),fusionImage(minutes,loadImg(10))),secondes);
    return heureFinale;
}

tm *getTime()
{
    time_t ms;
    tm *temps;
    //on récupère la valeur du temps UNIX
    time(&ms);
    //formatage dans une structure
    temps = localtime(&ms);
    return temps;
}

image fusionImage (image image1, image image2)
{
    //nouvelle structure qui contiendra les deux images
    image myImage;
    //dimensions de la nouvelle structure
    myImage.largeur = image1.largeur + image2.largeur + 1;
    myImage.hauteur = image1.hauteur;
    //allocation dynamique du tableau
    mallocTableau(&myImage);
    //copie des deux images dans le tableau
    copyTableau(&myImage, image1, 0);
    copyTableau(&myImage, image2, image1.largeur + 1);
    return myImage;
}

void copyTableau (image *myImage, image imageCopie, int posX)
{
    int i, j;
    for (i = 0; i < imageCopie.hauteur; i++)
    {
        for (j = 0; j < imageCopie.largeur; j++)
        {
            //copie dans le tableau
            myImage->tableau[i][j+posX] = imageCopie.tableau[i][j];
        }
    }
}
