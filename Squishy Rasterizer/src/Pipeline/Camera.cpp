#include "pch.h"
#include "Camera.h"

//constructor - will be using implict destruction
Camera::Camera(const glm::vec3 location, const glm::vec3 look_at, const glm::vec3 up_vector,
	const float fov, const float width, const float height, const float near, const float far) :
	m_view_mat4{ glm::lookAt(location, look_at, up_vector) },
	m_perspective_mat4{ glm::perspective(fov, width / height, near, far) }
{
	m_clip_planes.reserve(6);
	extracted_clip_planes();
	generate_screen_mat4(width, height);
	//m_view_norm_mat3 = glm::transpose(glm::inverse(m_view_mat4));
	//m_pers_norm_mat3 = glm::transpose(glm::inverse(m_perspective_mat4));
}

//private member functions
void Camera::generate_screen_mat4(const float& width, const float& height)
{
	m_screen_mat4[0][0] = width / 2;
	m_screen_mat4[1][1] = -(height / 2);
	m_screen_mat4[2][2] = 0.5f; //d = 1 - forumal is d/2
	m_screen_mat4[3][0] = width / 2;
	m_screen_mat4[3][1] = height / 2;
	m_screen_mat4[3][2] = 0.5f;
}

void Camera::extracted_clip_planes()
{
	uint16_t row = 0;
	Plane temp{};
	float magnitude{};

	for (uint16_t i = 0; i < 6; ++i)
	{
		if (i % 2 == 0)
		{
			temp.m_normal.x = m_perspective_mat4[0][3] + m_perspective_mat4[0][row];
			temp.m_normal.y = m_perspective_mat4[1][3] + m_perspective_mat4[1][row];
			temp.m_normal.z = m_perspective_mat4[2][3] + m_perspective_mat4[2][row];
			temp.m_normal.w = m_perspective_mat4[3][3] + m_perspective_mat4[3][row];
		}

		else
		{
			temp.m_normal.x = m_perspective_mat4[0][3] - m_perspective_mat4[0][row];
			temp.m_normal.y = m_perspective_mat4[1][3] - m_perspective_mat4[1][row];
			temp.m_normal.z = m_perspective_mat4[2][3] - m_perspective_mat4[2][row];
			temp.m_normal.w = m_perspective_mat4[3][3] - m_perspective_mat4[3][row];
			+row;
		}
	}

	magnitude = glm::length(glm::vec3(temp.m_normal));

	temp.m_normal.x /= magnitude;
	temp.m_normal.y /= magnitude;
	temp.m_normal.z /= magnitude;
	temp.m_normal.w /= magnitude;

	m_clip_planes.push_back(temp);
}

//public member functions
const glm::mat4& Camera::get_view_matrix() const
{
	return m_view_mat4;
}

const glm::mat3& Camera::get_view_normal_mat() const
{
	return m_view_norm_mat3;
}

const glm::mat3& Camera::get_perspective_norm_mat() const
{
	return m_pers_norm_mat3;
}

const glm::mat4& Camera::get_perspective_matrix() const
{
	return m_perspective_mat4;
}

const glm::mat4& Camera::get_screen_matrix() const
{
	return m_screen_mat4;
}
