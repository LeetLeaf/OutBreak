#ifndef PLAYER_H
#define PLAYER_H

class Player
{
	public:
		Player();

		float getX();
		void setX(float x2);
		float getY();
		void setY(float y2);
		int getSpeed();
		void setSpeed(int x);
		bool getAlive();
		void setAlive(bool x);
		int getWidth();
		void setWidth(int x);
		int getHeight();
		void setHeight(int x);

	private:
		float x;
		float y;
		bool alive;
		int speed;
		int angle;
		int width;
		int height;

};

#endif