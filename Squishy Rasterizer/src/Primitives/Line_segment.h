#pragma once
#include "..\pch.h"
#include "Fragment.h"

class Line_segment
{
public:
	Fragment m_origin, m_end;
	std::vector<Fragment>m_line_points;

	Line_segment();
	Line_segment(const Fragment& start, const Fragment& end);
	~Line_segment();

	Line_segment(const Line_segment& other);
	Line_segment operator=(const Line_segment& other);
	Line_segment(Line_segment&& other);
	Line_segment operator=(Line_segment&& other) noexcept;

private:
	void plot_line();
};