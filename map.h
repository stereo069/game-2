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
	SDL_Surface *screen; // ����� �� �����
	SDL_Surface *lineWinner[8]; // ����� �������� �����
	box element[3][3]; // ���� ��������
	bool done = true; // ���� true ��� ����
	SDL_Event event; // ���������� �������

public:
	void game(); // ������� ������� ���� 
	void InitMap(); // �������� ��������� �����
	void checkWinner(); // �������� �� ����������
	int  getLineWinner(XY one , XY two , XY three); // ����� ����� �������� ��� ������ �������� �����
	XY getPositionEvent(int x , int y); // ������ ��� ���������� element[i][j]

	
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

