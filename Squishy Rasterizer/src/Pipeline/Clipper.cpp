#include "pch.h"
#include "Clipper.h"

//constructors
Clipper::Clipper(Vertex_buffer& source) :
	m_clipspace {}
{
}

Clipper::~Clipper()
{
}

//returns a vector of models AFTER the perspective divide is performed
std::vector<Model>& Clipper::get_clipped_data()
{
	generate_NDC_for_all_models();
	return m_clipspace;
}

//member functions
void Clipper::start_clip_chain(Vertex_buffer& source)
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
		for (auto it = a.m_triangles.begin(); it != a.m_triangles.end();)
		{
			//Ok so this does look ugly - its the two edge vectors
			//v1-v0 and v2-v0 - surface_norm is the x-product of the two.
			glm::vec3 surface_norm = glm::cross
			(glm::vec3(a.m_verticies[it->m_v1].m_position - a.m_verticies[it->m_v0].m_position),
				(glm::vec3(a.m_verticies[it->m_v2].m_position - a.m_verticies[it->m_v0].m_position)));
			
			float result = glm::dot(glm::vec3(0.f, 0.f, -1.f), surface_norm);
			if (result < 0)
			{
				++it;
				continue;
			}
			else
			{
				it = a.m_triangles.erase(it); //erase returns a pointer to the next element that needs to go back
											//into our iterator	
			}
		}
	}
}


//perspective divide
void Clipper::generate_NDC_for_all_models()
{
	for (auto& a : m_clipspace)
	{
		for (auto& b : a.m_verticies)
		{
			b.m_position.x /= b.m_position.w;
			b.m_position.y /= b.m_position.w;
			b.m_position.z /= b.m_position.w;
			b.m_position.w = 1.f;
		}
	}
}
