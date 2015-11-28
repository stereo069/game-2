#pragma once
#include "SDL.h"
#include "box.h"
#include <iostream>
#include <string>


class map
{
private:
	box element[3][3]; // наши квадраты
	bool done = true; // пока true идёт игра
	SDL_Event event; // обработчик событий
	SDL_Window *window = nullptr;
	SDL_Renderer *renderer = nullptr;
	void ApplySurface(int x, int y, SDL_Texture *tex, SDL_Renderer *rend);
	SDL_Texture* LoadImage(SDL_Surface *);
	SDL_Texture *background;
	bool checkWinner(); // проверка на победителя
	void freeres();
public:
	bool game(); // главная функция игры 
	void InitMap(); // создание начальной карты

};

