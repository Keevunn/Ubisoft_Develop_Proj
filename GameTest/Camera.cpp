#include "stdafx.h"
#include "App/AppSettings.h"
#include "Camera.h"

void camera::update(float delta_time)
{
	position += velocity * delta_time;
	x_angle += x_vel * delta_time;
	y_angle += y_vel * delta_time;
	z_angle += z_vel * delta_time;
	config = configuration();
}

matrix camera::configuration()
{
	matrix R_x = matrix::rotation_x(-x_angle);
	matrix R_y = matrix::rotation_y(-y_angle);
	matrix R_z = matrix::rotation_z(-z_angle);

	matrix P = matrix::translation(-position);

	// Undo operations to put camera at origin axis aligned
	return R_z * R_y * R_x * P;
}

coordinate camera::projection(coordinate p)
{
	constexpr float view_distance = 50.f;

	// with FOV
	float aspectRatio = APP_VIRTUAL_WIDTH / APP_VIRTUAL_HEIGHT;
	float fov_rad = fov * (PI / 180);
	float scale = 1.f / tan(fov_rad / 2.f);

	matrix V{ {{
		{1, 0, 0, 0},
		{0, 1, 0, 0},
		{0, 0, 1, 0},
		{0, 0, 1.f / view_distance, 1}
		}} };
	matrix cam_coords = V * config;
	coordinate v = cam_coords * p; 
	float f = 1.f / v[3];
	v *= f;
	//3D -> 2D
	return v;
}

void camera::setFOV(float new_fov)
{
	fov = new_fov;
	config = configuration();
}
