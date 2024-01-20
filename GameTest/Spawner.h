#pragma once
#include "stdafx.h"
#include "App/AppSettings.h"

#include "Object.h"
#include "Camera.h"

class Spawner
{
private:
	 shape mesh;
	 std::vector<object> objs;
	 matrix screen;
	 camera cam;

public:
	std::pair<int, int> x_range, y_range;
	float z_point;
	size_t density;
	Spawner(matrix s, camera c, shape m, size_t d = 20) : screen{ s }, cam{ c }, mesh { m }, density{ d }
	{
		x_range.first = -300;
		x_range.second = 500;
		y_range.first = -300;
		y_range.second = 400;
		z_point = 5000;
	}

	std::vector<object> gen_object();
	void update(float deltatime);
	void render();
};