#include <stdlib.h>
#define GLAD_GL_IMPLEMENTATION
#include "glad/gl.h"
#include <SDL2/SDL_video.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL.h>
#include <glm/fwd.hpp>
#include <glm/glm.hpp>

int main(int argc, char* argv[])
{
	SDL_Init(SDL_INIT_EVERYTHING);

	SDL_Window* window  = SDL_CreateWindow("Window",
	 SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,  600, 400, 0);

	SDL_Event event;
	bool quit = false;

	
	glm::vec2 a(1.,2.);

	SDL_GLContext context = SDL_GL_CreateContext(window);

	int version = gladLoadGL((GLADloadfunc)SDL_GL_GetProcAddress);

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
