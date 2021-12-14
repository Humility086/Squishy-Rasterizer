#include "pch.h"
#include "Triangle.h"

Triangle::Triangle()
{
}

Triangle::Triangle(uint32_t v0, uint32_t v1, uint32_t v2) :
	m_v0 {v0}, m_v1 {v1}, m_v2 {v2}
{
}

Triangle::~Triangle()
{
}
