#include <SDL2/SDL_stdinc.h>
#include <SDL2/SDL_timer.h>
#include <glm/trigonometric.hpp>
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
	 SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,  600, 400, SDL_WINDOW_OPENGL);

	SDL_Event event;
	bool quit = false;

	
	glm::vec2 a(1.,2.);

	SDL_GLContext context = SDL_GL_CreateContext(window);

	int version = gladLoadGL((GLADloadfunc)SDL_GL_GetProcAddress);

	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER,1);	
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION,4);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION,5);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK,SDL_GL_CONTEXT_PROFILE_CORE);

	 

	while (!quit)
	{
		SDL_PollEvent(&event);

		if(event.type == SDL_QUIT)
		{
			quit = true;
		}

		glClearColor(1,0,1,1);
		glClear(GL_COLOR_BUFFER_BIT);

		SDL_GL_SwapWindow(window);
		SDL_Delay(1);
	}

	SDL_GL_DeleteContext(context);
	SDL_DestroyWindow(window);
	return 0;
}
