#pragma once
#include "..\pch.h"
#include "Veretx.h"

class Triangle
{
public:
	//Members
	uint32_t m_v0;
	uint32_t m_v1;
	uint32_t m_v2;

	//constructors and destructors
	Triangle();
	Triangle(uint32_t v0, uint32_t v1, uint32_t v2);
	~Triangle();
};
