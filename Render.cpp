#include "Render.h"
#include "SDL_opengl.h"
#include "TextureList.h"
#include "Screen.h"
#include "Grid.h"
#include "Player.h"

Render::Render()
{


}

void renderPlayer(Player player);
Player player;

void Render::renderEntities(Screen screen,TextureList tl, Grid grid)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glPushMatrix(); //Start rendering phase
	glOrtho(screen.getScreenX(),screen.getScreenWidth(),screen.getScreenHeight(),screen.getScreenY(),-1,1); //Set the matrix
	
	grid.setTile(2,3,2);
	grid.setTile(2,2,3);
	glEnable(GL_TEXTURE_2D);
	grid.renderGrid(tl);
	renderPlayer(player);
	glDisable(GL_TEXTURE_2D);

	glPopMatrix(); //End Render phase

}

void renderPlayer(Player player)
{
	glBegin(GL_QUADS); //Start drawing the pad

    glTexCoord2d(0,0); glVertex2f(player.getX(),player.getY()); //Upper-left corner
    glTexCoord2d(1,0); glVertex2f(player.getX()+player.getWidth(),player.getY()); //Upper-right corner
    glTexCoord2d(1,1); glVertex2f(player.getX()+player.getWidth(),player.getY()+player.getHeight()); //Down-right corner
    glTexCoord2d(0,1); glVertex2f(player.getX(),player.getY()+player.getHeight()); //Down-left corner

    glEnd(); //End drawing

}