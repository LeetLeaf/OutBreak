#ifndef TEXTURES_H
#define TEXTURES_H
#include "SDL.h"
#include "SDL_opengl.h"
#include "SDL_image.h"
#include <string>

class Textures
{
	public:
		Textures();

		void intTextures();
		unsigned int getTile(int number);
		GLuint loadTexture( const std::string &fileName );

	private:
		unsigned int tile[2];
};

#endif