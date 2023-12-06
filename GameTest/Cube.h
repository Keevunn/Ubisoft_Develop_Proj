//-----------------------------------------------------------------------------
// Cube.h
// Cube class
//-----------------------------------------------------------------------------
#ifndef _CUBE_H_
#define _CUBE_H_


//-----------------------------------------------------------------------------
// Cube
//-----------------------------------------------------------------------------

//Make shape class - face class 
class Cube
{
	public:
		struct Coords_2d
		{
			float x, y;
		};

		struct Coords_3d
		{
			float x, y, z;
		};

		struct CubeFace
		{ // Make an array of points for iteration
			Coords_3d v1, v2, v3, v4;
		};

		int faces = 6;
		CubeFace shape[6]; // make a pointer and memory allocation in constructor

		Coords_2d Convert_3D_2D(Coords_3d v, float fov);

		Cube(Coords_3d bl_v, float h = 100.f, float w = 100.f, float d = 1.f);
		
		Cube();

		void DrawCube(float r = 1.0f, float g = 1.0f, float b = 1.0f);
};

/* INHERITANCE EXAMPLE
class Face
{
protected:
	int vertices;
};

class Triangle:public Face
{
	Triangle()
	{
		vertices = 3;
	};
}; */


#endif