#pragma once
#include "..\pch.h"
#include "Clipper.h"
#include "Camera.h"

class Rasterizer
{
private:
	std::vector<Model> m_screen_buffer;

public:
	Rasterizer() = delete;
	Rasterizer(const Camera& camera, Clipper& clipper);
	~Rasterizer();
	Rasterizer(const Rasterizer& other) = delete;

	void start_pixel_processing(const Camera& camera, Clipper& clipper);

private:
	void triangle_setup();
};
