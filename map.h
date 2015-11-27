#pragma once
#include "SDL.h"
#include "box.h"
#include <iostream>

struct XY
{
	int x = 0;
	int y = 0;

};

class map
{
private:
	SDL_Surface *screen; // вывод на экран
	SDL_Surface *lineWinner[8]; // вывод победной линии
	box element[3][3]; // наши квадраты
	bool done = true; // пока true идёт игра
	SDL_Event event; // обработчик событий

public:
	void game(); // главная функция игры 
	void InitMap(); // создание начальной карты
	void checkWinner(); // проверка на победителя
	int  getLineWinner(XY one , XY two , XY three); // выдаёт номер текстуры для вывода победной линии
	XY getPositionEvent(int x , int y); // выдает нам координаты element[i][j]

	
	map()
	{
		char path[20];
		for (int i = 0; i < 8; i++)
		{
			path[i] = 0;
			sprintf(path, "line/line%c.bmp", (char)(i + '0'));
			lineWinner[i] = SDL_LoadBMP(path);
			lineWinner[i] = SDL_LoadBMP("empty/empty.bmp");
			if (lineWinner[i] == nullptr){
				return;
			}
		}
	
	}

	~map();
};

