#include "pch.h"
#include "main.h"

int main(int argc, char* argv[])
{
	constexpr uint16_t width = 1024;
	constexpr uint16_t height = 768;

	Window win(width, height);

	Model b_cube("Media\\obj\\cube2.obj");
	b_cube.u_scale(3.f);
	b_cube.translate(glm::vec3(0.f, 0.f, -15.f));
	b_cube.rotate_in_place(45, glm::vec3(0.f, 1.f, 0.f));

	//event handler
	bool running = true;
	SDL_Event event{};
	win.clear();

	//main event loop
	while (running)
	{
		while (SDL_PollEvent(&event) != 0)
		{
			switch (event.type)
			{
			case SDL_QUIT:
				running = false;
				SDL_Quit();
				break;
			}
		}
		win.display_test();
		win.present();
		win.clear();
	}
	return 0;
}
