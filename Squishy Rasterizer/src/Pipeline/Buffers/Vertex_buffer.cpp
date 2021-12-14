#include "pch.h"
#include "Vertex_buffer.h"

Vertex_buffer::Vertex_buffer()
{
}

Vertex_buffer::~Vertex_buffer()
{
}

const std::vector<Model>& Vertex_buffer::get_buffer_data() const
{
	return m_v_buffer;
}

void Vertex_buffer::add_model(Model source)
{
	m_world_state.push_back(source);
}

Model& Vertex_buffer::access_model(uint16_t index)
{
	return m_world_state[index];
}

void Vertex_buffer::apply_view_matrix(const Camera& camera)
{
	m_v_buffer.clear();
	m_v_buffer = m_world_state; //musn't forget to copy the world state into the buffer acctual
	for (auto& a : m_v_buffer)
	{
		for (auto& b : a.m_verticies)
		{
			b.m_position = camera.get_view_matrix() * b.m_position;
			//b.m_normal = camera.get_view_normal_mat() * b.m_normal;
		}
	}
}

void Vertex_buffer::apply_perspective_mat4(const Camera& camera)
{
	for (auto& a : m_v_buffer)
	{
		for (auto& b : a.m_verticies)
		{
			b.m_position = camera.get_perspective_matrix() * b.m_position;
			//b.m_normal = camera.get_perspective_norm_mat() * b.m_normal;
		}
	}
}

void Vertex_buffer::end_of_frame_refresh()
{
	m_v_buffer.clear();
}
