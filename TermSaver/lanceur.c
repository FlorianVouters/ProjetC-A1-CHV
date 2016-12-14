#include "lanceur.h"

void lanceur(int laDeche, int saverAexe){


pid_t f;
f= fork();
char *valeurVarEnvironement;

int saverAlancer= saverAexe;



//printf("le fork est :%d\n",f);



switch (f){

//fils
    default:
        //exec
        if(laDeche ==1){
        printf("truc a lancer %d\n", saverAlancer);



        switch(saverAlancer){

            case 1:

            printf("le fils lance statique");


            /*j'ai essayer de lancer l'image de façon propore de la manière suivante mais il semble que
        execlp() n'aime pas qu'on lui passe des Strings


        char ImageAlancer[50];
        int i=genRandom()%16+1;
        printf("%d",i);
        sprintf(ImageAlancer,"",i);
        printf(" c est facile %s\n",ImageAlancer);


        execlp("/home/TermSaver/statique","statique", ImageAlancer,NULL);



        du coupj'ai honte mais je n'ai pas plus de temps a y perdre donc en attendant: hard coding*/


           // execlp("/home/TermSaver","statique",NULL);
           int imageAcharger= genRandom()%16+1;



           switch(imageAcharger){


           case 1:
           execlp("/home/TermSaver/statique","statique", "1",NULL);
           wait(1);
           break;

           case 2:
           execlp("/home/TermSaver/statique","statique", "2",NULL);
           wait(1);
           break;

           case 3:
           execlp("/home/TermSaver/statique","statique", "3",NULL);
           wait(1);
           break;

           case 4:
           execlp("/home/TermSaver/statique","statique", "4",NULL);
           wait(1);
           break;

           case 5:
           execlp("/home/TermSaver/statique","statique", "5",NULL);
           wait(1);
           break;

           case 6:
           execlp("/home/TermSaver/statique","statique", "6",NULL);
           wait(1);
           break;

           case 7:
           execlp("/home/TermSaver/statique","statique", "7",NULL);
           wait(1);
           break;

           case 8:
           execlp("/home/TermSaver/statique","statique", "8",NULL);
           wait(1);
           break;

           case 9:
           execlp("/home/TermSaver/statique","statique", "9",NULL);
           wait(1);
           break;

           case 10:
           execlp("/home/TermSaver/statique","statique", "10",NULL);
           wait(1);
           break;

           case 11:
           execlp("/home/TermSaver/statique","statique", "11",NULL);
           wait(1);
           break;

           case 12:
           execlp("/home/TermSaver/statique","statique", "12",NULL);
           wait(1);
           break;

           case 13:
           execlp("/home/TermSaver/statique","statique", "13",NULL);
           wait(1);
           break;

           case 14:
           execlp("/home/TermSaver/statique","statique", "14",NULL);
           wait(1);
           break;

           case 15:
           execlp("/home/TermSaver/statique","statique", "15",NULL);
           wait(1);
           break;

           case 16:
           execlp("/home/TermSaver/statique","statique", "16",NULL);
           wait(1);
           break;


           default:
           break;


           }




           execlp("/home/TermSaver/statique","statique 15",NULL);

            break; //break lancement statique

            case 2:
            printf("le fils lance heure");
            //execlp("/home/TermSaver/hello","hello",NULL);


            /*meme disclamer que pour le statiue si j avais la fonctions qui ajoute la String au exec ce serait beau et propre mais en attendant....*/

            switch(imageAcharger){


           case 1:
           execlp("/home/TermSaver/heure","heure", "1",NULL);
           wait(1);
           break;

           case 2:
           execlp("/home/TermSaver/heure","heure", "2",NULL);
           wait(1);
           break;

           case 3:
           execlp("/home/TermSaver/heure","heure", "3",NULL);
           wait(1);
           break;

           case 4:
           execlp("/home/TermSaver/heure","heure", "4",NULL);
           wait(1);
           break;

           case 5:
           execlp("/home/TermSaver/heure","heure", "5",NULL);
           wait(1);
           break;

           case 6:
           execlp("/home/TermSaver/heure","heure", "6",NULL);
           wait(1);
           break;

           case 7:
           execlp("/home/TermSaver/heure","heure", "7",NULL);
           wait(1);
           break;

           case 8:
           execlp("/home/TermSaver/heure","heure", "8",NULL);
           wait(1);
           break;

           case 9:
           execlp("/home/TermSaver/heure","heure", "9",NULL);
           wait(1);
           break;

           case 10:
           execlp("/home/TermSaver/heure","heure", "10",NULL);
           wait(1);
           break;

           case 11:
           execlp("/home/TermSaver/heure","heure", "11",NULL);
           wait(1);
           break;

           case 12:
           execlp("/home/TermSaver/heure","heure", "12",NULL);
           wait(1);
           break;

           case 13:
           execlp("/home/TermSaver/heure","heure", "13",NULL);
           wait(1);
           break;

           case 14:
           execlp("/home/TermSaver/heure","heure", "14",NULL);
           wait(1);
           break;

           case 15:
           execlp("/home/TermSaver/heure","heure", "15",NULL);
           wait(1);
           break;

           default:
           execlp("/home/TermSaver/heure","heure", "1",NULL);
           break;
}
            //heure(2);
          //  execlp("/home/TermSaver","statique",NULL);

            break;//break lancement heure

            case 3:
            printf("le fils lance avion");
            execlp("/home/TermSaver/hello","hello",NULL);
          // execlp("/home/TermSaver","statique",NULL);

            break;//break lancement avion

            default:
            break;
            }
        }
    break;  //break du default



//père
    case 0:
  if(laDeche ==0){
    //vider(); //on vide la console

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

        lanceur(1,1);

        break; //break du case de lancement du statique

    case 2:

lanceur(1,2);

    //lire EXIASAVER2_PMB pour savoir le répertoire où sont les images de l'heure
    //lire EXIASAVER2_TAILLE pour savoir le répertoire où sont les images de l'heure
    //lire EXIASAVER2_SLEEP pour savoir le temps de refresh de l'horologe
    //MEMO: comparer les strings obtenues avec celle de loadImg ,si elle sot diférentes crier sur Max pour qu'il addapte sa fonction
   //valeurVarEnvironement = getenv("EXIASAVER2_PMB");


    break;



    case 3:
lanceur(1,3);
    //lire EXIASAVER3_PBM pour savoir le répertoire où sont les images de l'avion

    break;






    }
    wait(1); //c'est un test, je ne sais pas si ça sert ou si ça va foutre la merde
    } //fin du if de la dèche
    break; //break du père



}


//printf("saverAlancer = %d\n", saverAlancer);
sleep(1);
}
