#pragma once
#include "SDL.h"
class box
{
public :
	void Newstatus(int st); // меняем текстуру
	int Getstatus(); // выводим статус объекта
	SDL_Surface *gettexture()
	{
		return texture;
	}
	void settexture(int st);
	void setwinner();
	void freeres();
private:
	SDL_Surface *texture;
	SDL_Surface *cross;
	SDL_Surface *round;
	SDL_Surface *roundwin;
	SDL_Surface *crosswin;
	int status; // 0=empty ; 2=cross ; 1=round
	public:
	box()
	{
		texture = SDL_LoadBMP("empty/empty.bmp");
		if (texture == nullptr){
			return;
		}
		cross = SDL_LoadBMP("cross/cross.bmp");
		if (cross == nullptr){
			return;
		}
		round = SDL_LoadBMP("round/round.bmp");
		if (round == nullptr){
			return;
		}
		roundwin = SDL_LoadBMP("round/roundwin.bmp");
		if (round == nullptr){
			return;
		}
		crosswin = SDL_LoadBMP("cross/crosswin.bmp");
		if (round == nullptr){
			return;
		}
		status = 0;
	
	}

};

