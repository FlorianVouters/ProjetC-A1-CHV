#include "heure.h"

void heure (int n)
{
    int i;
    winsize tailleEcran;
    ioctl(0, TIOCGWINSZ, &tailleEcran);
    image image;
    char message[] = "Cet ecran sera actualise dans quelques secondes";
    while (1)
    {
        ioctl(0, TIOCGWINSZ, &tailleEcran);
        image = scale(fusionHeure(getTime()),2);
        afficher(image, (tailleEcran.ws_col - image.largeur) / 2, (tailleEcran.ws_row - image.hauteur) / 2 - 1,tailleEcran.ws_row);

        for (i = 0; i < (tailleEcran.ws_col - strlen(message) - n) / 2; i++)
            printf(" ");

        printf("%s", message);
        fflush(stdout);

        for (i = 0; i < n; i++)
        {
            sleep(1);
            printf(".");
            fflush(stdout);
        }
        printf("\n");
    }
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


image scale (image image1, int n)
{
    int i, j;
    int tempJ = 0;
    image myImage;
    myImage.hauteur = image1.hauteur + 2;
    myImage.largeur = image1.largeur + 1;
    mallocTableau(&myImage);

    if (n > 0)
    {
        for (j = 0; j < image1.largeur; j++)
            for (i = 0; i < image1.hauteur; i++)
            {
                if (j == floor(image1.largeur/2))
                {
                    myImage.tableau[i][j] = image1.tableau[i][j];
                    tempJ = 1;
                }
                myImage.tableau[i][j+tempJ] = image1.tableau[i][j];
            }

        //décalage de la partie supérieure du tableau
        for (j = 0; j < myImage.largeur; j++)
            myImage.tableau[myImage.hauteur-1][j] = myImage.tableau[myImage.hauteur-3][j];
         for (j = 0; j < myImage.largeur; j++)
            myImage.tableau[myImage.hauteur-2][j] = myImage.tableau[myImage.hauteur-4][j];
          for (j = 0; j < myImage.largeur; j++)
            myImage.tableau[myImage.hauteur-3][j] = myImage.tableau[myImage.hauteur-4][j];
        //décalage de la partie inférieure du tableau
        for (j = 0; j < myImage.largeur; j++)
            myImage.tableau[(myImage.hauteur+1)/2-1][j] = myImage.tableau[(myImage.hauteur+1)/2-2][j];
          for (j = 0; j < myImage.largeur; j++)
            myImage.tableau[(myImage.hauteur+1)/2-2][j] = myImage.tableau[(myImage.hauteur+1)/2-3][j];

        return scale(myImage, n-1);
    }
    return image1;
}

image fusionHeure ()
{
    tm *tempsActuel = getTime();
    //lire valeur d'environnement
    int n = 3;
    image heure = fusionImage(scale(loadImg(floor(tempsActuel->tm_hour/10)),n),scale(loadImg(tempsActuel->tm_hour%10),n));
    image minutes = fusionImage(scale(loadImg(floor(tempsActuel->tm_min/10)),n),scale(loadImg(tempsActuel->tm_min%10),n));
    image secondes = fusionImage(scale(loadImg(floor(tempsActuel->tm_sec/10)),n),scale(loadImg(tempsActuel->tm_sec%10),n));
    image heureFinale = fusionImage(fusionImage(fusionImage(heure,loadImg(10)),fusionImage(minutes,loadImg(10))),secondes);
    return heureFinale;
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
