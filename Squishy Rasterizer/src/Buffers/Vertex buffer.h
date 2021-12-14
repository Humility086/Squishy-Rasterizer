#pragma once
#include "..\pch.h"
#include "..\Primitives\Model.h"

class Vertex_Buffer
{
private:
	std::vector<Model> m_world_state;
	std::vector<Model> m_v_buffer;

public:
	Vertex_Buffer();
	~Vertex_Buffer();

	const std::vector<Model>& get_buffer_data() const;
	Model& access_model(uint16_t index);
	void apply_view_matrix();
	void apply_perspective_mat4();
};