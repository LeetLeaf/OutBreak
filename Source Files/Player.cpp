#include "Player.h"

Player::Player()
{
	x = (1024/2)-16;
	y = (300)-32;
	width = 32;
	height = 64;
	speed = 3;
	alive = true;
}

// Setters and Getters
void Player::setY(float y2)
{
    y = y2;
}
float Player::getY()
{
    return y;
}

void Player::setX(float x2)
{
    x = x2;
}
float Player::getX()
{
    return x;
}

void Player::setHeight(int x)
{
    height = x;
}
int Player::getHeight()
{
    return height;
}

void Player::setWidth(int x)
{
    width = x;
}
int Player::getWidth()
{
    return width;
}

void Player::setSpeed(int x)
{
    speed = x;
}
int Player::getSpeed()
{
    return speed;
}

void Player::setAlive(bool x)
{
    alive = x;
}
bool Player::getAlive()
{
    return alive;
}
