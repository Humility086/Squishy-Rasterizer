#pragma once
#include "..\pch.h"
#include "Veretx.h"

struct Triangle
{
	Vertex m_tv0, m_tv1, m_tv2;
	glm::vec3 m_surface_normal;
	
	Triangle();
	Triangle(Vertex v0, Vertex v1, Vertex v2);
	~Triangle();

	void calculate_surface_normal();
};
