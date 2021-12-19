#include "pch.h"
#include "Clipper.h"

//constructors
Clipper::Clipper(Vertex_buffer& source) :
	m_clipspace {source.m_v_buffer}
{
}

Clipper::~Clipper()
{
}

//returns a vector of models
const std::vector<Model> Clipper::get_clipped_data() const
{
	return m_clipspace;
}

//member functions
void Clipper::start_clip_chain(const Vertex_buffer& source)
{
	m_clipspace.clear(); //don't forget to flush!
	m_clipspace = source.get_buffer_data();
	backface_cull();
}

//such a simple algorithm works because we're banking on using .obj files
//and obj's preserve a CCW winding order.
void Clipper::backface_cull()
{
	for (auto& a : m_clipspace)
	{
		for (auto it = a.m_triangle_maps.begin(); it != a.m_triangle_maps.end();)
		{
			//Ok so this does look ugly - its the two edge vectors
			//v1-v0 and v2-v0 - surface_norm is the x-product of the two.
			glm::vec3 surface_norm = glm::cross
			(glm::vec3(a.m_verticies[it->m_v1].m_position - a.m_verticies[it->m_v0].m_position),
				(glm::vec3(a.m_verticies[it->m_v2].m_position - a.m_verticies[it->m_v0].m_position)));
			
			float result = glm::dot(glm::vec3(0.f, 0.f, -1.f), surface_norm);
			if (result <= 0.f)
			{
				++it;
				continue;
			}
			else
			{
				it = a.m_triangle_maps.erase(it); //erase returns a pointer to the next element that needs to go back
											//into our iterator	
			}
		}
	}
}
