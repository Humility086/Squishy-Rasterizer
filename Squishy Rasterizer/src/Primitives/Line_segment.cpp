#include "pch.h"
#include "Line_segment.h"

Line_segment::Line_segment(const Vertex& start, const Vertex& end) :
	m_origin {start}, m_end {end}
{
	auto temp = m_end.m_position - m_origin.m_position;
	uint32_t delta = std::max({ glm::abs(temp.x), glm::abs(temp.y), glm::abs(temp.z) });
	m_line_points.reserve(delta + 1);
	plot_line();
}

Line_segment::~Line_segment()
{
}

void Line_segment::plot_line()
{
	constexpr float EPSILON = 0.5f;
	auto start = m_origin.m_position;
	auto end = m_end.m_position;

	int32_t dx = glm::abs(end.x - start.x);
	int32_t dy = glm::abs(end.y - start.y);
	int32_t dz = glm::abs(end.z - start.z);

	int32_t xs = (start.x < end.x) ? 1 : -1;
	int32_t ys = (start.y < end.y) ? 1 : -1;
	int32_t zs = (start.z < end.z) ? 1 : -1;

	if (dx >= dy && dx >= dz)
	{
		m_line_points.push_back(start);
		float y = start.y;
		float z = start.z;
		float y_error = (2 * dy) - dx;
		float z_error = (2 * dz) - dx;
		
		for (float x = start.x; EPSILON < (glm::abs(x - end.x));)
		{
			if (y_error > 0)
			{
				y += ys;
				y_error += (2 * (dy - dx));
			}
			else
			{
				y_error += (2 * dy);
			}

			if (z_error > 0)
			{
				z += zs;
				z_error += (2 * (dz - dx));
			}
			else
			{
				z_error += (2 * dz);
			}
			x += xs;
			Vertex temp(glm::vec3(x, y, z));
			m_line_points.push_back(temp);
		}
		return;
	}

	if (dy > dx && dy >= dz)
	{
		m_line_points.push_back(start);
		float x = start.x;
		float z = start.z;
		float x_error = (2 * dx) - dy;
		float z_error = (2 * dz) - dy;

		for (float y = start.y; EPSILON < (glm::abs(y - end.y));)
		{
			if (x_error > 0)
			{
				x += xs;
				x_error += (2 * (dx - dy));
			}
			else
			{
				x_error += (2 * dx);
			}

			if (z_error > 0)
			{
				z += zs;
				z_error += (2 * (dz - dy));
			}
			else
			{
				z_error += (2 * dz);
			}
			y += ys;
			Vertex temp(glm::vec3(x, y, z));
			m_line_points.push_back(temp);
		}
		return;
	}
	else
	{
		m_line_points.push_back(start);
		float x = start.x;
		float y = start.y;
		float x_error = (2 * dx) - dz;
		float y_error = (2 * dy) - dz;

		for (float z = start.z; EPSILON < (glm::abs(z - end.z));)
		{
			if (x_error > 0)
			{
				x += xs;
				x_error += (2 * (dx - dz));
			}
			else
			{
				x_error += (2 * dx);
			}

			if (y_error > 0)
			{
				y += ys;
				y_error += (2 * (dy - dz));
			}
			else
			{
				y_error += (2 * dy);
			}
			z += zs;
			Vertex temp(glm::vec3(x, y, z));
			m_line_points.push_back(temp);
		}
		return;
	}
}
