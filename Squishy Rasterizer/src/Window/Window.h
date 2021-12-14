#pragma once
#include <SDL.h>
#include <iostream>

class Window
{
private:
	SDL_Window* m_window;
	SDL_Renderer* m_renderer;
	SDL_Texture* m_texture;

	uint16_t m_width;
	uint16_t m_height;

	Window() = delete;
	Window(const Window& other) = delete;
	Window(const Window&& other) = delete;

public:
	Window(uint16_t window_width_px, uint16_t window_height_px);
	~Window();

	void present();
	void display_test();
	void clear();
};
