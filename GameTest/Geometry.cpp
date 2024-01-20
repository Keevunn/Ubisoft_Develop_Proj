#include "stdafx.h"
#include "App/app.h"

#include "MatrixHelper.h"
#include "Geometry.h"

void drawline(vertex& p1, vertex& p2)
{
	constexpr unsigned int x = 0;
	constexpr unsigned int y = 1;
	App::DrawLine(p1[x], p1[y], p2[x], p2[y], 1, 1, 1);
}
void draw(face& f)
{
	for (auto v = f.begin(); v < (f.end() - 1); v++)
		drawline(*v, *(v + 1));
	drawline(f.back(), f.front());
}
void draw(shape& s)
{
	for (face& f : s)
		draw(f);
}
void moveby(shape& s, coordinate& v)
{
	for (face& f : s)
		for (vertex& p : f)
			p += v;
}
shape copyto(const shape& s, coordinate& p)
{
	shape o = s;
	moveby(o, p);
	return o;
}
void drawat(coordinate& p, shape& s)
{
	draw(copyto(s, p));
}
void rotate(shape& s, float theta)
{
	matrix rot_M = matrix::rotation(theta);
	for each (face f in s)
		for each (vertex p in f)
			p = rot_M * p;
}

//linear interpolation
float lerp(float a, float b, float f)
{
	return a * (1 - f) + b * f;
}

edges edgesof(face& f)
{
	edges e;
	for (auto v = f.begin(); v < (f.end() - 1); v++)
		// equivalent to appending an edge
		e.push_back(edge{ *v, *(v + 1) });
	e.push_back(edge{f.front(), f.back()});
	return e;
}
edges edgesof(shape& s)
{
	edges e;
	for (face f : s)
	{
		edges face_e = edgesof(f);
		e.insert(e.end(), face_e.begin(), face_e.end());
	}
	return e;
}

coordinate direction(edge& e)
{
	return e.second + (-e.first);
}

bool existsin(edge& e, edges& es)
{
	for (edge es_edge : es)
	{
		if ((es_edge.first == e.first && es_edge.second == e.second) || (es_edge.first == e.second && es_edge.second == e.first))
			return true;
	}
	return false;
}


bool visible(coordinate pt)
{
	return false;
}

coordinate normal(face f)
{
	return coordinate();
}



void fillFace(edges lines)
{
	float y_min = 10000, x_min = 10000;
	float y_max = 0, x_max = 0;
	
	line_equations equations;
	for (edge line : lines)
	{
		if (line.first[1] < y_min) { y_min = line.first[1]; }
		if (line.first[1] > y_max) { y_max = line.first[1]; }
		if (line.first[0] < x_min) { x_min = line.first[0]; }
		if (line.first[0] > x_max) { x_max = line.first[0]; }

		if (line.second[1] < y_min) { y_min = line.second[1]; }
		if (line.second[1] > y_max) { y_max = line.second[1]; }
		if (line.second[0] < x_min) { x_min = line.second[0]; }
		if (line.second[0] > x_max) { x_max = line.second[0]; }

		

		if ((line.second)[0] - (line.first)[0] != 0)
		{
			float m = ((line.second)[1] - (line.first)[1]) / ((line.second)[0] - (line.first)[0]);
			float c = (line.first)[1] - m * ((line.first)[0]);
			equations.push_back(line_info{ m, c });
		}
	}

	intersections intersect_coords;
	for (float x = x_min+1; x < x_max-1; x++)
	{
		coordinate e1;
		coordinate e2;
		size_t count = 0;
		for (float y = y_min; y < y_max - 1; y++)
		{
			for (line_info l : equations)
			{
				float check_y = (l.first * x) + l.second;
				if (check_y == y)
				{
					if (count == 0)
					{
						e1 = vertex{ {x, y, 1} };
						count++;
					}
					else if (count == 1)
					{
						e2 = vertex{ {x, y, 1} };
						count++;
					}
				}
			}
		}
		if (count == 2)
			App::DrawLine(e1[0], e1[1], e2[0], e2[1], 1, 0, 0);
	}
}