#ifndef GENERALPARSER_H
#define GENERALPARSER_H

#include <string>
#include "Common/matrix.h"
#include "Common/functionname.h"
#include "Algorithm/matrixparser.h"
#include "Common/polynomial.h"
#include "Algorithm/computedeterminant.h"


std::string generalParser(std::string expression);

std::string removeSpace(std::string expression);

FunctionType seperateComponent(const std::string &expression, std::vector<std::string> &component_out);

#endif // GENERALPARSER_H
