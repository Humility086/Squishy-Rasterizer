#include "pch.h"
#include "Window.h"

Window::Window(uint16_t window_width_px, uint16_t window_height_px) :
	m_width { window_width_px }, m_height { window_height_px }
{
	if (SDL_Init(SDL_INIT_VIDEO || SDL_INIT_TIMER) < 0)
	{
		std::cout << "SDL failed to initilize correct. Error: "
			<< SDL_GetError << std::endl;
	}

	m_window = SDL_CreateWindow("Squishy Rasterizer - Hardeep Bahia 2021", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, m_width, m_height, 0);
	if (m_window == NULL)
	{
		std::cout << "Window failed to initilize: " << SDL_GetError << std::endl;
	}

	m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_TARGETTEXTURE);
	if (m_renderer == NULL)
	{
		std::cout << "Renderer failed to initilize: " << SDL_GetError << std::endl;
	}

	m_texture = SDL_CreateTexture(m_renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STREAMING, m_width, m_height);
	if (m_texture == NULL)
	{
		std::cout << "Texture failed to initilize: " << SDL_GetError << std::endl;
	}
}

Window::~Window()
{
	SDL_DestroyTexture(m_texture);
	SDL_DestroyRenderer(m_renderer);
	SDL_DestroyWindow(m_window);
}

void Window::present()
{
	SDL_RenderPresent(m_renderer);
}

void Window::display_test()
{
	SDL_Rect filledRect = { m_width / 4, m_height / 4, m_width / 2, m_height / 2 };
	SDL_SetRenderDrawColor(m_renderer, 255, 0, 0, 255);
	SDL_RenderFillRect(m_renderer, &filledRect);
}

void Window::clear()
{
	SDL_SetRenderDrawColor(m_renderer, 0.f, 0.f, 0.f, 255.f);
	SDL_RenderClear(m_renderer);
}
