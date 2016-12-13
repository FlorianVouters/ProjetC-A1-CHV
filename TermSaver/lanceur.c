#include "lanceur.h"

void lanceur(int saverAlancer[]){


pid_t f;
f= fork();
char *valeurVarEnvironement;



printf("le fork est :%d\n",f);
switch (f){

//fils
    default:
        //exec
        switch(saverAlancer[0]){  //le segsig est ici !!!!!!!!!!

            case 1:

            printf("le fils lance statique");
            //execlp("/home/TermSaver","statique",NULL);

            break;

            case 2:
            printf("le fils lance heure");
            //execlp("/home/TermSaver","statique",NULL);

            break;

            case 3:
            printf("le fils lance avion");
           // execlp("/home/TermSaver","statique",NULL);

            break;

            default:
            break;
        }
    break;



//père
    case 0:

    vider(); //on vide la console

    int iRand=genRandom(); //on génère un nombre aléatoire qui servira pour tous les choix aléatoires qu'n devra faire

    char path[20]; //on déclare un tableau de char pour contenir le nom des variables d'environement qu'on devra lire

    char pathComplet[40]; //on déclare un tableau de char pour contenir le path complet (relatif) du fichier à lire

    FILE *fichier = NULL; //on déclare un pointer vers le fichier qui sera à lire


    switch (iRand%3+1){  //on choisi que Saver lancer à l'aide du random %3 qui renvera donc seulement 3 valeurs diffrentes

        case 1:

    //lire EXIASAVER1_PBM pour savoir le répertoire où sont les images statiques


       // sprintf(pathComplet, ".profile/%s", "EXIASAVER_PBM");
       // fichier = fopen(pathComplet, "r");
        printf("statique");
        *saverAlancer=1;
        iRand=iRand%6;
        switch(/*iRand*/0){

            case 0:
            loadImg(0);
            //afficher (image, 20, 20, winsize.ws_col);


            break;

            case 1:
            loadImg(1);


            break;

            case 2:
            loadImg(2);


            break;

            case 3:
            loadImg(3);


            break;

            case 4:
            loadImg(4);


            break;

            case 5:
            loadImg(5);
            break;
        }

        break; //break du case de lancement du statique

    case 2:



    //lire EXIASAVER2_PMB pour savoir le répertoire où sont les images de l'heure
    //lire EXIASAVER2_TAILLE pour savoir le répertoire où sont les images de l'heure
    //lire EXIASAVER2_SLEEP pour savoir le temps de refresh de l'horologe
   valeurVarEnvironement = getenv("EXIASAVER2_PMB");
saverAlancer[0]=2;



    break;

    case 3:
saverAlancer[0]=3;
    //lire EXIASAVER3_PBM pour savoir le répertoire où sont les images de l'avion

    break;






    }
    wait(1); //c'est un test, je ne sais pas si ça sert ou si ça va foutre la merde

break;


}
printf("saverAlancer = %d\n", saverAlancer[0]);
sleep(1);
}
