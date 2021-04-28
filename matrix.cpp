#include "matrix.h"

Matrix::Matrix(unsigned int s)
{
    size = s;
    data.resize(size);
    for (size_t i = 0; i < size; i++)
    {
        data[i].resize(size);
    }
}

Matrix::~Matrix()
{
    for (size_t i = 0; i < data.size(); i++)
    {
        data[i].clear();
    }
    data.clear();
}
