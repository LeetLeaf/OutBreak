#include "Inventory.h"
#include "SDL_opengl.h"
#include <iostream>

Inventory::Inventory()
{
	displayed = false;
}
void Inventory::toggleDisplayState()
{
	if(displayed)
	{
		displayed = false;
		std::cout<<"false"<<std::endl;
	}
	else if(!displayed)
	{
		displayed = true;
		std::cout<<"true"<<std::endl;
	}
}

bool Inventory::getDisplayState()
{
	return displayed;
}

void Inventory::setDisplayState(bool x)
{
	displayed = x;
}