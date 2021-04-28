#ifndef MATRIX_H
#define MATRIX_H

#include <QVector>

class Matrix
{
public:
    unsigned int size;
    Matrix(unsigned int);
    ~Matrix();
    QVector < QVector<bool> > data;
};

#endif // MATRIX_H
