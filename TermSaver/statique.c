#include "statique.h"
//includes de la compil





//début de la vrai fonction
void statique( int imageAlancer){

winsize taille; //décalre la struct pour récupérer la taille de l'image
getSize(&taille); //on récupère la taille de l'image dans la struct

image myImage =loadImg(imageAlancer);
//printf("taille :%d",myImage.hauteur);

//on affiche l'image demandé et on la centre

afficher(loadImg(imageAlancer),(taille.ws_col-myImage.largeur)/2,(taille.ws_row-myImage.hauteur)/2,taille.ws_row);

//
GetKeyboardInput(1);

}


