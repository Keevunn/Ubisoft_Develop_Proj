//-----------------------------------------------------------------------------
// MatrixHelper.h
// Matrix class
//-----------------------------------------------------------------------------
#include <vector>
#ifndef _MATRIXHELPER_H_
#define _MATRIXHELPER_H_


//-----------------------------------------------------------------------------
// Matrix
//-----------------------------------------------------------------------------

struct Coords_2d
{
	float x, y;
};

struct Coords_3d
{
	float x, y, z;
};

class Matrix
{
	size_t rows;
	size_t cols;
	std::vector<std::vector<float>> data;

	Matrix(size_t rows, size_t cols) : rows(rows), cols(cols), data(rows, std::vector<float>(cols,0)) {};
	Matrix(size_t rows, size_t cols, std::vector<std::vector<float>> data) : rows(rows), cols(cols), data(data) {};

	Matrix add(Matrix& matB);
	Matrix dot(Matrix& matB);

};

#endif