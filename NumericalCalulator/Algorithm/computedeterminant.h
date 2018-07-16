#ifndef COMPUTEDETERMINANT_H
#define COMPUTEDETERMINANT_H
#include "Common/matrix.h"

template <typename T, typename sizeT = size_t>
T ComputeDeterminant(matrix<T> &sourceMatrix);

template <typename T, typename sizeT = size_t>
T ComputeSubDeterminant(matrix<T> &sourceMatrix);

template <typename T, typename sizeT = size_t>
matrix<T> GenerateMinor(matrix<T> &sourceMatrix, sizeT i, sizeT j);
#endif // COMPUTEDETERMINANT_H
