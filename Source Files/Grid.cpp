#include "Grid.h"
#include "Point.h"
#include "SDL.h"
#include "SDL_opengl.h"
#include <ctime>

Grid::Grid()
{
	srand((unsigned)time(0));

	xMax=100;
	yMax=100;
	

	//Map Gen
	for(int i = 0; i < xMax; i++)
	{
		for(int j = 0; j < yMax; j++)
		{
			grid[i][j] = rand()%2;
		}
	}
	
}
//GET STUFF
int Grid::getX(){return xMax;}
int Grid::getY(){return yMax;}
//SET STUFF
void Grid::setX(int tempX){xMax=tempX;}
void Grid::setY(int tempY){yMax=tempY;}


//Real STUFF

void Grid::renderGrid(TextureList tex)
{
	
	for(int i = 0;i<xMax;i++)
	{
		for(int j =0;j<yMax;j++)
		{
			//render the grid
			switch(grid[i][j])
			{
				case 0:
					glBindTexture(GL_TEXTURE_2D,tex.getTile(0));
					xRender = 32;
					yRender = 32;
					break;	
				case 1:
					glBindTexture(GL_TEXTURE_2D,tex.getTile(1));
					xRender = 32;
					yRender = 32;
					break;
				case 2:
					glBindTexture(GL_TEXTURE_2D,tex.getTile(2));
					xRender = 32;
					yRender = 64;
					break;
			}
			glBegin(GL_QUADS);
			glVertex3f(xRender*i,yRender*j,0);//top Left corner
			glVertex3f(xRender*i+xRender,yRender*j,0);//top right corner
			glVertex3f(xRender*i+xRender,yRender*j+yRender,0);//bottom right corner
			glVertex3f(xRender*i,yRender*j+yRender,0);//bottom left corner
			glEnd();
		}
	}
}
void Grid::setTile(int xpos, int ypos, int tileNum)
{
	grid[xpos][ypos]=tileNum;
}

