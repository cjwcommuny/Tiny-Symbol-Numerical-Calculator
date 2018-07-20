#ifndef SOLVELINEAR_H
#define SOLVELINEAR_H

#endif // SOLVELINEAR_H
#include "Common/matrix.h"

using namespace std;
#include <memory>
#include <vector>
#include "Common/matrix.h"

shared_ptr<matrix> LUdecompose(shared_ptr<matrix> &M, shared_ptr<matrix> &b);
