#pragma once
#include "..\pch.h"
#include "..\Primitives\Model.h"
#include "..\Primitives\Triangle.h"
#include "Clipper.h"
#include "Camera.h"
#include "..\Rasterizer\Model2D.h"

//I could remake the model type here to reduce its memory footprint,
//however, as this is being built on a system with 8 logical cores
//I will favour speed over memory footprint.

class screen_mapper
{
private:
	std::vector<Model2D> m_models;

public:
	screen_mapper();
	~screen_mapper();
	void update_state(const Clipper& clipper, const Camera& camera);
	std::vector<Fragment> get_fragments();
private:
	void perspective_divide(std::vector<Model>& input);
};
