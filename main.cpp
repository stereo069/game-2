
#include <iostream>
#include <conio.h>
#include "map.h"

//#undef main


int main(int argc, char* argv[])
{
	bool done = true;


	while (done)
	{
		map *test = new map;
		done = test->game();
		delete test;
		SDL_Delay(200);
	}
	return 0;
}