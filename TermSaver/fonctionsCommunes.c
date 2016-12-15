#include "fonctionsCommunes.h"


/*fonction simpliste vidant la console mais qu'on va réutiliser*/
void vider(){

system("clear");

}

/*Génère un random dont on utilisera le modulo pour faire des randoms sur des intervales*/
int genRandom(){

srand(time(NULL)); /*génère un "random" en utilisant le temps actuel comme seed*/
return rand(); /*renvoie notre random*/
}


/*si statique (TypeTerm=0): arrete le programme losqu'on appuye sur une touche
si avion(TypeTerm=1): retourne pour zqsd les valeurs respectives de 1,2,3,4 qui seront interpétées par le programme de l'avion

*/
int GetKeyboardInput(int TypeTerm){

/*TypeTerm est 0 si le programme lancé est l'avion*/
    if (TypeTerm==0){

        /* on déclare un tableau de caractères de 2 case, 2 cases car la dernière est réservée à la fonction fgets  et l'autre au caractère entrée*/
        char commande[2];


        /*fgets ne prendra en compte que la première touche car le tableau n'a que 2 cases et que la dernière est réservée*/
        fgets(commande,2, stdin);
        /*fgets prends en paramètre un tableau de char, la taille du tableau et un pointeur vers un fichier à lire, stdin correspond au clavier*/

         //   printf("%s\n",commande);

        char direction= commande[0];
            switch (direction){
                case 'z': case '5':
                   // printf("nord\n");
                    return 1;
                    break;

                case 's': case '2':
                //    printf("sud\n");
                    return 3;
                    break;
                case 'q': case '1':
                   // printf("ouest\n");
                    return 4;
                    break;
                case 'd': case '3':
                  //  printf("est\n");
                    return 2;
                    break;
                case 'x'
                 //   printf("exit");
                    return 5;
                default:
                 //   printf("commande inconnue");
                    return 6;

                }
    }

/*TypeTerm est 1 si le programme lancé est la statique*/
    if (TypeTerm !=0){

/*
        char c;

        while(c == NULL)
            c = getchar();
        return 12;
*/


    system("/bin/stty  raw");
    getchar();


    }

return 13;

}

void getSize (winsize *tailleEcran)
{
    ioctl(0, TIOCGWINSZ, tailleEcran);
}

//exit (-1) = erreur ouverture fichier
//exit (-2) = erreur allocation tableau
//path = nom du fichier sans l'extension
image loadImg (int path)
{
    //formatage du chemin d'accès au fichier
    char fullPath[50];
    sprintf(fullPath, "data/%d.pbm", path);
    //ouverture du fichier en mode lecture
    FILE *fichier = NULL;
    fichier = fopen(fullPath, "r");

    image myImage;
    //on teste si l'on a réussi à ouvrir le fichier
    if (fichier != NULL)
    {
        //on déplace le curseur dans le fichier
        fseek(fichier, 3, SEEK_SET);

        int i,j;
        //chaine de caractères qui va stocker temporirement le contenu du fichier
        char buffer[70];
        //tant qu'on lit quelque chose dans le fichier
        while (fgets(buffer, 70, fichier) != NULL)
        {
            //si la ligne n'est pas un commentaire
            if (buffer[0] != '#')
            {
                //strtol = fonction qui permet de convertir une chaine de caractère en entier jusqu'à un caractère non numérique
                char *end;
                myImage.largeur = strtol(buffer, &end, 10);
                myImage.hauteur = strtol(end, NULL, 10);
                break;
            }
        }

        mallocTableau(&myImage);

        i = 0;
        //lecture du fichier ligne par ligne
        while (fgets(buffer, 70, fichier) != NULL && i < myImage.hauteur)
        {
            //si la ligne n'est pas un commentaire
            if (buffer[0] != '#')
            {
                //même principe que plus haut, cette fois-ci on range les valeurs dans un tableau
                char *end;
                myImage.tableau[i][0] = strtol(buffer, &end, 10);
                for (j = 1; j < myImage.largeur; j++)
                {
                    myImage.tableau[i][j] = strtol(end, &end, 10);
                }
                i++;
            }
        }
        //on ferme le fichier
        fclose(fichier);
    }
    //si l'on n'a pas réussi à ouvrir le fichier
    else
    {
        //message d'erreur et on quitte le programme
        printf("Impossible d'ouvrir le fichier \"%s\"", fullPath);
        exit(-1);
    }
    //renvoi de la structure
    return myImage;
}

void afficher (image myImage, int posX, int posY, int nbLignes)
{
    int i, j;
    //offset par rapport au haut de la fenêtre
    for (i = 0; i < posY; i++)
    {
        printf("\n");
    }

    //affichage de l'image
    for (i = 0; i < myImage.hauteur; i++)
    {
        for (j = 0; j < posX; j++)
        {
            //offset en début de ligne
            printf(" ");
        }
        for (j = 0; j < myImage.largeur; j++)
        {
            //affichage du tableau
            switch (myImage.tableau[i][j])
            {
                case 0:
                    printf(" ");
                    break;
                case 1:
                    printf("%c", 88);
                    break;
            }
        }
        printf("\n");
    }

    i += posY;
    //affichage des lignes après l'image
    for (; i < nbLignes - 1; i++)
    {
        printf("\n");
    }
}

void mallocTableau (image *myImage)
{
    int i;
    //allocation dynamique du tableau
    myImage->tableau = malloc (myImage->hauteur * sizeof(int*));
    //test si l'allocation dynamque à réussi
    if (myImage->tableau == NULL)
        exit(-2);

    for (i = 0; i < myImage->hauteur; i++)
    {
        myImage->tableau[i] = calloc (3, myImage->largeur * sizeof(int));
        if (myImage->tableau[i] == NULL)
            exit(-2);
    }
}

void viderBuffer () {

    char c;
    while (c != '\n')
    {
        c = getchar();
    }

}
