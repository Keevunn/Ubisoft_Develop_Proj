#pragma once
#include "Geometry.h"

//-----------------------------------------------------------------------------
// Camera
//-----------------------------------------------------------------------------
class camera {
private:
	coordinate position;
	float x_angle, y_angle, z_angle;
	coordinate velocity;
	float x_vel, y_vel, z_vel;
	float fov;
	matrix config;

public:
	camera(coordinate pos = coordinate{ {0,0,0} }, float x = 0.f, float y = 0.f, float z = 0.f, float fov = 100.f) : position{ pos }, x_angle{ x }, y_angle{ y }, z_angle{ z }, fov {fov}
	{
		config = configuration();
	}

	void update(float delta_time);
	matrix configuration();
	coordinate projection(coordinate p);
	void setFOV(float new_fov);
};