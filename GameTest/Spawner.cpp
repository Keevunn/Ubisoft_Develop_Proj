#include "stdafx.h"
#include "App/AppSettings.h"

#include <cstdlib>
#include <vector>

#include "App/app.h"

#include "Spawner.h"

std::vector<object> Spawner::gen_object()
{
	int rand_x, rand_y;
	size_t objsToAdd = density - objs.size();
	for (size_t count = 0; count < objsToAdd; count++)
	{
		rand_x = x_range.first + (rand() % x_range.second);
		rand_y = y_range.first + (rand() % y_range.second);
		object o{ mesh, coordinate{{(float)rand_x, (float)rand_y, (float)z_point, 1}} };
		objs.push_back(o);
	}
	return objs;
}

void Spawner::update(float deltatime)
{
// VECTOR ITERATORS INCOMPATIBLE
	for (auto& o = objs.begin(); !objs.empty() && o != objs.end();)
	{
		if (!objs.empty())
		{
			o->velocity = { {0,0,-1000} };
			o->update(deltatime);
			if (!o->isVisible())
			{
				objs.erase(o);
			}
			else
				++o;
		}
	}
	
}

void Spawner::render()
{
	for each (object o in objs)
	{ 
		edges lines = o.getedges();
		edges worldEdges;
		for each (edge e in lines) // iterate over each face - face culling - use normal vector to determine direction
		{
			if (!existsin(e, worldEdges))
			{
				coordinate w1 = screen * cam.projection(e.first);
				coordinate w2 = screen * cam.projection(e.second);
				worldEdges.push_back(e); // Check if edge exists in worldEdges
				App::DrawLine(w1[0], w1[1], w2[0], w2[1]);
			}

		}
	}
	
}
