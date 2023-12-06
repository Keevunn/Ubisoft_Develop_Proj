#include "stdafx.h"
#include "MatrixHelper.h"
#include <stdexcept>



Matrix Matrix::add(Matrix& matB)
{
    if (rows != matB.rows || cols != matB.cols) {
        throw std::invalid_argument("Matrices must have the same dimensions for addition");
    }

    Matrix results(rows,cols);
    for (size_t row = 0; row < rows; row++)
    {
        for (size_t col = 0; col < cols; col++)
        {
            results.data[row][col] = data[row][col] + matB.data[row][col];
        }
    }

    return results;
}

Matrix Matrix::dot(Matrix& matB)
{
    if (cols != matB.rows) {
        throw std::invalid_argument("Matrices not valid for dot multiplication");
    }

    Matrix results(rows, cols);
    for (size_t row = 0; row < rows; row++)
    {
        for (size_t colB = 0; colB < matB.cols; colB++)
        {
            for (size_t col = 0; col < cols; col++)
            {
                results.data[row][colB] += data[row][col] + matB.data[col][colB];
            }
        }
    }
    return results;
}
