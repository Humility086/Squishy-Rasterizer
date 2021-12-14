#pragma once
#include "..\..\pch.h"
#include "..\..\Primitives\Model.h"
#include "..\Camera.h"

class Vertex_buffer
{
private:
	std::vector<Model> m_world_state;
	std::vector<Model> m_v_buffer; //world state needs to be protected from culling and clipping
									//thats why we have this

public:
	Vertex_buffer();
	~Vertex_buffer();

	const std::vector<Model>& get_buffer_data() const;
	void add_model(Model source);
	Model& access_model(uint16_t index);
	void apply_view_matrix(const Camera& camera);
	void apply_perspective_mat4(const Camera& camera);
	void end_of_frame_refresh();
};