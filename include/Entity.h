#pragma once
#include <SDL.h>
#include <SDL_image.h>

class Entity
{
public:
	Entity(float p_x, float p_y, SDL_Texture* p_tex);
	float GetX();
	float GetY();
	SDL_Texture* GetTexture();
	SDL_Rect GetcurrentFrame();
	bool collison(SDL_Rect& playerRect);
private:
	float x, y;
	SDL_Rect currentFrame;
	SDL_Texture* texture;

};
