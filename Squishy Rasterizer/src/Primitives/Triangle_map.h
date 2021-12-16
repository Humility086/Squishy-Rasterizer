#pragma once
#include "..\pch.h"
#include "Veretx.h"

class Triangle_map
{
public:
	//Members
	uint16_t m_v0;
	uint16_t m_v1;
	uint16_t m_v2;
	uint16_t m_material_index;

	//constructors and destructors
	Triangle_map();
	Triangle_map(uint16_t v0, uint16_t v1, uint16_t v2, uint16_t mat_index);
	~Triangle_map();
};
