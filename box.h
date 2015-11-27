#pragma once
#include "SDL.h"
class box
{
public :
	void Newstatus(int st); // меняем текстуру
	int Getstatus(); // выводим статус объекта
	SDL_Rect position; // позиция 
private:
	SDL_Surface *texture;
	SDL_Surface *cross;
	SDL_Surface *round;
	int status; // 0=empty ; 1=cross ; -1=round
	public:
	box()
	{
		texture = SDL_LoadBMP("empty/empty.bmp");
		if (texture == nullptr){
			return;
		}
		cross = SDL_LoadBMP("cross/cross.bmp");
		if (texture == nullptr){
			return;
		}
		round = SDL_LoadBMP("round/round.bmp");
		if (texture == nullptr){
			return;
		}
		status = 0;
	
	}

	~box();
};

