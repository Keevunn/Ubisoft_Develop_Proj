#pragma once

#include <vector>
#include <algorithm>

#include "MatrixHelper.h"

using vertex = coordinate;
using face = std::vector<vertex>;
using shape = std::vector<face>;

void drawline(vertex& p1, vertex& p2);
void draw(face& f);
void draw(shape& s);
void moveby(shape& s, coordinate& v);
shape copyto(const shape& s, coordinate& p);
void drawat(coordinate& p, shape& s);
void rotate(shape& s, float theta);

float lerp(float a, float b, float f);

using edge = std::pair<coordinate, coordinate>;
using edges = std::vector<edge>;

edges edgesof(face& f);
edges edgesof(shape& s);
coordinate direction(edge& e);
bool existsin(edge& e, edges& es);

bool visible(coordinate pt);
coordinate normal(face f);

using line_info = std::pair<float, float>;
using line_equations = std::vector<line_info>;
using intersections = std::vector<edge>;

void fillFace(edges lines);
