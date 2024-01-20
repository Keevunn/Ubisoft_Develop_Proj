//------------------------------------------------------------------------
// CubeTest.cpp
//------------------------------------------------------------------------

#include "stdafx.h"

//------------------------------------------------------------------------
#include <windows.h> 
#define _USE_MATH_DEFINES
#include <math.h>  
//------------------------------------------------------------------------
#include "App/app.h"
//------------------------------------------------------------------------
#include "Geometry.h"
#include "Object.h"
#include "Camera.h"
#include "Spawner.h"
//------------------------------------------------------------------------

shape square_mesh{ {
		face{
			vertex{{-20,-20,1}},
			vertex{{-20, 20,1}},
			vertex{{20, 20,1}},
			vertex{{20,-20,1}}}
} };
shape cube_mesh{ {
		face{vertex{{-20, -20, 20, 1}}, vertex{{-20, 20, 20, 1}}, vertex{{20, 20, 20, 1}}, vertex{{20,-20, 20, 1}}}, //front face
		face{vertex{{-20, -20, -20, 1}}, vertex{{-20, 20, -20, 1}}, vertex{{20, 20, -20, 1}}, vertex{{20, -20, -20, 1}}}, //back face

		face{vertex{{-20, -20, 20, 1}}, vertex{{-20, 20, 20, 1}}, vertex{{-20, 20, -20, 1}}, vertex{{-20, -20, -20, 1}}}, //left face
		face{vertex{{20, -20, 20, 1}}, vertex{{20, 20, 20, 1}}, vertex{{20, 20, -20, 1}}, vertex{{20, -20, -20, 1}}}, //right face

		face{vertex{{-20, 20, 20, 1}}, vertex{{-20, 20, -20, 1}}, vertex{{20, 20, -20, 1}}, vertex{{20, 20, 20, 1}}}, //top face
		face{vertex{{-20, -20, 20, 1}}, vertex{{-20, -20, -20, 1}}, vertex{{20, -20, -20, 1}}, vertex{{20,-20, 20, 1}}}, //bottom face
} };
coordinate start_pos{ {APP_VIRTUAL_WIDTH / 2, APP_VIRTUAL_HEIGHT/2, 1} }, velocity{ {1, 0, 0} };
float orientation;

object cube{ cube_mesh, coordinate{{0, 0, 600, 1}} };

camera cam{ coordinate{{0, 0, 0}}, 0, 0, 0 };

constexpr int fov = 180;
matrix screen{ {{
	{fov, 0, 0, 1024 / 2},
	{0, fov, 0, 768 / 2},
	{0, 0, fov, 0},
	{0, 0, 0, 1}
}} };

Spawner cubeSpawner{ screen, cam, cube_mesh };

// INIT
void Init()
{

}

// UPDATE
void Update(float deltaTime)
{
	coordinate vec = 2 * coordinate::unit(static_cast<float>(std::rand() % 360));
	start_pos += vec;
	orientation = lerp(-2, 2, ((std::rand() % 100) / 100.f));
	rotate(square_mesh, orientation);

	deltaTime /= 1000;
	cubeSpawner.update(deltaTime);
	
	if (App::IsKeyPressed('W'))
	{
		cube.velocity = { {0, 50, 0} };
		cube.update(deltaTime);
	} if (App::IsKeyPressed('S'))
	{
		cube.velocity = { {0, -50, 0} };
		cube.update(deltaTime);
	} if (App::IsKeyPressed('A'))
	{
		cube.velocity = { {-50, 0, 0} };
		cube.update(deltaTime);
	} if (App::IsKeyPressed('D'))
	{
		cube.velocity = { {50, 0, 0} };
		cube.update(deltaTime);
	} if (App::IsKeyPressed('Q'))
	{
		cube.velocity = { {0, 0, -100} };
		cube.update(deltaTime);
	} if (App::IsKeyPressed('E'))
	{
		cube.velocity = { {0, 0, 100} };
		cube.update(deltaTime);
	}
	else
	{
		cube.velocity = { {0, 0, 0} };
		cube.update(deltaTime);
	}
	cubeSpawner.update(deltaTime);

}

//START DRAWING MULTIPLE ON THE SCREEN MAKE ENEMY MESH AND A SPAWNER
// RENDER

//On screen (visible) -> break down shape to faces -> face visible? - > draw face -> shading for face
void Render()
{
	drawat(start_pos, square_mesh);
	char buffer[80];
	//sprintf(buffer, "(%.3f,%.3f)", start_pos[0], start_pos[1]);
	//App::Print(100, 80, buffer);
	cubeSpawner.gen_object();
	cubeSpawner.render();

	edges lines = cube.getedges();
	edges worldEdges;
	//for each (edge e in lines)
	//{
	//	coordinate w1 = screen * cam.projection(e.first);
	//	coordinate w2 = screen * cam.projection(e.second);
	//	edge worldE = { w1, w2 };
	//	if (!existsin(worldE, worldEdges))
	//	{ 
	//		worldEdges.push_back(worldE); // Check if edge exists in worldEdges
	//		App::DrawLine(w1[0], w1[1], w2[0], w2[1]);
	//	}
	//	
	//}
	//fillFace(worldEdges);  - try drawing each face individually then shading each face

	sprintf(buffer, "(%.3f,%.3f,%.3f) %d", cube.position[0], cube.position[1], cube.position[2], cube.isVisible());
	App::Print(100, 100, buffer);
}

// SHUTDOWN
void Shutdown()
{
	return;
}


