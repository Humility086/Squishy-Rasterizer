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

	//constructors and destructors
	Triangle_map();
	Triangle_map(uint16_t v0, uint16_t v1, uint16_t v2);
	~Triangle_map();
};
