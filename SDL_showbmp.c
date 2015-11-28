#include <SDL2/SDL.h>

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

	SDL_Renderer *ren = SDL_CreateRenderer(win,-1,SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );

	if(ren == NULL)
	{
		SDL_DestroyWindow(win);
		printf("SDL Create Render failed: %s!\n",SDL_GetError());	
		SDL_Quit();
		return 1;
	}

	SDL_Surface *bmp = SDL_LoadBMP("test.bmp");
	
	if(bmp == NULL)
	{
		SDL_DestroyRenderer(ren);
		SDL_DestroyWindow(win);
		
		printf("SDL Create Surfece failed: %s!\n",SDL_GetError());
			
		SDL_Quit();
		return 1;
	}

	SDL_Texture *tex = SDL_CreateTextureFromSurface(ren,bmp);
	SDL_FreeSurface(bmp);
	
	if(tex == NULL)
	{
		SDL_DestroyRenderer(ren);
		
		SDL_DestroyWindow(win);
		
		printf("SDL Create Texture failed: %s!\n",SDL_GetError());
		SDL_Quit();
		return 1;

	}
	
	int i;
	for(i = 0; i <3; i++)
	{
		//clear the renderer
		SDL_RenderClear(ren);
		SDL_RenderCopy(ren,tex,NULL,NULL);
		SDL_RenderPresent(ren);
		SDL_Delay(1000);

	}	

	SDL_DestroyTexture(tex);
	SDL_DestroyRenderer(ren);
	SDL_DestroyWindow(win);
	SDL_Quit();

	return 0;

}

