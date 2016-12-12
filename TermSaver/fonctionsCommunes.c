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
                case 'z':
                   // printf("nord\n");
                    return 1;
                    break;

                case 's':
                //    printf("sud\n");
                    return 3;
                    break;
                case 'q':
                   // printf("ouest\n");
                    return 2;
                    break;
                case 'd':
                  //  printf("est\n");
                    return 4;
                    break;
                case 'x':
                 //   printf("exit");
                    return 5;
                default:
                 //   printf("commande inconnue");
                    return 6;

                }



    }

/*TypeTerm est 1 si le programme lancé est la statique*/
    if (TypeTerm !=0){

        char c;

        while(c == NULL){
        c= getchar();
        }
        return 12;

    }

return 13;

}
