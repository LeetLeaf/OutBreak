#ifndef SCREEN_H
#define SCREEN_H

#include "SDL.h"
#include "SDL_opengl.h"
#include <string>


class Screen
{
    public:
        Screen();

		void setScreenY(int x);
		int getScreenY();
		void setScreenX(int x);
		int getScreenX();
		void setScreenHeight(int x);
		int getScreenHeight();
		void setScreenWidth(int x);
		int getScreenWidth();

    private:
		int screenWidth,screenHeight,screenX,screenY;
};

#endif // SCREEN_H
