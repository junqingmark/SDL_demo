//gcc -o SDLblitsurface SDLblitsurface.c -lSDL2 -lSDL2_image
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
 #include <unistd.h>

int main()
{
	if(SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		printf("SDL init error: %s!\n",SDL_GetError());
		return 1;
	}

	SDL_Window *win = SDL_CreateWindow("Hello World!",100,100,640,480,SDL_WINDOW_SHOWN);

	if(win == NULL)
	{	
		printf("SDL Create Window failed: %s!\n",SDL_GetError());
		SDL_Quit();
		return 1;
	}

	SDL_Surface *jpg = IMG_Load("test.jpg");

	if(jpg == NULL)
	{
		SDL_DestroyWindow(win);
		
		printf("SDL Create Surface failed: %s!\n",SDL_GetError());
			
		SDL_Quit();
		return 1;
	}

	SDL_Surface *sur = SDL_GetWindowSurface(win);

	SDL_Rect dstrect;
	dstrect.x = 0;
	dstrect.y = 0;
	dstrect.w = 640;
	dstrect.h = 480;

	int ret = SDL_BlitSurface(jpg, NULL, sur, &dstrect);
	if (ret != 0)
	{
		printf("Fail to SDL_Blitsurface!\n");
		SDL_FreeSurface(jpg);
		SDL_DestroyWindow(win);
		return 1;
	}

	SDL_UpdateWindowSurface(win);

	sleep(5);

	return 0;
}