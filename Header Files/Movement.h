#ifndef MOVEMENT_H
#define MOVEMENT_H
#include "Player.h"
#include "Screen.h"


class Movement
{
	public:
		Movement();
		int getPlayerDir();
		void setPlayerDir(int dir,bool state);
		void moveLogic(Player &player, Screen &screen);
        bool checkCollision(float Ax, float Ay, float Aw, float Ah, float Bx, float By, float Bw, float Bh);

	private:	
		bool playerDir[4];
};


#endif