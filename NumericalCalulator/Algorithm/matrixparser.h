#ifndef MATRIXPARSER_H
#define MATRIXPARSER_H
#include <memory>
#include <vector>
#include "Common/matrix.h"

template <typename T, typename sizeT = size_t>
std::shared_ptr<matrix<T, sizeT>> SingleRowmatrixParser(std::string expression);

template <typename T, typename sizeT = size_t>
std::shared_ptr<matrix<T, sizeT>> matrixParser(std::string expression);

#endif // MATRIXPARSER_H
