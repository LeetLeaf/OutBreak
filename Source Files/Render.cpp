#include "Render.h"
#include "SDL_opengl.h"
#include "TextureList.h"
#include "Screen.h"
#include "Grid.h"
#include "Player.h"
#include "Inventory.h"

Render::Render()
{


}

void renderPlayer(TextureList tl,Player player);
void renderInventory(TextureList tl,Inventory i,Screen screen);

void Render::renderEntities(Screen screen,TextureList tl, Grid grid,Player player,Inventory i)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glPushMatrix(); //Start rendering phase
	glOrtho(screen.getScreenX(),screen.getScreenWidth(),screen.getScreenHeight(),screen.getScreenY(),-1,1); //Set the matrix
	
	grid.setTile(2,3,2);
	grid.setTile(2,2,3);
	glEnable(GL_TEXTURE_2D);
	glColor4ub(255,255,255,255);
	grid.renderGrid(tl);
	renderPlayer(tl,player);

	renderInventory(tl,i,screen);
	glDisable(GL_TEXTURE_2D);

	glPopMatrix(); //End Render phase

}

void renderPlayer(TextureList tl,Player player)
{
	glBindTexture(GL_TEXTURE_2D,tl.getPlayerTex());

	glBegin(GL_QUADS); //Start drawing the pad

    glTexCoord2d(0,0); glVertex2f(player.getX(),player.getY()); //Upper-left corner
    glTexCoord2d(1,0); glVertex2f(player.getX()+player.getWidth(),player.getY()); //Upper-right corner
    glTexCoord2d(1,1); glVertex2f(player.getX()+player.getWidth(),player.getY()+player.getHeight()); //Down-right corner
    glTexCoord2d(0,1); glVertex2f(player.getX(),player.getY()+player.getHeight()); //Down-left corner

    glEnd(); //End drawing

}

void renderInventory(TextureList tl,Inventory i,Screen screen)
{
	if(i.getDisplayState())
	{
	glBindTexture(GL_TEXTURE_2D,tl.getInventory());

	glBegin(GL_QUADS);

	glTexCoord2d(0,0); glVertex2f(212+screen.getScreenX(),100+screen.getScreenY()); //Upper-left corner
    glTexCoord2d(1,0); glVertex2f(852+screen.getScreenX(),100+screen.getScreenY()); //Upper-right corner
    glTexCoord2d(1,1); glVertex2f(852+screen.getScreenX(),500+screen.getScreenY()); //Down-right corner
    glTexCoord2d(0,1); glVertex2f(212+screen.getScreenX(),500+screen.getScreenY()); //Down-left corner

	glEnd();
	}
}