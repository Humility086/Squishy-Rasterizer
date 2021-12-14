#pragma once
#include "..\pch.h"
#include "Veretx.h"
#include "Triangle.h"
#include "..\Helpers\Simple_obj converter.h"
#include "..\Transformations\Model_world.h"

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

	//transformations
	void u_scale(const float scale_factor);
	void scale(const glm::vec3 scale_vec);
	void rotate_around_world(const float degrees, const glm::vec3 axis);
	void rotate_in_place(const float degrees, const glm::vec3 axis);
	void translate(const glm::vec3 displacement);

	//member functions
	void update_bounding_sphere();

private:
	void build_model(const char filepath[]);
	glm::mat3 calculate_normal_mat3(const glm::mat4& source);
};
