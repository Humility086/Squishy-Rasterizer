#pragma once
#include "..\pch.h"
#include "..\Primitives\Plane.h"

class Camera
{
private:
	glm::mat4 m_view_mat4;
	glm::mat3 m_view_norm_mat3;
	glm::mat4 m_perspective_mat4;
	glm::mat3 m_pers_norm_mat3;
	glm::mat4 m_screen_mat4;
	std::vector<Plane> m_clip_planes;
	
	void extracted_clip_planes();
	void generate_screen_mat4(const float& width, const float& height);

public:

	//constructors
	Camera() = delete;
	Camera(const glm::vec3 location, const glm::vec3 look_at, const glm::vec3 up_vector,
		const float fov, const float width, const float height, const float near = 0.1f, const float far = 100.f);
	Camera(const Camera& other) = delete;

	//member functions
	const glm::mat4& get_view_matrix() const;
	const glm::mat3& get_view_normal_mat() const;
	const glm::mat3& get_perspective_norm_mat() const;
	const glm::mat4& get_perspective_matrix() const;
	const glm::mat4& get_screen_matrix() const;
};
