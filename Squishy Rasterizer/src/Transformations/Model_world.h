#pragma once
#include "..\pch.h"

constexpr float F_MAX = std::numeric_limits<float>::max();

namespace tfm 
{
	constexpr glm::mat4 identity = glm::mat4(1.f);

	glm::mat4 u_scale(const float scale_factor);
	glm::mat4 scale(const glm::vec3 scale_vec);
	glm::mat4 rotate_around_wOrigin(const float degrees, const glm::vec3 axis);
	glm::mat4 translate(const glm::vec3 displacement);
}