#ifndef GRID_H
#define GRID_H
#include "Point.h"
#include "Screen.h"
#include "TextureList.h"

class Grid
{
	public:
		Grid();
			
		//Basic Crap Down here
		int getX();
		void setX(int tempX);
		int getY();
		void setY(int tempY);

		//Real Shit
		void renderGrid(TextureList tex);
		void setTile(int xpos,int ypos,int tileNum);

		
	private:
		
		int xMax;
		int yMax;
		int grid[100][100];
};

#endif