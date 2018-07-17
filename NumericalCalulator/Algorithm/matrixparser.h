#ifndef MATRIXPARSER_H
#define MATRIXPARSER_H
#include <memory>
#include <vector>
#include "Common/matrix.h"

std::shared_ptr<matrix> SingleRowmatrixParser(std::string expression);

/*this function is used to analyse an expression with many pairs of '[' and ']', and return a pointer to a matrix */

std::shared_ptr<matrix> matrixParser(std::string expression);

#endif // MATRIXPARSER_H
