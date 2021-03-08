a:
	gcc main.c  -I/usr/include  -L/usr/lib/x86_64-linux-gnu -lSDL  -o jeu
z:
	gcc jeu.c  -I /usr/include/SDL2 -L /usr/lib/x86_64-linux-gnu -l SDL2  -o exec
x:
	gcc main.c Menu.c Load_Images.c Playmenu.c option.c -o jeu `pkg-config --cflags --libs SDL_image SDL_ttf SDL_mixer ` 

