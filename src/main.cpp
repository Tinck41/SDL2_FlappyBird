#include "SDL.h"
#include "utils/logger.h"

//Screen dimension constants
constexpr int SCREEN_WIDTH = 640;
constexpr int SCREEN_HEIGHT = 480;

int main(int argc, char* args[]) {
	//The window we'll be rendering to
	SDL_Window* window = nullptr;

	//The surface contained by the window
	SDL_Surface* screenSurface = nullptr;

	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		FB::utils::LOG_ERROR("SDL could not initialize! SDL_Error: {}\n", SDL_GetError());
	} else {
		//Create window
		window = SDL_CreateWindow("Flappy Bird", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH,
								SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (window == nullptr) {
			FB::utils::LOG_ERROR("Window could not be created! SDL_Error: {}\n", SDL_GetError());
		} else {
			//Get window surface
			screenSurface = SDL_GetWindowSurface(window);

			//Fill the surface white
			SDL_FillRect(screenSurface, nullptr, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));

			//Update the surface
			SDL_UpdateWindowSurface(window);

			//Hack to get window to stay up
			SDL_Event e;
			bool quit = false;
			while (quit == false) {
				while (SDL_PollEvent(&e)) {
					if (e.type == SDL_QUIT) {
						quit = true;
					}
				}
			}
		}
	}
	//Destroy window
	SDL_DestroyWindow(window);

	//Quit SDL subsystems
	SDL_Quit();

	return 0;
}
