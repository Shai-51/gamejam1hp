#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <vector>

#include "C:/dev/mvc projects/GameJam1HP/GameJam1HP/include/RenderWindow.h"
#include "C:/dev/mvc projects/GameJam1HP/GameJam1HP/include/Entity.h"


int main(int argc, char* argv[]) {
	int FPS = 60;
	int frameTime = 0;
    SDL_Rect playerRect;
    playerRect.x = 750;
    playerRect.y = 460;
    playerRect.w = 32;
    playerRect.h = 32;
    bool jumping = false;
    int gravity = 1;
    int jumpHight = 20;
    int jumpingSpeed = jumpHight;
	int formerPlayer_x = 0;
	int formerPlayer_y = 0;
	if (SDL_Init(SDL_INIT_VIDEO) > 0)
		std::cout << "HEY.. SDL_Init HAS FAILED. SDL_ERROR: " << SDL_GetError() << std::endl;

	if (!(IMG_Init(IMG_INIT_PNG)))
		std::cout << "IMG_init has failed. Error: " << SDL_GetError() << std::endl;

	RenderWindow Window("game", 800, 600);

	SDL_Texture* grayPlatform = Window.loadTexture("C:/dev/mvc projects/GameJam1HP/GameJam1HP/res/backgroud/grayPlatform.png");
	SDL_Texture* grayLowerPlatform = Window.loadTexture("C:/dev/mvc projects/GameJam1HP/GameJam1HP/res/backgroud/grayLowerPlatform.png");
    SDL_Texture* playerStandingTexture = Window.loadTexture("C:/dev/mvc projects/GameJam1HP/GameJam1HP/res/player/1hpStanding.png");
	SDL_Texture* playerWalikingTexture = Window.loadTexture("C:/dev/mvc projects/GameJam1HP/GameJam1HP/res/player/1hpWalking.png");

	std::vector<Entity> backgroundEntities = { Entity(0, 270, grayLowerPlatform),
													Entity(30, 270, grayLowerPlatform),
													Entity(60, 270, grayLowerPlatform),
													Entity(90, 270, grayLowerPlatform),
													Entity(120, 270, grayLowerPlatform),
													Entity(150, 270, grayLowerPlatform),
													Entity(180, 270, grayLowerPlatform),
													Entity(210, 270, grayLowerPlatform),
													Entity(240, 270, grayLowerPlatform),
													Entity(270, 270, grayLowerPlatform),
													Entity(300, 270, grayLowerPlatform),
													Entity(330, 270, grayLowerPlatform),
													Entity(360, 270, grayLowerPlatform),
													Entity(390, 270, grayLowerPlatform),
                                                    Entity(0, 240, grayPlatform),
												    Entity(30, 240, grayPlatform),
												    Entity(60, 240, grayPlatform),
												    Entity(90, 240, grayPlatform),
												    Entity(120, 240, grayPlatform),
												    Entity(150, 240, grayPlatform),
												    Entity(180, 240, grayPlatform),
												    Entity(210, 240, grayPlatform),
												    Entity(240, 240, grayPlatform),
												    Entity(270, 240, grayPlatform),
												    Entity(300, 240, grayPlatform),
												    Entity(330, 240, grayPlatform),
												    Entity(360, 240, grayPlatform),
												    Entity(390, 240, grayPlatform)};


    std::vector<Entity> Platforms = {Entity(30, 220, grayPlatform)};

	bool running = true;
	SDL_Event event;
    bool rightKeyPressed = false;
    bool leftKeyPressed = false;

    while (running)
    {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
            else if (event.type == SDL_KEYDOWN) {
                SDL_Keycode key = event.key.keysym.sym;
                if (key == SDLK_RIGHT) {

                    playerRect.x += 20; 
                    rightKeyPressed = true;
                }
                else if (key == SDLK_LEFT) {

                    playerRect.x -= 20; 
                    leftKeyPressed = true;
                }
            }
            else if (event.type == SDL_KEYUP) {
                SDL_Keycode key = event.key.keysym.sym;
                if (key == SDLK_RIGHT) {
                    rightKeyPressed = false;
                }
                if (key == SDLK_LEFT) {
                    leftKeyPressed = false;
                }
                if (key == SDLK_SPACE or key == SDLK_UP)
                {
                    jumping = true;
                }
            }
        }

        Window.clear();

        if (jumping) {
            playerRect.y -= jumpingSpeed;
            jumpingSpeed -= gravity;
            if (jumpingSpeed < -jumpHight) {
                jumping = false;
                jumpingSpeed = jumpHight;
            }
        }
        for (Entity& e : backgroundEntities) {
            Window.render(e);
        }
        for (Entity& p : Platforms) {
            Window.render(p);
            if (p.collison(playerRect)) {
                    playerRect.x = formerPlayer_x - 10;
                    playerRect.y = formerPlayer_y;
            }
            else {
                formerPlayer_x = playerRect.x;
                formerPlayer_y = playerRect.y;
            }
        }

        if (rightKeyPressed) {
            Window.animate(playerWalikingTexture, playerRect, 100);
        }
        else if (leftKeyPressed) {
            Window.animate(playerWalikingTexture, playerRect, 100);
        }
        else {
            Window.animate(playerStandingTexture, playerRect, 100);
        }

        Window.display();

        
        SDL_Delay(60); 
    }


	Window.cleanUp();
	SDL_Quit();



	return 0;
}