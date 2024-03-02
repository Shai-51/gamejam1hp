#include "C:/dev/mvc projects/GameJam1HP/GameJam1HP/include/RenderWindow.h"


RenderWindow::RenderWindow(const char* p_title, int p_w, int p_h) {
	// Creating Window & Renderer
	Window = SDL_CreateWindow(p_title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, p_w, p_h, SDL_WINDOW_SHOWN);
	Renderer = SDL_CreateRenderer(Window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
}

SDL_Texture* RenderWindow::loadTexture(const char* fIlePath) {
	SDL_Texture* texture;
	texture = IMG_LoadTexture(Renderer, fIlePath);
	return texture;
}
void RenderWindow::cleanUp()
{
	SDL_DestroyRenderer(Renderer);
	SDL_DestroyWindow(Window);
}

void RenderWindow::render(Entity& p_Entity)
{
	SDL_Rect src;
	src.x = p_Entity.GetcurrentFrame().x;
	src.y = p_Entity.GetcurrentFrame().y;
	src.w = p_Entity.GetcurrentFrame().w;
	src.h = p_Entity.GetcurrentFrame().h;


	SDL_Rect dst;
	dst.x = p_Entity.GetX() * 2;
	dst.y = p_Entity.GetY() * 2;
	dst.w = p_Entity.GetcurrentFrame().w * 2;
	dst.h = p_Entity.GetcurrentFrame().h * 2;

	SDL_RenderCopy(Renderer, p_Entity.GetTexture(), &src, &dst);

}
void RenderWindow::display()
{
	SDL_RenderPresent(Renderer);
}

void RenderWindow::clear()
{
	SDL_RenderClear(Renderer);
}

SDL_Renderer* RenderWindow::GetRenderer()
{
	return Renderer;
}

void RenderWindow::animate(SDL_Texture* p_texture, SDL_Rect& Rect, float deltaTime) {
	 animationTimer += deltaTime;
    if (animationTimer >= animationSpeed) {
        currentAnimationFrame = (currentAnimationFrame + 1) % 8;
        animationTimer = 0.0f;
    }
    SDL_Rect textureAnimateRect = { currentAnimationFrame * Rect.w, 0, Rect.w, Rect.h };
    SDL_Rect destRect = { Rect.x, Rect.y, Rect.w, Rect.h };
    SDL_RenderCopy(Renderer, p_texture, &textureAnimateRect, &destRect);
}




