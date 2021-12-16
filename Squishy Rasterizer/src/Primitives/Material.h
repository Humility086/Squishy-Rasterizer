#pragma once
#include "..\pch.h"
struct Material
{
	float specular_exponent;
	float ambient_color[3];
	float diffuse_color[3];
	float specular_color[3];
	float alpha;

	Material(const sqy_obj::Material input);
};

inline Material::Material(const sqy_obj::Material input) :
	specular_exponent{ input.specular_exponent },
	alpha{input.alpha}
{
	std::copy(std::begin(input.ambient_color), std::end(input.ambient_color), std::begin(ambient_color));
	std::copy(std::begin(input.diffuse_color), std::end(input.diffuse_color), std::begin(diffuse_color));
	std::copy(std::begin(input.specular_color), std::end(input.specular_color), std::begin(specular_color));
}
