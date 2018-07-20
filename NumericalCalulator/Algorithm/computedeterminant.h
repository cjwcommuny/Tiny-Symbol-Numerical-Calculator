#ifndef COMPUTEDETERMINANT_H
#define COMPUTEDETERMINANT_H
#include "Common/matrix.h"

double computeDeterminant(const matrix &sourceMatrix);

matrix GenerateMinor(const matrix &sourceMatrix, size_t i, size_t j);

#endif // COMPUTEDETERMINANT_H
