#ifndef GENERALPARSER_H
#define GENERALPARSER_H

#include <string>
#include <memory>
#include "Parameter/Parameter.h"
#include "Common/matrix.h"
#include "Common/functionname.h"
#include "Algorithm/matrixparser.h"
#include "Common/polynomial.h"
#include "Algorithm/computedeterminant.h"


std::shared_ptr<Parameter> generalParser(std::string expression);

std::string removeSpace(std::string expression);

FunctionType seperateComponent(const std::string &expression, std::vector<std::string> &component_out);

std::string removeComment(std::string expression);

#endif // GENERALPARSER_H
