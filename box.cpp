#include "box.h"

void box::settexture(int st)
{
	
	if (st < 0)
	{
		texture = round;
		status = 1;
	}
	else
	{
		texture = cross;
		status = 2;
	}


}
void box::setwinner()
{

	if (status == 2)
	{
		texture = crosswin;
		return;
	}
	if (status == 1)
	{
		texture = roundwin;
		return;
	}

}

int box::Getstatus()
{

	return status;

}


void box::freeres()
{

	//SDL_FreeSurface(texture);
//	SDL_FreeSurface(cross);
	//SDL_FreeSurface(round);
	//SDL_FreeSurface(crosswin);
	//SDL_FreeSurface(roundwin);

}


