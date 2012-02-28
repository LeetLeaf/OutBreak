#include "SDL.h"
#include "SDL_opengl.h"
#include "Screen.h"

Screen::Screen()
{
    screenX = 0;
    screenY = 0;
    screenHeight = 600;
    screenWidth = 1024;
    SDL_Init(SDL_INIT_EVERYTHING);

    //Set OpenGL memory usage
    SDL_GL_SetAttribute( SDL_GL_RED_SIZE, 8 );
    SDL_GL_SetAttribute( SDL_GL_GREEN_SIZE, 8);
    SDL_GL_SetAttribute( SDL_GL_BLUE_SIZE, 8 );
    SDL_GL_SetAttribute( SDL_GL_ALPHA_SIZE, 8);
    SDL_GL_SetAttribute( SDL_GL_BUFFER_SIZE, 32);
    SDL_GL_SetAttribute( SDL_GL_DEPTH_SIZE, 16 );
    SDL_GL_SetAttribute( SDL_GL_DOUBLEBUFFER, 1 );

  //Size of the window
    SDL_SetVideoMode(screenWidth,screenHeight,32, SDL_OPENGL );
  //Specific the clear color
    glClearColor(1,1,1,1); //RED,GREEN,BLUE,ALPHA
    SDL_WM_SetCaption("Outbreak?", NULL );
  //What portion of the screen we will display
    glViewport(0,0,screenWidth,screenHeight);

  //Shader model - Use this
    glShadeModel(GL_SMOOTH);

  //2D rendering
    glMatrixMode(GL_MODELVIEW);

  //"Save" it
    glLoadIdentity();

  //Disable depth checking
    //glDisable(GL_DEPTH_TEST);

  //We enable blending of textures and set how we are going to blend it
    glEnable( GL_BLEND );
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}


// Setters and Getters
void Screen::setScreenY(int x)
{
    screenY = x;
}
int Screen::getScreenY()
{
    return screenY;
}

void Screen::setScreenX(int x)
{
    screenX = x;
}
int Screen::getScreenX()
{
    return screenX;
}

void Screen::setScreenHeight(int x)
{
    screenHeight = x;
}
int Screen::getScreenHeight()
{
    return screenHeight;
}

void Screen::setScreenWidth(int x)
{
    screenWidth = x;
}
int Screen::getScreenWidth()
{
    return screenWidth;
}