#pragma once
#include "..\pch.h"
#include "..\Primitives\Veretx.h"

namespace conv //converter
{
	//Converts from the Squishy obj data structure to the ones we require
	inline Vertex sqy_obj_vert_to_vertex(const sqy_obj::Vertex& source)
	{
		Vertex temp{};
		temp.m_position = glm::vec4(source.m_position.x, source.m_position.y, source.m_position.z, 1.f);
		temp.m_normal = glm::vec3(source.m_normal.xn, source.m_normal.yn, source.m_normal.zn);
		temp.m_texture_coord = glm::vec2(source.m_texture_coord.u, source.m_texture_coord.v);

		return temp;
	}
}
