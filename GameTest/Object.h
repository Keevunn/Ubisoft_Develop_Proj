#pragma once

#include "Geometry.h"

using vertex = coordinate;
using face = std::vector<coordinate>;
using shape = std::vector<face>;
using edge = std::pair<coordinate, coordinate>;
using edges = std::vector<edge>;

//-----------------------------------------------------------------------------
// Object
// Represents a general shape
//-----------------------------------------------------------------------------
class object 
{
protected:
	shape mesh;
	edges lines;

public:
	coordinate position;
	float x_angle, y_angle, z_angle;
	coordinate velocity;
	float x_vel, y_vel, z_vel;

	matrix config;

	object(shape _mesh, coordinate pos = { {0,0,0} }, float x = 0.f, float y = 0.f, float z = 0.f)
		: position{ pos }, x_angle{ x }, y_angle{ y }, z_angle{ z } 
	{
		mesh = _mesh;
		lines = edgesof(mesh);
		config = configuration();
		x_vel = 15;
		y_vel = 15;
		z_vel = 15;
		velocity = { {1,1,5} };
	}
	// 
	void update(float delta_time);
	matrix configuration();
	edges getedges();
	bool isVisible();
};