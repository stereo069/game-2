#pragma once
#include "SDL.h"
#include "box.h"
#include <iostream>
#include <string>


class map
{
private:
	box element[3][3]; // ���� ��������
	bool done = true; // ���� true ��� ����
	SDL_Event event; // ���������� �������
	SDL_Window *window = nullptr;
	SDL_Renderer *renderer = nullptr;
	void ApplySurface(int x, int y, SDL_Texture *tex, SDL_Renderer *rend);
	SDL_Texture* LoadImage(SDL_Surface *);
	SDL_Texture *background;
	bool checkWinner(); // �������� �� ����������
	void freeres();
public:
	bool game(); // ������� ������� ���� 
	void InitMap(); // �������� ��������� �����

};

