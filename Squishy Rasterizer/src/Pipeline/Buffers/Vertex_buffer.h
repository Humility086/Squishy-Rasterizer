#pragma once
#include "..\..\pch.h"
#include "..\..\Primitives\Model.h"
#include "..\Camera.h"

//not a true v_buffer I know, but its serving as a good ground
//to perform actions on each vertex. I have decidced to keep 
//the model as a high level of abstraction, and leave the verticies
//interleaved. I'll go into detail why in the post mortem. Hint - 
//I don't want scope creep and I don't want to work on this project forever.

class Vertex_buffer
{
private:
	std::vector<Model> m_world_state;  //world state needs to be protected from culling and clipping

public:
	std::vector<Model> m_v_buffer; //thats why we have this
	std::vector<Model> m_viewspace_uniforms; //viewspace data for lighting an z-value 1/z texturing
	Vertex_buffer();
	~Vertex_buffer();

	const std::vector<Model>& get_buffer_data() const;
	const std::vector<Model>& get_view_space_data() const;
	void add_model(Model source);
	Model& access_model(uint16_t index);
	void apply_view_matrix(const Camera& camera);
	void apply_perspective_mat4(const Camera& camera);
	void end_of_frame_refresh();
};