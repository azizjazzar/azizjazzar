#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "main.h"
#include "Menu.h"
#include "Load_Images.h"



int main (int argc,char **argv)
{
volume=64;
volumesword=64;
//initialisation de la fenetre
SDL_Init(SDL_INIT_EVERYTHING); //Initialisation(partie video)
ecran=SDL_SetVideoMode(1220,720,32,SDL_HWSURFACE | SDL_DOUBLEBUF );//ouverture d'une fentre 

//Load all menu images(with Loading images)
Load_Menu();
//Menu

Menu(1);

//evenement sur la fentre ouverte



Liberation_Images();//liberation des images intro+texte
SDL_Quit();//Quiter
}



