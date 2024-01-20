#include "stdafx.h"
#include "MatrixHelper.h"
#include <stdexcept>

coordinate coordinate::unit(float theta)
{
	float angle = theta * PI / 180; // convert to radians
	return coordinate{ {cos(angle), sin(angle), 0} };
}

float coordinate::dot(const coordinate& rhs)
{
	float r = 0.f;
	for (int i = 0; i < dimensions; i++)
		r += (coord[i] * rhs.coord[i]);
	return r;
}

coordinate matrix::applied(const coordinate& rhs)
{
	coordinate r;
	for (size_t i = 0; i < dimensions; i++)
		for (size_t j = 0; j < dimensions; j++)
			r.coord[i] += data[i][j] * rhs.coord[j];
	return r;
}

matrix matrix::zero()
{
	matrix r;
	for (size_t i = 0; i < dimensions; i++)
		for (size_t j = 0; j < dimensions; j++)
			r.data[i][j] = 0;
	return r;
}

matrix matrix::identity()
{
	matrix r = zero();
	for (size_t i = 0; i < dimensions; i++)
		r.data[i][i] = 1;
	return r;
}

matrix matrix::rotation(float theta)
{
	float angle = theta * PI / 180;
	matrix rot_M{ { {	{cos(angle), -sin(angle), 0},
						{sin(angle), cos(angle), 0},
						{0, 0, 1} } } };
	return rot_M;
}

matrix matrix::rotation_x(float theta)
{
	float angle = theta * PI / 180;
	float s = sin(angle);
	float c = cos(angle);
	matrix rot_Mx{ { { 
		{1, 0, 0, 0},
		{0, c, -s, 0},
		{0, s, c, 0},
		{0, 0, 0, 1}
		} } };
	return rot_Mx; 
}

matrix matrix::rotation_y(float theta)
{
	float angle = theta * PI / 180;
	float s = sin(angle);
	float c = cos(angle);
	matrix rot_My{ { {
		{c, 0, -s, 0},
		{0, 1, 0, 0},
		{s, 0, c, 0},
		{0, 0, 0, 1}
		} } };
	return rot_My;
}

matrix matrix::rotation_z(float theta)
{
	float angle = theta * PI / 180;
	float s = sin(angle);
	float c = cos(angle);
	matrix rot_Mz{ { {
		{c, -s, 0, 0},
		{s, c, 0, 0},
		{0, 0, 1, 0},
		{0, 0, 0, 1}
		} } };
	return rot_Mz;
}

matrix matrix::translation(coordinate v)
{
	constexpr unsigned int x = 0;
	constexpr unsigned int y = 1;
	constexpr unsigned int z = 2;
	return matrix{ { {
		{1, 0, 0, v[x]},
		{0, 1, 0, v[y]},
		{0, 0, 1, v[z]},
		{0, 0, 0, 1}
		} } };
};

coordinate operator*(float scalar, coordinate& rhs) {
	rhs *= scalar;
	return rhs;
};
