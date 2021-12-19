#pragma once
#include "..\pch.h"
#include "Veretx.h"

struct Fragment : public Vertex
{
	Fragment(const Vertex& source);
	using Vertex::Vertex;
	glm::vec4 m_color;

	Fragment(const Fragment& other);
	Fragment operator=(const Fragment& other);
	Fragment(Fragment&& other) noexcept;
	Fragment operator=(Fragment&& other) noexcept;
};

inline Fragment::Fragment(const Vertex& source) :
	Vertex {source}, m_color {glm::vec4(255.f)}
{
}

inline Fragment::Fragment(const Fragment& other) :
	Vertex{other}, m_color {other.m_color}
{
}

inline Fragment Fragment::operator=(const Fragment& other)
{
	if (this != &other)
	{
		Vertex::operator=(other);
		m_color = other.m_color;
	}

	return *this;
}

inline Fragment::Fragment(Fragment&& other) noexcept
{
	*this = std::move(other);
}

inline Fragment Fragment::operator=(Fragment&& other) noexcept
{
	if (this != &other)
	{
		Vertex::operator=(std::move(other));
		m_color = std::move(other.m_color);
	}
	return *this;
}
