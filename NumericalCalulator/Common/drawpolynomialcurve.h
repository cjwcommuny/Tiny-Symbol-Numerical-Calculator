#ifndef DRAWPOLYNOMIALCURVE_H
#define DRAWPOLYNOMIALCURVE_H
#include <vector>
#include "polynomial.h"
#include "point.h"
#include <algorithm>

vector<Point> generatePolynomialPoint(const LinkList &polynomial, int start, int end, int step, int winodwHeight, int windowWidth);

#endif // DRAWPOLYNOMIALCURVE_H
