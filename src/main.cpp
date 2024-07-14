#include <SDL2/SDL_events.h>
#include <SDL2/SDL_video.h>
#include <stdlib.h>
#include <SDL2/SDL.h>

int main(int argc, char* argv[])
{
	SDL_Init(SDL_INIT_EVERYTHING);

	SDL_Window* window  = SDL_CreateWindow("Window",
	 SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,  600, 400, 0);

	SDL_Event event;
	bool quit = false;

	

	while (!quit)
	{
		SDL_PollEvent(&event);

		if(event.type == SDL_QUIT)
		{
			quit = true;
		}
	}
	return 0;
}
