#include "map.h"


SDL_Texture* map::LoadImage(SDL_Surface *image){
	SDL_Texture *texture = nullptr;
	if (image != nullptr){

		texture = SDL_CreateTextureFromSurface(renderer, image);
		SDL_FreeSurface(image);
	}
	else
		std::cout << SDL_GetError() << std::endl;
	return texture;
}
void map::ApplySurface(int x, int y, SDL_Texture *tex, SDL_Renderer *rend){
	SDL_Rect pos;
	pos.x = x;
	pos.y = y;
	SDL_QueryTexture(tex, NULL, NULL, &pos.w, &pos.h);
	SDL_RenderCopy(rend, tex, NULL, &pos);
}


void map::InitMap()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0){
		std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
		return ;
	}

	window = SDL_CreateWindow("CROSS AND ROUND", SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED, 600, 600, SDL_WINDOW_SHOWN);
	if (window == nullptr){
		std::cout << SDL_GetError() << std::endl;
		return ;
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED
		| SDL_RENDERER_PRESENTVSYNC);
	if (renderer == nullptr){
		std::cout << SDL_GetError() << std::endl;
		return ;
	}

	SDL_Surface *temp = SDL_LoadBMP("empty/empty.bmp");
	background = SDL_CreateTextureFromSurface(renderer, temp);
	SDL_FreeSurface(temp);
	//image = LoadImage("Lesson2res/image.bmp");
	if (background == nullptr)
		return ;

	SDL_RenderClear(renderer);

	int bW, bH;
	SDL_QueryTexture(background, NULL, NULL, &bW, &bH);
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++)
		{
			ApplySurface(i*bW, j*bH, LoadImage(element[i][j].gettexture()), renderer);
		}
	
	}
	return;

}


bool map::game()
{
	InitMap();
	bool done = true;
	bool done2 = true;
	int n = 0;
	SDL_Event event;
	int q = 1;
	int bW, bH;
	SDL_QueryTexture(background, NULL, NULL, &bW, &bH);
	while (done)
	{
		SDL_RenderPresent(renderer);
		SDL_Delay(30);
		SDL_WaitEvent(&event);

		switch(event.type)
		{
		case SDL_MOUSEBUTTONDOWN:
		{
			if (done2)  // чтобы после победы события мыши не обрабатывались
			{
				if (event.button.button = SDL_BUTTON_LEFT)
				{
					int x = event.button.x / 200, y = event.button.y / 200; // Координаты клика
					if (!element[x][y].Getstatus())
					{
						n++;
						element[x][y].settexture(q);
						q *= -1;
						ApplySurface(x*bW, y*bH, LoadImage(element[x][y].gettexture()), renderer);
						if (checkWinner() || n==9)
						{
							done2 = false;  // чтобы после победы события мыши не обрабатывались 
						}
					}

				}


			}
			else{
				SDL_DestroyTexture(background);
				SDL_DestroyRenderer(renderer);
				SDL_DestroyWindow(window);
				SDL_Quit();
				return 1;
			
			}
			break;
		}
            case SDL_QUIT: // Событие выхода
				done = false;
		}


	}
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			element[i][j].freeres();
		}

	}
	SDL_DestroyTexture(background);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return false;

}

bool map::checkWinner() // проверка на победителя
{ 
	for (int i = 0; i < 3; i++)
	{
		if ((element[0][i].Getstatus() == element[1][i].Getstatus()) &&
			(element[1][i].Getstatus() == element[2][i].Getstatus()) && (element[0][i].Getstatus() != 0))
		{
				
			for (int k = 0; k < 3; k++)
			{
				element[k][i].setwinner();
				ApplySurface(k*200, i*200, LoadImage(element[k][i].gettexture()), renderer);
	
			}
			return 1;
		}
		if ((element[i][0].Getstatus() == element[i][1].Getstatus()) &&
			(element[i][1].Getstatus() == element[i][2].Getstatus()) && (element[i][0].Getstatus() != 0))
		{
			for (int k = 0; k < 3; k++)
			{
				element[i][k].setwinner();
				ApplySurface(i * 200, k * 200, LoadImage(element[i][k].gettexture()), renderer);
			}
			return 1;
		}
	}
	
	// диагонали
	if ((element[0][0].Getstatus() == element[1][1].Getstatus()) &&
		(element[1][1].Getstatus() == element[2][2].Getstatus()) && (element[0][0].Getstatus() != 0))
	{
		for (int k = 2; k >= 0; k--)
		{
			element[k][k].setwinner();
			ApplySurface(k * 200, k * 200, LoadImage(element[k][k].gettexture()), renderer);
		}
		return 1;
	}
	if ((element[0][2].Getstatus() == element[1][1].Getstatus()) &&
		(element[1][1].Getstatus() == element[2][0].Getstatus()) && (element[0][2].Getstatus() != 0))
	{
		
			element[0][2].setwinner();
			ApplySurface(0 * 200, 2 * 200, LoadImage(element[0][2].gettexture()), renderer);
			element[1][1].setwinner();
			ApplySurface(1 * 200, 1 * 200, LoadImage(element[1][1].gettexture()), renderer);
			element[2][0].setwinner();
			ApplySurface(2 * 200, 0 * 200, LoadImage(element[2][0].gettexture()), renderer);
		
		return 1;
	}
	return 0;
}



