#ifndef TEXTURELIST_H
#define TEXTURELIST_H
#include "SDL.h"
#include "SDL_opengl.h"
#include "SDL_image.h"
#include <string>

class TextureList
{
	public:
		TextureList();

		void intTextureList();
		unsigned int getTile(int number);
		unsigned int getPlayerTex();
		unsigned int getInventory();
		GLuint loadTexture( const std::string &fileName );

	private:
		unsigned int tile[4];
		unsigned int playerTexture;
		unsigned int inventory;
};

#endif