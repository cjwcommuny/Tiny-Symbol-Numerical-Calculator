#ifndef MATRIXTRANSFORMATION_H
#define MATRIXTRANSFORMATION_H
#include <memory>
#include <vector>
#include "Common/matrix.h"

#endif // MATRIXTRANSFORMATION_H

std::shared_ptr<matrix> matrixTranspose(matrix &M);
std::shared_ptr<matrix> matrixInverse(matrix &M);
