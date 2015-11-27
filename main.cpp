#include "SDL.h"
#include <iostream>
#include <conio.h>
//#undef main

int main(int argc, char* argv[])
{

	SDL_Window *win = SDL_CreateWindow("CROSS AND ROUND", 100, 100, 480, 480, NULL);
	if (win == nullptr){
		std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
		return 1;
	}
	SDL_Renderer *ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (ren == nullptr){
		std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
		return 1;
	}
	SDL_Surface *bmp = SDL_LoadBMP("blue.bmp");
	if (bmp == nullptr){
		std::cout << "SDL_LoadBMP Error: " << SDL_GetError() << std::endl;
		return 1;
	}
	SDL_Texture *tex = SDL_CreateTextureFromSurface(ren, bmp);
	SDL_FreeSurface(bmp);
	if (tex == nullptr){
		std::cout << "SDL_CreateTextureFromSurface Error: " << SDL_GetError() << std::endl;
		return 1;
	}
	bool done=false;
	SDL_Event event;
	while (!done)
	{
		(SDL_PollEvent(&event)); // Пока есть хоть одно необработанное событие
		
				SDL_RenderClear(ren);
				SDL_RenderCopy(ren, tex, NULL, NULL);
				SDL_RenderPresent(ren);
				SDL_Delay(100);

			


				switch (event.type)
				{
				case SDL_MOUSEBUTTONDOWN:
				{
					if (event.button.button = SDL_BUTTON_LEFT)
					{
						int x = event.button.x, y = event.button.y; // Координаты клика
						if (x > 100)
							done = true;
					}
					break;
				}
				case SDL_QUIT: // Событие выхода
					done = true;
				}
		}

	SDL_DestroyTexture(tex);
	SDL_DestroyRenderer(ren);
	SDL_DestroyWindow(win);

	return 0;
}