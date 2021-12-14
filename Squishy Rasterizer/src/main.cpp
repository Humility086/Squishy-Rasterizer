#include "pch.h"
#include "main.h"

int main(int argc, char* argv[])
{
	constexpr uint16_t width = 1024;
	constexpr uint16_t height = 768;

	Window win(width, height);

	//auto cube = sqy_obj::load_obj_file("Media\\obj\\cube2.obj");
	Model b_cube("Media\\obj\\cube2.obj");


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
