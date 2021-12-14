#include "pch.h"
#include "Model.h"

Model::Model(const char filepath[])
{
	build_model(filepath);
}

Model::Model(const Model& other) :
	m_verticies {other.m_verticies},
	m_triangles {other.m_triangles}
{
}

Model Model::operator=(const Model& other)
{
	if (this != &other)
	{
		m_verticies = other.m_verticies;
		m_triangles = other.m_triangles;
	}
	return *this;
}

Model::Model(Model&& other) noexcept 
{
	*this = std::move(other); //more robust checks this != &other;
}

Model Model::operator=(Model&& other) noexcept
{
	if (this != &other)
	{
		m_verticies = std::move(other.m_verticies);
		m_triangles = std::move(other.m_triangles);

		other.m_verticies.clear();
		other.m_triangles.clear();
	}
	return *this;
}

Model::~Model()
{
}

void Model::update_bounding_sphere()
{
}

void Model::build_model(const char filepath[])
{
	auto sqy_mesh = sqy_obj::load_obj_file(filepath);
	
	for (auto& a : sqy_mesh.m_verticies)
	{
		this->m_verticies.push_back(conv::sqy_obj_vert_to_vertex(a));
	}
	for (auto& a : sqy_mesh.m_face_mapping)
	{
		Triangle temp(a.indicies[0], a.indicies[1], a.indicies[2]);
		this->m_triangles.push_back(temp);
	}
}
