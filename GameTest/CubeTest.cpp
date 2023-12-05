//------------------------------------------------------------------------
// CubeTest.cpp
//------------------------------------------------------------------------
#include "stdafx.h"
//------------------------------------------------------------------------
#include <windows.h> 
#define _USE_MATH_DEFINES
#include <math.h>  
//------------------------------------------------------------------------
#include "app\app.h"
#include <cstdio>
//------------------------------------------------------------------------
#include "Cube.h"


/*
struct Cube
{
	int faces;
	float x1, y1, z1, x2, y2, z2, x3, y3, z3, x4, y4, z4;
};
struct TriBasedPyramid
{
	int faces;
	float x1, y1, z1, x2, y2, z2, x3, y3, z3;
};

auto Convert_3D_2D(float x, float y, float z, float fov)
{
	APP_VIRTUAL_TO_NATIVE_COORDS(x, y);
	float aspectRatio = APP_VIRTUAL_WIDTH / APP_VIRTUAL_HEIGHT;
	float w = -z;
	float f = 1 / tanf(fov / 2);
	float X = ((f / aspectRatio) * x) / w;
	float Y = ((f / aspectRatio) * y) / w;


	//float newX = (X + 1) / 2 * APP_VIRTUAL_WIDTH;
	//float newY = (Y + 1) / 2 * APP_VIRTUAL_HEIGHT;
	APP_NATIVE_TO_VIRTUAL_COORDS(X, Y)
		struct coords { float x, y; };
	return coords{ X, Y };
}


Cube* CubeInit(float sx, float sy, float sz, float h, float w, float d)
{
	Cube* C = new Cube[6];

	float x1 = sx;  float y1 = sy;
	APP_VIRTUAL_TO_NATIVE_COORDS(x1, y1);
	float x2 = sx;  float y2 = sy + h;
	APP_VIRTUAL_TO_NATIVE_COORDS(x2, y2);
	float x3 = sx + w; float y3 = sy + h;
	APP_VIRTUAL_TO_NATIVE_COORDS(x3, y3);
	float x4 = sx + w; float y4 = sy;
	APP_VIRTUAL_TO_NATIVE_COORDS(x4, y4);
	float z1 = sz;
	float z2 = sz + d;

	C[0].x1 = x1; C[0].y1 = y1; C[0].z1 = z1; //front face
	C[0].x2 = x2; C[0].y2 = y2; C[0].z2 = z1;
	C[0].x3 = x3; C[0].y3 = y3; C[0].z3 = z1;
	C[0].x4 = x4; C[0].y4 = y4; C[0].z4 = z1;

	C[1].x1 = x1; C[1].y1 = y1; C[1].z1 = z2; //back face
	C[1].x2 = x2; C[1].y2 = y2; C[1].z2 = z2;
	C[1].x3 = x3; C[1].y3 = y3; C[1].z3 = z2;
	C[1].x4 = x4; C[1].y4 = y4; C[1].z4 = z2;

	C[2].x1 = x1; C[2].y1 = y1; C[2].z1 = z1; //right face
	C[2].x2 = x1; C[2].y2 = y1; C[2].z2 = z2;
	C[2].x3 = x2; C[2].y3 = y2; C[2].z3 = z2;
	C[2].x4 = x2; C[2].y4 = y2; C[2].z4 = z1;

	C[3].x1 = x3; C[3].y1 = y3; C[3].z1 = z1; //left face
	C[3].x2 = x3; C[3].y2 = y3; C[3].z2 = z2;
	C[3].x3 = x4; C[3].y3 = y4; C[3].z3 = z2;
	C[3].x4 = x4; C[3].y4 = y4; C[3].z4 = z1;

	C[4].x1 = x2; C[4].y1 = y2; C[4].z1 = z1; //bottom face
	C[4].x2 = x3; C[4].y2 = y3; C[4].z2 = z1;
	C[4].x3 = x3; C[4].y3 = y3; C[4].z3 = z2;
	C[4].x4 = x2; C[4].y4 = y2; C[4].z4 = z2;

	C[5].x1 = x1; C[5].y1 = y1; C[5].z1 = z1; //top face
	C[5].x2 = x4; C[5].y2 = y4; C[5].z2 = z1;
	C[5].x3 = x4; C[5].y3 = y4; C[5].z3 = z2;
	C[5].x4 = x1; C[5].y4 = y1; C[5].z4 = z2;

	C[0].faces = 6;

	return C;
} Cube* C = CubeInit(1000, 0, 1, 100, 100, 0.25);

TriBasedPyramid* PyramidInit(float sx, float sy, float sz, float h, float w, float d)
{
	TriBasedPyramid* T = new TriBasedPyramid[4];

	float x1 = sx;  float y1 = sy;
	APP_VIRTUAL_TO_NATIVE_COORDS(x1, y1);
	float x2 = sx - w; float y2 = sy;
	APP_VIRTUAL_TO_NATIVE_COORDS(x2, y2);
	float x3 = sx - (w / 2); float y3 = sy;
	APP_VIRTUAL_TO_NATIVE_COORDS(x3, y3);
	float x4 = sx - (w / 2); float y4 = sy - h;
	APP_VIRTUAL_TO_NATIVE_COORDS(x4, y4);
	float z1 = sz;
	float z2 = sz + d;
	float z3 = sz + (d / 2);

	T[0].x1 = x1; T[0].y1 = y1; T[0].z1 = z1; //bottom face
	T[0].x2 = x2; T[0].y2 = y2; T[0].z2 = z1;
	T[0].x3 = x3; T[0].y3 = y3; T[0].z3 = z2;

	T[1].x1 = x1; T[1].y1 = y1; T[1].z1 = z1; //front face
	T[1].x2 = x2; T[1].y2 = y2; T[1].z2 = z1;
	T[1].x3 = x4; T[1].y3 = y4; T[1].z3 = z3;

	T[2].x1 = x1; T[2].y1 = y1; T[2].z1 = z1; //left face
	T[2].x2 = x3; T[2].y2 = y3; T[2].z2 = z2;
	T[2].x3 = x4; T[2].y3 = y4; T[2].z3 = z3;

	T[3].x1 = x2; T[3].y1 = y2; T[3].z1 = z1; //right face
	T[3].x2 = x3; T[3].y2 = y3; T[3].z2 = z2;
	T[3].x3 = x4; T[3].y3 = y4; T[3].z3 = z3;

	T[0].faces = 4;
	return T;
} TriBasedPyramid* T = PyramidInit(0, 0, 1, 100, 100, 0.25);



void DrawCube(Cube* C, float r = 1.0f, float g = 1.0f, float b = 1.0f)
{

	for (int i = 0; i < C[0].faces; i++)
	{
		auto xy1 = Convert_3D_2D(C[i].x1, C[i].y1, C[i].z1, fov);
		auto xy2 = Convert_3D_2D(C[i].x2, C[i].y2, C[i].z2, fov);
		auto xy3 = Convert_3D_2D(C[i].x3, C[i].y3, C[i].z3, fov);
		auto xy4 = Convert_3D_2D(C[i].x4, C[i].y4, C[i].z4, fov);
		App::DrawLine(xy1.x, xy1.y, xy2.x, xy2.y, r, g, b);
		App::DrawLine(xy2.x, xy2.y, xy3.x, xy3.y, r, g, b);
		App::DrawLine(xy3.x, xy3.y, xy4.x, xy4.y, r, g, b);
		App::DrawLine(xy4.x, xy4.y, xy1.x, xy1.y, r, g, b);
	}
}

void DrawPyramid(TriBasedPyramid* T, float r = 1.0f, float g = 1.0f, float b = 1.0f)
{

	for (int i = 0; i < T[0].faces; i++)
	{
		auto xy1 = Convert_3D_2D(T[i].x1, T[i].y1, T[i].z1, fov);
		auto xy2 = Convert_3D_2D(T[i].x2, T[i].y2, T[i].z2, fov);
		auto xy3 = Convert_3D_2D(T[i].x3, T[i].y3, T[i].z3, fov);
		App::DrawLine(xy1.x, xy1.y, xy2.x, xy2.y, r, g, b);
		App::DrawLine(xy2.x, xy2.y, xy3.x, xy3.y, r, g, b);
		App::DrawLine(xy3.x, xy3.y, xy1.x, xy1.y, r, g, b);
	}
}


using namespace std; */

float x, y;
char bufferx[20];
char buffery[20];
char bufferz[20];
//double fov = M_PI_2;
Cube::Coords_3d bl_v;
Cube* C;

void Init()
{
	bl_v.x = 100;
	bl_v.y = 100;
	bl_v.z = 1;
	C = new Cube(bl_v);
}

void Render()
{
	snprintf(bufferx, sizeof(bufferx), "%.2f", C->shape[0].v1.x);
	snprintf(buffery, sizeof(buffery), "%.2f", C->shape[0].v1.y);
	snprintf(bufferz, sizeof(bufferz), "%.2f", C->shape[0].v1.z);
	char txt[50];
	std::strcpy(txt, bufferx);
	std::strcat(txt, ", ");
	std::strcat(txt, buffery);
	App::Print(0, 100, txt);
	App::Print(0, 50, bufferz);

	C->DrawCube();

}

void depth(float v, Cube* cube)
{
	/*
	int i = 0;
	while (i < cube[0].faces && (cube[0].z1 + v) > 0)
	{
		cube[i].z1 += v;
		cube[i].z2 += v;
		cube[i].z3 += v;
		cube[i].z4 += v;
		i++;
	}*/

	for (int i = 0; i < C->faces; i++)
	{
		cube->shape[i].v1.z += v;
		cube->shape[i].v2.z += v;
		cube->shape[i].v3.z += v;
		cube->shape[i].v4.z += v;
	}
}

void Shutdown()
{
	delete(C);
}

void move(int st, float v, Cube* cube)
{ // Use vectors instead of if statements - matrix class
	for (int i = 0; i < C->faces; i++)
	{
		if (st == 1) { cube->shape[i].v1.x += v; cube->shape[i].v2.x += v; cube->shape[i].v3.x += v; cube->shape[i].v4.x += v; }
		if (st == 2) { cube->shape[i].v1.y += v; cube->shape[i].v2.y += v; cube->shape[i].v3.y += v; cube->shape[i].v4.y += v; }
	}
}

void Update(float deltaTime)
{
	if (App::IsKeyPressed('W')) { move(2, 1.f, C); }
	if (App::IsKeyPressed('A')) { move(1, -1.f, C); }
	if (App::IsKeyPressed('S')) { move(2, -1.f, C); }
	if (App::IsKeyPressed('D')) { move(1, 1.f, C); }
	if (App::IsKeyPressed('E')) { depth(-1.f, C); }
	if (App::IsKeyPressed('Q')) { depth(1.f, C); }
}