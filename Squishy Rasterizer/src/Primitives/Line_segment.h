#pragma once
#include "..\pch.h"
#include "Veretx.h"

class Line_segment
{
public:
	const Vertex& m_origin, m_end;
	std::vector<Vertex>m_line_points;

	Line_segment() = delete;
	Line_segment(const Vertex& start, const Vertex& end);
	~Line_segment();

private:
	void plot_line();
};