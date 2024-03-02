#include "C:/dev/mvc projects/GameJam1HP/GameJam1HP/include/Entity.h"
#include <SDL.h>
#include <SDL_image.h>

Entity::Entity(float p_x, float p_y, SDL_Texture* p_texure)
	:x(p_x), y(p_y), texture(p_texure)
{
	currentFrame.x = 0;
	currentFrame.y = 0;
	currentFrame.w = 32;
	currentFrame.h = 32;
}

float Entity::GetX()
{
	return x;
}

float Entity::GetY()
{
	return y;
}

SDL_Texture* Entity::GetTexture()
{
	return texture;
}

SDL_Rect Entity::GetcurrentFrame()
{
	return currentFrame;
}

bool Entity::collison(SDL_Rect& playerRect)
{
	if ((x*2) < playerRect.x + playerRect.w &&
		(x*2) + (currentFrame.w * 2) > playerRect.x &&
		(y*2) < playerRect.y + playerRect.h &&
		(y*2) + (currentFrame.h *2) > playerRect.y) 
	{
		return true;
	}
	
	return false;
}
