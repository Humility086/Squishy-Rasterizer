#include "pch.h"
#include "Rasterizer.h"

Rasterizer::Rasterizer(const Camera& camera, Clipper& clipper) :
	m_screen_buffer {clipper.get_clipped_data()}
{
	for (auto& a : m_screen_buffer)
	{
		for (auto& b : a.m_verticies)
		{
			b.m_position = camera.get_screen_matrix() * b.m_position;
		}
	}
}

Rasterizer::~Rasterizer()
{
}

void Rasterizer::start_pixel_processing(const Camera& camera, Clipper& clipper)
{
	m_screen_buffer = clipper.get_clipped_data();
	for (auto& a : m_screen_buffer)
	{
		for (auto& b : a.m_verticies)
		{
			b.m_position = camera.get_screen_matrix() * b.m_position;
		}
	}
}

void Rasterizer::triangle_setup()
{
	for (auto& a : m_screen_buffer)
	{
		for (auto& b : a.m_triangles)
		{
			const glm::vec3& v0 = glm::vec3(a.m_verticies[b.m_v0].m_position);
			const glm::vec3& v1 = glm::vec3(a.m_verticies[b.m_v1].m_position);
			const glm::vec3& v2 = glm::vec3(a.m_verticies[b.m_v2].m_position);

			auto l01 = glm::length(v1 - v0);
			auto l12 = glm::length(v2 - v1);
			auto l20 = glm::length(v0 - v2);

			float long_side = std::max({ l01, l12, l20 });
		}
	}
}
