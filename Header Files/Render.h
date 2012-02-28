#ifndef RENDERING_H
#define RENDERING_H
#include "Screen.h"
#include "TextureList.h"
#include "Grid.h"
#include "Inventory.h"
#include "Player.h"

class Render
{
	public:
		Render();
		void renderEntities(Screen screen,TextureList tl, Grid grid,Player player,Inventory i);

	private:


};


#endif