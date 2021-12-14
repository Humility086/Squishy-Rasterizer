#pragma once
#include "..\pch.h"
#include "Veretx.h"

struct Plane
{
	glm::vec4 m_normal;
	float& offset = m_normal.w;

	float plane_test(const Vertex& input);
	glm::vec4 closest_point_on_plane(const Vertex& input);
	glm::vec4 closest_point_on_plane(const glm::vec4& input);
};

inline float Plane::plane_test(const Vertex& input)
{
	float result = glm::dot(glm::vec3(m_normal), glm::vec3(input.m_position)) + offset;
	return result;
}

inline glm::vec4 Plane::closest_point_on_plane(const Vertex& input)
{
	glm::vec4 result = input.m_position - plane_test(input) * m_normal;
}

inline glm::vec4 Plane::closest_point_on_plane(const glm::vec4& input)
{
	glm::vec4 result = input - plane_test(input) * m_normal;
}
