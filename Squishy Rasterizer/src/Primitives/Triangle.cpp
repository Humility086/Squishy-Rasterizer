#include "pch.h"
#include "Triangle.h"

Triangle::Triangle(Fragment v0, Fragment v1, Fragment v2) :
	m_tf0 {&v0}, m_tf1 {&v1}, m_tf2 {&v2},
	m_l01 {*m_tf0, *m_tf1}, m_l12 {*m_tf1, *m_tf2}, m_l20 {*m_tf2, *m_tf0}
{
	//calculate_surface_normal();
}

Triangle::~Triangle()
{
}

Triangle::Triangle(const Triangle& other)
{
	m_tf0 = other.m_tf0;
	m_tf1 = other.m_tf1;
	m_tf2 = other.m_tf2;

	m_l01 = other.m_l01;
	m_l12 = other.m_l12;
	m_l20 = other.m_l20;

	//m_surface_normal = other.m_surface_normal;
}

Triangle Triangle::operator=(const Triangle& other)
{
	if (this != &other)
	{
		m_tf0 = other.m_tf0;
		m_tf1 = other.m_tf1;
		m_tf2 = other.m_tf2;

		m_l01 = other.m_l01;
		m_l12 = other.m_l12;
		m_l20 = other.m_l20;

		//m_surface_normal = other.m_surface_normal;
	}
	return *this;
}

Triangle::Triangle(Triangle&& other) noexcept
{
	*this = std::move(other);
}

Triangle Triangle::operator=(Triangle&& other) noexcept
{
	if (this != &other)
	{
		m_tf0 = std::move(other.m_tf0);
		m_tf1 = std::move(other.m_tf1);
		m_tf2 = std::move(other.m_tf2);

		m_l01 = std::move(other.m_l01);
		m_l12 = std::move(other.m_l12);
		m_l20 = std::move(other.m_l20);

		//m_surface_normal = std::move(other.m_surface_normal);
	}

	return *this;
}

std::vector<Fragment> Triangle::return_edges()
{
	std::vector<Fragment>edges;

	edges.insert(edges.end(), m_l01.m_line_points.begin(), m_l01.m_line_points.end());
	edges.insert(edges.end(), m_l12.m_line_points.begin(), m_l12.m_line_points.end());
	edges.insert(edges.end(), m_l20.m_line_points.begin(), m_l20.m_line_points.end());

	return edges;
}

void Triangle::calculate_surface_normal()
{
	auto a = m_tf0->m_position - m_tf1->m_position;
	auto b = m_tf2->m_position - m_tf1->m_position;
	//m_surface_normal = glm::cross(glm::vec3(a), glm::vec3(b));
}
