#include "pch.h"
#include "Triangle_map.h"

Triangle_map::Triangle_map()
{
}

Triangle_map::Triangle_map(uint16_t v0, uint16_t v1, uint16_t v2, uint16_t mat_index) :
	m_v0{ v0 }, m_v1{ v1 }, m_v2{ v2 }, m_material_index{mat_index}
{
}

Triangle_map::~Triangle_map()
{
}
