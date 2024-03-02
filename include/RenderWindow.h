#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include "C:/dev/mvc projects/GameJam1HP/GameJam1HP/include/Entity.h"
class RenderWindow
{
private:
	SDL_Renderer* Renderer;
	SDL_Window* Window;
	int currentAnimationFrame = 0;
	float animationTimer = 0;
	float animationSpeed = 0;
public:
	RenderWindow(const char* p_title, int p_w, int p_h);
	SDL_Texture* loadTexture(const char* p_filePath);
	void cleanUp();
	void render(Entity& p_Entity);
	void display();
	void clear();
	SDL_Renderer* GetRenderer();
	void animate(SDL_Texture* p_texture, SDL_Rect& Rect, float deltaTime);
};

