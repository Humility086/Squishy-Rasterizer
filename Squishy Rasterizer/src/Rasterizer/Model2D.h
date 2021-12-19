#pragma once
#include "..\pch.h"
#include "..\Primitives\Triangle.h"
#include "..\Primitives\Model.h"

struct Model2D
{
	std::vector<Fragment> m_fragments;
	std::vector<Triangle> m_triangles;

	Model2D(const Model& souce);

	std::vector<Fragment> get_wireframe();
};

inline Model2D::Model2D(const Model& source)
{
	for (auto it = source.m_verticies.begin(); it != source.m_verticies.end(); ++it)
	{
		//converts all verts into fragments
		Fragment temp(*it);
		m_fragments.push_back(temp);
	}
	
	for (auto it = source.m_triangle_maps.begin(); it != source.m_triangle_maps.end(); ++it)
	{
		//genreates triangles from fragment vector
		Triangle temp(m_fragments[it->m_v0], m_fragments[it->m_v1], m_fragments[it->m_v2]);
		m_triangles.push_back(temp);
	}
}

inline std::vector<Fragment> Model2D::get_wireframe()
{
	std::vector<Fragment> wireframe;
	for (auto& a : m_triangles)
	{
		auto temp = a.return_edges();
		wireframe.insert(wireframe.begin(), temp.begin(), temp.end());
	}
	return wireframe;
}
