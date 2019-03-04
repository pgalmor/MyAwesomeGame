#include <iostream>
#include "SDL/include/SDL.h"

#pragma comment(lib, "SDL/libx86/SDL2.lib")

#pragma comment(lib, "SDL/libx86/SDL2main.lib")


using namespace std;

int main(int argc, char **argv) {
	SDL_Window *mainFin;
	SDL_Renderer *winRender;
	SDL_Rect rectangle;
	bool winClose = true;
	mainFin = SDL_CreateWindow("MyAwesomeGame by Pol Galan", 600, 100, 600, 600, SDL_WINDOW_RESIZABLE);
	winRender = SDL_CreateRenderer(mainFin, -1, SDL_RENDERER_ACCELERATED);
	SDL_Event event;
	rectangle.x = 20;
	rectangle.y = 10;
	rectangle.w = 200;
	rectangle.h = 100;
	while (winClose) {
		if (SDL_PollEvent(&event)) {
			switch (event.type) {
			case SDL_QUIT:
				winClose = false;
				break;
			case SDL_KEYDOWN:
				switch (event.key.keysym.sym) {
				case SDLK_LEFT:
					if (rectangle.x != 0) {
						rectangle.x = rectangle.x - 4;
					}
					break;
				case SDLK_RIGHT:
					if (rectangle.x != 400) {
						rectangle.x = rectangle.x + 4;
					}
					break;
				case SDLK_UP:
					rectangle.y = rectangle.y - 4;
					break;

				case SDLK_DOWN:
					rectangle.y = rectangle.y + 4;
					break;
				case SDLK_SPACE:

					break;
				}
			}
		}
		SDL_SetRenderDrawColor(winRender, 255, 0, 0, 0);
		SDL_RenderFillRect(winRender, &rectangle);
		SDL_RenderPresent(winRender);
		SDL_SetRenderDrawColor(winRender, 0, 0, 0xff, 0xff);
		SDL_RenderClear(winRender);
	}
	SDL_DestroyRenderer(winRender);
	SDL_DestroyWindow(mainFin);
	SDL_Quit();
	cin.get();

	return 0;
}