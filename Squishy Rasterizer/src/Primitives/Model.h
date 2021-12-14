#pragma once
#include "..\pch.h"
#include "Veretx.h"
#include "Triangle.h"
#include "..\Helpers\Simple_obj converter.h"

class Model
{
public:
	std::vector<Vertex> m_verticies; //why?: contigious and expandable. Can always not render culled verts.
	std::list<Triangle> m_triangles; //why? easy deletions in middle when culling/clipping.
	
	//Bounding sphere
	glm::vec4 center;
	float radius;

	//Constructors and destructors
	Model() = delete;
	Model(const char filepath[]);
	Model(const Model& other);
	Model operator=(const Model& other);
	Model(Model&& other) noexcept;
	Model operator=(Model&& other) noexcept;
	~Model();

	//member functions
	void update_bounding_sphere();

private:
	void build_model(const char filepath[]);
};
