#include "pch.h"
#include "Veretx.h"

//============
//Constrcutors
//============
Vertex::Vertex() :
    m_position{glm::vec4(0.f)}, m_normal{glm::vec3(0.f)}, m_texture_coord{glm::vec2(0.f)}, m_intensity{glm::vec4(1.f)}
{
}

Vertex::Vertex(glm::vec3 pos, glm::vec3 norm, glm::vec2 text_coord) :
    m_position {glm::vec4(pos, 1.f)},
    m_normal {norm},
    m_texture_coord {text_coord},
    m_intensity {glm::vec4(1.f)}
{
}

Vertex::Vertex(glm::vec4 pos, glm::vec3 norm, glm::vec2 text_coord) :
    m_position {pos},
    m_normal {norm},
    m_texture_coord {text_coord},
    m_intensity{ glm::vec4(1.f) }
{
}

//================
//Copy constructor
//================
Vertex::Vertex(const Vertex& other) :
    m_position{other.m_position},
    m_normal{other.m_normal},
    m_texture_coord{ other.m_texture_coord },
    m_intensity{ glm::vec4(1.f) }
{
}

//===============
//Copy assignment
//===============
Vertex& Vertex::operator=(const Vertex& other)
{
    if (this != &other)
    {
        m_position = other.m_position;
        m_normal = other.m_normal;
        m_texture_coord = other.m_texture_coord;
    }
    return *this;
}

//================
//Move constructor
//================
Vertex::Vertex(Vertex&& other) noexcept 
 
{
    *this = std::move(other); //more robust checks this != &other;
}

//===============
//Move assignment
//===============
Vertex Vertex::operator=(Vertex&& other) noexcept
{
    if (this != &other)
    {
        m_position = std::move(other.m_position);
        m_normal = std::move(other.m_normal);
        m_texture_coord = std::move(other.m_texture_coord);
        m_intensity = std::move(other.m_intensity);

        other.m_position = glm::vec4(0.f);
        other.m_normal = glm::vec3(0.f);
        other.m_texture_coord = glm::vec2(0.f);
        other.m_intensity = glm::vec4(1.f);
    }
    return *this;
}

//===========
//Destructors
//===========
Vertex::~Vertex()
{
}
