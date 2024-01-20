#include "stdafx.h"
#include "Object.h"

void object::update(float delta_time)
{
	position += velocity * delta_time;
	x_angle += x_vel * delta_time;
	y_angle += y_vel * delta_time;
	z_angle += z_vel * delta_time;
	config = configuration();
}

matrix object::configuration()
{
	matrix R_x = matrix::rotation_x(x_angle);
	matrix R_y = matrix::rotation_y(y_angle);
	matrix R_z = matrix::rotation_z(z_angle);

	matrix P = matrix::translation(position);

	// Apply translation <- rotation z <- rotation y <- rotation x
	return P * R_z * R_y * R_x;
}

edges object::getedges()
{
	edges world_coords;
	for (edge e : lines)
		world_coords.push_back(edge{ config * e.first, config * e.second });
	return world_coords;
}

bool object::isVisible()
{
	if (position[0] < -APP_VIRTUAL_WIDTH / (2) || position[0] > APP_VIRTUAL_WIDTH / (2 )
		|| position[1] < -APP_VIRTUAL_HEIGHT / (2 ) || position[1] > APP_VIRTUAL_HEIGHT / (2)
		|| position[2] < 100)
		return false;
	return true;
}


