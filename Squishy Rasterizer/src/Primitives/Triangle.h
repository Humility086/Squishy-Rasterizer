#pragma once
#include "..\pch.h"
#include "Fragment.h"
#include "Line_segment.h"

class Triangle
{
public:
	Fragment *m_tf0, *m_tf1, *m_tf2;
	Line_segment m_l01, m_l12, m_l20;
	//glm::vec3 m_surface_normal;
	
	Triangle() =  delete;
	Triangle(Fragment v0, Fragment v1, Fragment v2);
	~Triangle();

	Triangle(const Triangle& other);
	Triangle operator=(const Triangle& other);
	Triangle(Triangle&& other)noexcept;
	Triangle operator=(Triangle&& other)noexcept;

	std::vector<Fragment> return_edges();

private:
	void calculate_surface_normal();
};
