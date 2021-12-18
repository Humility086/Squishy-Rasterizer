#pragma once
#include "..\pch.h"
#include "..\Primitives\Model.h"
#include "..\Primitives\Triangle.h"

//I could remake the model type here to reduce its memory footprint,
//however, as this is being built on a system with only 8 logical cores
//I will favour speed over memory footprint.

class screen_mapper
{
private:
	std::vector<Model> m_screen_coords;

public:

};
