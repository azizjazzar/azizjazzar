#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "main.h"
#include "Menu.h"
#include "Playmenu.h"


void Menu(int WithIntro)
{

volume=64;
	if(WithIntro)
	{	
		load=IMG_Load("images/Loadingscreens/load.png");
		SDL_BlitSurface(load,NULL,ecran,&pos);
		SDL_Flip(ecran);
		SDL_Delay(4000);
		Play_Intro();
		Play_Menu();
		
		
	}
	else
	{
		Play_Menu();
	}




}


void Liberation_Images()
{
	int i;
	for (i=0;i<339;i++){
	SDL_free(intro[i]);//libration du ram
	}
		

}
void Play_Intro()
{
SDL_Rect postexte ;
postexte.x=990;
postexte.y=600;
TTF_Font *font;
TTF_Init();
font=TTF_OpenFont("/usr/share/fonts/truetype/freefont/FreeMono.ttf", 20);
SDL_Color couleur={130,130,130};
texte=TTF_RenderText_Solid(font,"Echap pour quitter",couleur);
	int i=0,cont=1;
	pos.x=0;
	pos.y=0;
		//partie son
		Mix_Music *music ;
		Mix_Chunk *effet;
		Mix_OpenAudio(22050,MIX_DEFAULT_FORMAT,2,4096);
		music=Mix_LoadMUS("music/jeumusic.mp3");
		Mix_PlayMusic(music,0);

	while (i <=339 && cont )
	{
		i++;
		SDL_BlitSurface(intro[i],NULL,ecran,&pos);
		SDL_BlitSurface(texte,NULL,ecran,&postexte);
		SDL_Flip(ecran);
		Aller_Au_Menu(&cont);
		SDL_Delay(32);//temp d'attente entre chaque images
		
		
	}
	SDL_FreeSurface(texte);
	Liberation_Images();

		
}




void Aller_Au_Menu(int *x)
{
SDL_Event event2;

		//Aller au Menu direct en cas (echap ou click sur la croix rouge)
		SDL_PollEvent(&event2);
		if (event2.type==SDL_QUIT)
		*x=0;
		else if (event2.type==SDL_KEYDOWN)
		if (event2.key.keysym.sym==SDLK_ESCAPE)
		*x=0;

}







