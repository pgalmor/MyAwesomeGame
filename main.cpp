#include <iostream>
#include "SDL/include/SDL.h"
#include "SDL_image/include/SDL_image.h"

#pragma comment(lib, "SDL/libx86/SDL2.lib")
#pragma comment(lib, "SDL/libx86/SDL2main.lib")
#pragma comment(lib, "SDL_image/libx86/SDL2_image.lib")


using namespace std;

#define Bullet_No 10 // Maximum no of alive bullet

int main(int argc, char **argv) {
	bool winClose = true;
	int SDL_Init(SDL_INIT_VIDEO);
	int IMG_Init(IMG_INIT_PNG);

	SDL_Window *mainFin;
	SDL_Renderer *winRender;
	SDL_Rect rectangle;
	SDL_Rect shot;
	
	SDL_Surface *image;
	image = IMG_Load("Assets/pingu.png");
	if (!image) {
		winClose = false;
	}

	/*class _Bullet {
	public:
		bool alive; // For bullet alive checking
		SDL_Rect shot; // For SDL fill rectangle
		char w, h; // The width & height of a bullet
	} bullet[Bullet_No];
	// Initialize the bullet
	for (int i = 0; i < Bullet_No; i++) {
		bullet[i].alive = 0;
		bullet[i].w = 75; // Bullet Size Configuration
		bullet[i].h = 20;
	}*/

	
	bool shoot = false;
	mainFin = SDL_CreateWindow("MyAwesomeGame by Pol Galan", 600, 100, 600, 600, SDL_WINDOW_RESIZABLE);
	winRender = SDL_CreateRenderer(mainFin, -1, SDL_RENDERER_ACCELERATED);
	SDL_Event event;
	rectangle.x = 20;
	rectangle.y = 10;
	rectangle.w = 200;
	rectangle.h = 100;

	while (shoot == true) {
		shot.x = rectangle.x + 200;
		shot.y = rectangle.y + 40;
		shot.w = 75;
		shot.h = 20;
	}

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
					shoot = true;
					
					break;
				case SDLK_ESCAPE:
					winClose = false;
					break;
				}
			}
		}
		SDL_SetRenderDrawColor(winRender, 255, 0, 0, 0);
		SDL_RenderFillRect(winRender, &rectangle);
		SDL_SetRenderDrawColor(winRender, 0, 255, 0, 0);
		SDL_RenderFillRect(winRender, &shot);
		SDL_RenderPresent(winRender);
		SDL_SetRenderDrawColor(winRender, 0, 0, 0xff, 0xff);
		SDL_RenderClear(winRender);
	}
	SDL_DestroyRenderer(winRender);
	SDL_DestroyWindow(mainFin);
	IMG_Quit();
	SDL_Quit();
	cin.get();


	
	/*
	while (shotRun) {

		// Check if exist any empty slot for Initialize a bullet
		if (bKeySpace == 1 && bKeySpaceTick % 10 == 1) {
			for (int i = 0; i < Bullet_No; i++) if (!bullet[i].alive) {
				bullet[i].alive = 1;
				bullet[i].shot.x = rectangle.x + 200;
				bullet[i].shot.y = rectangle.y + 40;
				break; // break this for( ) loop
			}
		} // if(bKeyA == 1 && bKeyATick%10 == 1) { END
		for (int i = 0; i < Bullet_No; i++) if (bullet[i].alive) {
			bullet[i].shot.x += 5;
			bullet[i].shot.w = bullet[i].w;
			bullet[i].shot.h = bullet[i].h;
			SDL_SetRenderDrawColor(winRender, 0, 255, 0, 0);
			SDL_RenderFillRect(winRender, &bullet[i].shot);
			// Bullet Destroy condition
			if (bullet[i].shot.x > 600) bullet[i].alive = 0;
		}

		if (bKeySpace) bKeySpaceTick++; // Press KeyA counter + 1
		if (!bKeySpace) bKeySpaceTick = 0; // Release KeyA counter = 0

	}; // while(bRun) { END
	*/

	return 0;
}