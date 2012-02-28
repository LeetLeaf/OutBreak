#include "TextureList.h"

TextureList::TextureList()
{

}

GLuint TextureList::loadTexture( const std::string &fileName )
{
    SDL_Surface *image = IMG_Load( fileName.c_str() );

    SDL_DisplayFormatAlpha(image);

    GLuint object;

    glGenTextures(1, &object);

    glBindTexture(GL_TEXTURE_2D, object);

    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image->w, image->h, 0, GL_RGBA, GL_UNSIGNED_BYTE, image->pixels);

    //Free surface
    SDL_FreeSurface(image);

    return object;
}

void TextureList::intTextureList()
{
    tile[0] = loadTexture("Images/tile0.png");
	tile[1] = loadTexture("Images/tile1.png");
	tile[2] = loadTexture("Images/tile2_1.png");
	tile[3] = loadTexture("Images/tile2_2.png");
	playerTexture = loadTexture("Images/Player.png");
	inventory = loadTexture("Images/Inventory.png");
}


unsigned int TextureList::getTile(int number)
{
	return tile[number];
}
unsigned int TextureList::getInventory()
{
	return inventory;
}
unsigned int TextureList::getPlayerTex()
{
	return playerTexture;
}

