#include "Movement.h"
#include "Player.h"
#include "Screen.h"


Movement::Movement()
{
	playerDir[0] = false;
	playerDir[1] = false;
	playerDir[2] = false;
	playerDir[3] = false;
}

int Movement::getPlayerDir()
{
	for(int i = 0;i < 4;i++)
	{
		if(playerDir[i])
		{
			return i;
		}
	}
	return 0;
}

void Movement::setPlayerDir(int dir,bool state)
{
	playerDir[dir] = state;
}

bool Movement::checkCollision(float Ax, float Ay, float Aw, float Ah, float Bx, float By, float Bw, float Bh)
{
    if ( Ay+Ah < By ) return false; //if A is more to the left than B
    else if ( Ay > By+Bh ) return false; //if A is more to the right than B
    else if ( Ax+Aw < Bx ) return false; //if A is higher than B
    else if ( Ax > Bx+Bw ) return false; //if A is lower than B

    return true;
}

void Movement::moveLogic(Player &player, Screen &screen)
{
	if(playerDir[0])//left
	{
		player.setX(player.getX() - player.getSpeed());
		screen.setScreenX(screen.getScreenX()-player.getSpeed());
        screen.setScreenWidth(screen.getScreenWidth()-player.getSpeed());
	}
	if(playerDir[1])//up
	{
		player.setY(player.getY() - player.getSpeed());
		screen.setScreenY(screen.getScreenY()-player.getSpeed());
        screen.setScreenHeight(screen.getScreenHeight()-player.getSpeed());
	}
	if(playerDir[2])//right
	{
		player.setX(player.getX() + player.getSpeed());
		screen.setScreenX(screen.getScreenX()+player.getSpeed());
        screen.setScreenWidth(screen.getScreenWidth()+player.getSpeed());
	}
	if(playerDir[3])//down
	{
		player.setY(player.getY() + player.getSpeed());
		screen.setScreenY(screen.getScreenY()+player.getSpeed());
        screen.setScreenHeight(screen.getScreenHeight()+player.getSpeed());
	}
}