#include "pch.h"
#include "Screen_mapper.h"

screen_mapper::screen_mapper()
{
}

screen_mapper::~screen_mapper()
{
}

void screen_mapper::update_state(const Clipper& clipper, const Camera& camera)
{
	m_models.clear();
	std::vector<Model> screen_coords = clipper.get_clipped_data();
	perspective_divide(screen_coords); //Generate NDC after being in clip space
	for (auto& a : screen_coords) //screen coordinates
	{
		a.m_verticies;
		for (auto& b : a.m_verticies)
		{
			b.m_position = camera.get_screen_matrix() * b.m_position;
		}
	}
	for (auto& a : screen_coords) //create 2d models
	{
		Model2D temp(a);
		m_models.push_back(temp);
	}
}

std::vector<Fragment> screen_mapper::get_fragments()
{
	std::vector<Fragment> result;
	for (auto& a : m_models)
	{
		auto temp = a.get_wireframe();
		result.insert(result.end(), temp.begin(), temp.end());
	}
	return result;
}

void screen_mapper::perspective_divide(std::vector<Model>& input)
{
	for (auto& a : input)
	{
		a.m_verticies;
		for (auto& b : a.m_verticies)
		{
			b.m_position.x /= b.m_position.w;
			b.m_position.y /= b.m_position.w;
			b.m_position.z /= b.m_position.w;
			b.m_position.w = 1.f;
		}
	}
}
