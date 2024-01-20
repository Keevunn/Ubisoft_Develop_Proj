//-----------------------------------------------------------------------------
// MatrixHelper.h
// Matrix class
//-----------------------------------------------------------------------------
#pragma once

#include <array>

#include "App/AppSettings.h"
#include <cmath>


constexpr unsigned int _2D = 3;
constexpr unsigned int _3D = 4;
constexpr unsigned int dimensions = _3D;

//-----------------------------------------------------------------------------
// Coordinates
//-----------------------------------------------------------------------------

class coordinate {
public:
	float coord[dimensions];

	coordinate() {
		for (size_t i = 0; i < dimensions; i++)
			coord[i] = 0;
	};
	coordinate(std::array<float, dimensions> init) {
		for (size_t i = 0; i < dimensions; i++)
			coord[i] = init[i];
	};

	static coordinate unit(float theta);
	float dot(const coordinate& rhs);

	coordinate operator-() {
		return coordinate{ {-coord[0], -coord[1], -coord[2], -coord[3]} };
	};
	coordinate& operator+=(const coordinate& rhs) {
		for (size_t i = 0; i < dimensions; i++)
			coord[i] += rhs.coord[i];
		return *this;
	};
	coordinate& operator*=(float scalar) {
		for (size_t i = 0; i < dimensions; i++)
			coord[i] *= scalar;
		return *this;
	};
	coordinate operator+(coordinate& rhs) {
		coordinate r = *this;
		r += rhs;
		return r;
	};
	coordinate operator*(float scalar) {
		coordinate r = * this;
		r *= scalar;
		return r;
	};

	bool operator==(const coordinate& rhs) {
		bool equal = true;
		for (size_t i = 0; i < dimensions; i++)
			equal = equal && (coord[i] == rhs.coord[i]);
		return equal;
	};
	float operator[](unsigned int axis) {
		return coord[axis];
	};
};

coordinate operator*(float scalar, coordinate& rhs);

//-----------------------------------------------------------------------------
// Matrix
//-----------------------------------------------------------------------------
class matrix {
private:
	float data[dimensions][dimensions];

public:
	matrix() {
		for (size_t i = 0; i < dimensions; i++)
			for (size_t j = 0; j < dimensions; j++)
				data[i][j] = 0;
};
	matrix(std::array<std::array<float, dimensions>, dimensions> init) {
		for (size_t i = 0; i < dimensions; i++)
			for (size_t j = 0; j < dimensions; j++)
				data[i][j] = init[i][j];
	};

	coordinate applied(const coordinate& rhs);
	static matrix zero();
	static matrix identity();
	static matrix rotation(float theta);
	static matrix rotation_x(float theta);
	static matrix rotation_y(float theta);
	static matrix rotation_z(float theta);
	static matrix translation(coordinate v);

	matrix& operator=(const matrix& rhs) {
		for (size_t i = 0; i < dimensions; i++)
			for (size_t j = 0; j < dimensions; j++)
				data[i][j] = rhs.data[i][j];
		return *this;
	};
	matrix& operator+=(const matrix& rhs) {
		for (size_t i = 0; i < dimensions; i++)
			for (size_t j = 0; j < dimensions; j++)
				data[i][j] += rhs.data[i][j];
		return *this;
	};
	matrix& operator*=(const matrix& rhs) {
		matrix r = zero();
		for (size_t i = 0; i < dimensions; i++)
			for (size_t j = 0; j < dimensions; j++)
				for (size_t k = 0; k < dimensions; k++)
					r.data[i][j] += (data[i][k] * rhs.data[k][j]);
		*this = r;
		return *this;
	};
	matrix operator*(matrix& rhs) {
		matrix r = *this;
		r *= rhs;
		return r;
	};
	coordinate operator*(coordinate rhs) {
		matrix r = *this;
		return r.applied(rhs);
	};
};

