#pragma once
#include "..\pch.h"

struct Vertex
{
	//==============
	//Public members
	//==============
	glm::vec4 m_position;
	glm::vec3 m_normal;
	glm::vec2 m_texture_coord;
	glm::vec4 m_intensity = glm::clamp(m_intensity, 0.f, 1.f);
	//============================
	//Constructors and destructors
	//============================
	Vertex();
	Vertex(glm::vec3 pos, glm::vec3 norm = glm::vec3(0.f), glm::vec2 text_coord = glm::vec2(0.f));
	Vertex(glm::vec4 pos, glm::vec3 norm = glm::vec3(0.f), glm::vec2 text_coord = glm::vec2(0.f));
	Vertex(const Vertex& other);
	Vertex& operator=(const Vertex& other);
	Vertex(Vertex&& other) noexcept;
	Vertex operator= (Vertex&& other) noexcept;
	~Vertex();
};
