#include "pch.h"
#include "Model.h"

Model::Model(const char filepath[])
{
	build_model(filepath);
	update_bounding_sphere();
}

Model::Model(const Model& other) :
	m_verticies {other.m_verticies},
	m_triangle_maps {other.m_triangle_maps},
	m_materials {other.m_materials}
{
}

Model Model::operator=(const Model& other)
{
	if (this != &other)
	{
		m_verticies = other.m_verticies;
		m_triangle_maps = other.m_triangle_maps;
		m_materials = other.m_materials;
	}
	return *this;
}

Model::Model(Model&& other) noexcept 
{
	*this = std::move(other); //more robust checks this != &other;
}

Model Model::operator=(Model&& other) noexcept
{
	if (this != &other)
	{
		m_verticies = std::move(other.m_verticies);
		m_triangle_maps = std::move(other.m_triangle_maps);
		m_materials = std::move(other.m_materials);

		other.m_verticies.clear();
		other.m_triangle_maps.clear();
		other.m_materials.clear();
	}
	return *this;
}

Model::~Model()
{
}

void Model::u_scale(const float scale_factor)
{	
	for (auto& a : m_verticies)
	{
		a.m_position = tfm::u_scale(scale_factor) * a.m_position;

	}
	update_bounding_sphere();
}

void Model::scale(const glm::vec3 scale_vec)
{
	glm::mat4 deformation_mat4 = tfm::scale(scale_vec);
	glm::mat3 normal_matrix = calculate_normal_mat3(deformation_mat4);

	for (auto& a : m_verticies)
	{
		a.m_position = deformation_mat4 * a.m_position;
		a.m_normal = normal_matrix * a.m_normal;
	}
	update_bounding_sphere();
}

void Model::rotate_around_world(const float degrees, const glm::vec3 axis)
{
	glm::mat4 world_rot = tfm::rotate_around_wOrigin(degrees, axis);
	glm::mat3 normal_matrix = calculate_normal_mat3(world_rot);
	
	for (auto& a : m_verticies)
	{
		a.m_position =  world_rot * a.m_position;
		a.m_normal = normal_matrix * a.m_normal;
	}
}

void Model::rotate_in_place(const float degrees, const glm::vec3 axis)
{
	glm::vec3 displacement = glm::vec4(0.f) - center;
	glm::mat4 local_rot_mat4 = tfm::translate(-displacement) * tfm::rotate_around_wOrigin(degrees, axis) *
		tfm::translate(displacement);
	glm::mat3 normal_matrix = calculate_normal_mat3(local_rot_mat4);

	for (auto& a : m_verticies)
	{
		a.m_position = local_rot_mat4 * a.m_position;
		a.m_normal = normal_matrix * a.m_normal;
	}
}

void Model::translate(const glm::vec3 displacement)
{
	for (auto& a : m_verticies)
	{
		a.m_position = tfm::translate(displacement) * a.m_position;
	}
}

void Model::update_bounding_sphere()
{
	float x_left{F_MAX}, x_right{-F_MAX}, y_bottom{F_MAX}, y_top{-F_MAX}, z_near{-F_MAX}, z_far{F_MAX};

	for (const auto& a : m_verticies)
	{
		if (a.m_position.x < x_left)
			x_left = a.m_position.x;

		if (a.m_position.x > x_right)
			x_right = a.m_position.x;

		if (a.m_position.y < y_bottom)
			y_bottom = a.m_position.y;

		if (a.m_position.y > y_top)
			y_top = a.m_position.y;

		if (a.m_position.z > z_near)
			z_near = a.m_position.z;

		if (a.m_position.z < z_far)
			z_far = a.m_position.z;
	}

	center.x = (x_left + x_right) / 2;
	center.y = (y_bottom + y_top) / 2;
	center.z = (z_far + z_near) / 2;
	center.w = 1.f;

	float max_x = std::max({ x_left, x_right});
	float max_y = std::max({ y_bottom, y_top });
	float max_z = std::max({ z_near, z_far });

	float x_rad = glm::abs(max_x - center.x);
	float y_rad = glm::abs(max_y - center.y);
	float z_rad = glm::abs(max_z - center.z);

	//this might seem crazy, but it covers the senario when we scale the model
	//not at the world origin! - it could happen!
	if (x_rad >= y_rad && x_rad >= z_rad)
		radius = x_rad;

	if (y_rad >= x_rad && y_rad >= z_rad)
		radius = y_rad;

	if (z_rad >= x_rad && z_rad >= y_rad)
		radius = z_rad;
}

void Model::build_model(const char filepath[])
{
	auto sqy_mesh = sqy_obj::load_obj_file(filepath);
	
	for (auto& a : sqy_mesh.m_verticies)
	{
		this->m_verticies.push_back(conv::sqy_obj_vert_to_vertex(a));
	}
	for (auto& a : sqy_mesh.m_face_mapping)
	{
		Triangle_map temp(a.indicies[0], a.indicies[1], a.indicies[2], a.material_index);
		this->m_triangle_maps.push_back(temp);
	}
	for (auto& a : sqy_mesh.m_materials)
	{
		Material temp(a);
		this->m_materials.push_back(temp);
	}
}

glm::mat3 Model::calculate_normal_mat3(const glm::mat4& source)
{
	glm::mat3 normal_mat3 = glm::transpose(glm::inverse(source));
	return normal_mat3;
}
