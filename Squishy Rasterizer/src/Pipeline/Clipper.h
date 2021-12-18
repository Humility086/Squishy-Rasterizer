#pragma once
#include "..\pch.h"
#include "..\Primitives\Model.h"
#include "Buffers/Vertex_buffer.h"

class Clipper
{
private: 
	std::vector<Model> m_clipspace;

public:
	Clipper() = delete;
	Clipper(Vertex_buffer& source);
	Clipper(const Clipper& other) = delete;
	~Clipper();

	std::vector<Model>& get_clipped_data();
	void start_clip_chain(Vertex_buffer& source);

private:
	void backface_cull(); //hidden surface removal
};
