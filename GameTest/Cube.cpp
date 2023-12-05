#include "stdafx.h"

#define _USE_MATH_DEFINES
#include <math.h> 
#include "App/app.h"
#include "Cube.h"


Cube::Coords_2d Cube::Convert_3D_2D(Coords_3d v, float fov)
{
	float x = v.x;
	float y = v.y;
	APP_VIRTUAL_TO_NATIVE_COORDS(x, y);
	float aspectRatio = APP_VIRTUAL_WIDTH / APP_VIRTUAL_HEIGHT;
	float w = v.z;
	float f = 1 / tanf(fov / 2);
	float X = x / w;
	float Y = y / w;


	//float newX = (X + 1) / 2 * APP_VIRTUAL_WIDTH;
	//float newY = (Y + 1) / 2 * APP_VIRTUAL_HEIGHT;
	APP_NATIVE_TO_VIRTUAL_COORDS(X, Y);
	Cube::Coords_2d r;
	r.x = X;
	r.y = Y;
	return r;
}

Cube::Cube(Cube::Coords_3d bl_v, float h, float w, float d)
{
	Cube::CubeFace frontFace;
	Cube::CubeFace backFace;
	Cube::CubeFace leftFace;
	Cube::CubeFace rightFace;
	Cube::CubeFace topFace;
	Cube::CubeFace bottomFace;

	Cube::Coords_3d v = bl_v;
	frontFace.v1 = v;
	v.y += h;
	frontFace.v2 = v;
	v.x += w;
	frontFace.v3 = v;
	v.y -= h;
	frontFace.v4 = v;
	shape[0] = frontFace;

	v = bl_v;
	v.z += d;
	backFace.v1 = v;
	v.y += h;
	backFace.v2 = v;
	v.x += w;
	backFace.v3 = v;
	v.y -= h;
	backFace.v4 = v;
	shape[1] = backFace;

	v = bl_v;
	leftFace.v1 = v;
	v.y += h;
	leftFace.v2 = v;
	v.z += d;
	leftFace.v3 = v;
	v.y -= h;
	leftFace.v4 = v;
	shape[2] = leftFace;

	v = bl_v;
	v.x += w;
	rightFace.v1 = v;
	v.y += h;
	rightFace.v2 = v;
	v.z += d;
	rightFace.v3 = v;
	v.y -= h;
	rightFace.v4 = v;
	shape[3] = rightFace;

	v = bl_v;
	bottomFace.v1 = v;
	v.z += d;
	bottomFace.v2 = v;
	v.x += w;
	bottomFace.v3 = v;
	v.z -= d;
	bottomFace.v4 = v;
	shape[4] = bottomFace;

	v = bl_v;
	v.y += h;
	topFace.v1 = v;
	v.z += d;
	topFace.v2 = v;
	v.x += w;
	topFace.v3 = v;
	v.z -= d;
	topFace.v4 = v;
	shape[5] = topFace;
}

Cube::Cube()
{}

void Cube::DrawCube(float r, float g, float b)
{
	double fov = M_PI_2;
	for (int i = 0; i < faces; i++)
	{
		Cube::Coords_2d xy1 = Convert_3D_2D(shape[i].v1, fov);
		Cube::Coords_2d xy2 = Convert_3D_2D(shape[i].v2, fov);
		Cube::Coords_2d xy3 = Convert_3D_2D(shape[i].v3, fov);
		Cube::Coords_2d xy4 = Convert_3D_2D(shape[i].v4, fov);
		App::DrawLine(xy1.x, xy1.y, xy2.x, xy2.y, r, g, b);
		App::DrawLine(xy2.x, xy2.y, xy3.x, xy3.y, r, g, b);
		App::DrawLine(xy3.x, xy3.y, xy4.x, xy4.y, r, g, b);
		App::DrawLine(xy4.x, xy4.y, xy1.x, xy1.y, r, g, b);
	}
}