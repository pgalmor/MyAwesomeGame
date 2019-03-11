#include <iostream>
#include "SDL/include/SDL.h"
#include "SDL_image/include/SDL_image.h"

#pragma comment(lib, "SDL/libx86/SDL2.lib")
#pragma comment(lib, "SDL/libx86/SDL2main.lib")
#pragma comment(lib, "SDL_image/libx86/SDL2_image.lib")

using namespace std;

void clear(SDL_Renderer * winRender, SDL_Texture * Background, SDL_Rect * rectBack);
void draw(SDL_Renderer * winRender, SDL_Rect * rectangle);
void drawShot(SDL_Renderer * winRender, SDL_Rect * shot);

int main(int argc, char **argv) {
	bool winClose = true;
	int SDL_Init(SDL_INIT_VIDEO);
	int IMG_Init(IMG_INIT_PNG);

	SDL_Window *mainFin;
	SDL_Renderer *winRender;
	SDL_Rect rectP;
	SDL_Rect rectP2;
	SDL_Rect rectB;
	SDL_Rect rectB2;
	SDL_Rect rectBack;
	SDL_Surface *Load_Surf;
	SDL_Texture *Player;
	SDL_Texture *Background;
	SDL_Texture *Bullet;

	bool shoot = false;
	mainFin = SDL_CreateWindow("MyAwesomeGame by Pol Galan", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1920, 1080, SDL_WINDOW_RESIZABLE);
	winRender = SDL_CreateRenderer(mainFin, -1, SDL_RENDERER_ACCELERATED);
	SDL_Event event;
	
	Load_Surf = IMG_Load("Assets/Pingu.png");
	if (!Load_Surf) {
		winClose = false;
	}
	Player = SDL_CreateTextureFromSurface(winRender, Load_Surf);
	SDL_FreeSurface(Load_Surf);

	Load_Surf = IMG_Load("Assets/Bullet.png");
	if (!Load_Surf) {
		winClose = false;
	}
	Bullet = SDL_CreateTextureFromSurface(winRender, Load_Surf);
	SDL_FreeSurface(Load_Surf);


	Load_Surf = IMG_Load("Assets/Igloo.jpg");
	if (!Load_Surf) {
		winClose = false;
	}
	Background = SDL_CreateTextureFromSurface(winRender, Load_Surf);
	SDL_FreeSurface(Load_Surf);

	
	rectP.x = 20;
	rectP.y = 10;
	rectP.w = 480;
	rectP.h = 480;

	rectP2.x = 0;
	rectP2.y = 0;
	rectP2.w = 120;
	rectP2.h = 120;

	rectB.x = 0;
	rectB.y = 0;
	rectB.w = 170;
	rectB.h = 170;

	rectB2.x = 0;
	rectB2.y = 0;
	rectB2.w = 85;
	rectB2.h = 85;

	rectBack.x = 0;
	rectBack.y = 0;
	rectBack.w = 1920;
	rectBack.h = 1080;

	while (winClose) {
		if (SDL_PollEvent(&event)) {
			switch (event.type) {
			case SDL_QUIT:
				winClose = false;
				break;
			case SDL_KEYDOWN:
				switch (event.key.keysym.sym) {
				case SDLK_LEFT:
					if (rectP.x != 0) {
						rectP.x = rectP.x - 15;
					}
					break;
				case SDLK_RIGHT:
					if (rectP.x != 400) {
						rectP.x = rectP.x + 15;
					}
					break;
				case SDLK_UP:
					rectP.y = rectP.y - 15;
					break;
				case SDLK_DOWN:
					rectP.y = rectP.y + 15;
					break;
				case SDLK_SPACE:
					rectB.x = rectP.x + 200;
					rectB.y = rectP.y + 40;
					shoot = true;
					break;
				case SDLK_ESCAPE:
					winClose = false;
					break;
				}
			}
		}
		clear(winRender, Background, &rectBack);
		draw(winRender, &rectP);
		if (shoot == true) {
			drawShot(winRender, &rectB);
		}
	}
	SDL_DestroyRenderer(winRender);
	SDL_DestroyWindow(mainFin);
	IMG_Quit();
	SDL_Quit();
	cin.get();

	return 0;
}

void clear(SDL_Renderer * winRender, SDL_Texture * Background, SDL_Rect * rectBack) {
	SDL_RenderCopy(winRender, Background, NULL, NULL);
	SDL_RenderPresent(winRender);
}

void draw(SDL_Renderer * winRender, SDL_Rect * rectP) {
	SDL_SetRenderDrawColor(winRender, 255, 0, 0, 0);
	SDL_RenderFillRect(winRender, rectP);
	SDL_RenderPresent(winRender);
	SDL_Delay(15);
}

void drawShot(SDL_Renderer * winRender, SDL_Rect * rectB) {
	for (int i = 0; i < 30; i++) {
		SDL_Rect noDelay;
		noDelay.x = rectB->x;
		noDelay.y = rectB->y;
		noDelay.w = 4;
		noDelay.h = rectB->h;

		rectB->x += 4;
		SDL_SetRenderDrawColor(winRender, 0, 255, 0, 0);
		SDL_RenderFillRect(winRender, rectB);
		SDL_RenderPresent(winRender);
		SDL_SetRenderDrawColor(winRender, 0, 0, 0xff, 0xff);
		SDL_RenderFillRect(winRender, &noDelay);
		SDL_RenderPresent(winRender);
	}
}