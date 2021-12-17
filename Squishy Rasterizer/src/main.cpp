#include "pch.h"
#include "main.h"

int main(int argc, char* argv[])
{
	constexpr uint16_t width = 1024;
	constexpr uint16_t height = 768;

	Window win(width, height);
	Camera camera(glm::vec3(0.f,0.f,1.f), glm::vec3(0.f), glm::vec3(0.f, 1.f, 0.f),
		52, width, height);
	Vertex_buffer v_buffer;
	Clipper clipper(v_buffer);

	Model b_cube("Media\\obj\\cube2.obj");
	//Model cottage("Media\\obj\\cottage.obj");
	v_buffer.add_model(b_cube);
	//v_buffer.add_model(cottage);
	v_buffer.access_model(0).u_scale(3.0);
	v_buffer.access_model(0).rotate_in_place(45, glm::vec3(0.f, 1.f, 0.f));
	v_buffer.access_model(0).translate(glm::vec3(0.f, 0.f, -15.f));
	v_buffer.apply_view_matrix(camera);
	v_buffer.apply_perspective_mat4(camera);

	clipper.start_clip_chain(v_buffer);

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
