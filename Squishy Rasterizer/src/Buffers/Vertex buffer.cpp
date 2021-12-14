#include "pch.h"
#include "Vertex buffer.h"

Vertex_Buffer::Vertex_Buffer()
{
}

Vertex_Buffer::~Vertex_Buffer()
{
}

const std::vector<Model>& Vertex_Buffer::get_buffer_data() const
{
	return m_v_buffer;
}

Model& Vertex_Buffer::access_model(uint16_t index)
{
	return m_world_state[index];
}
