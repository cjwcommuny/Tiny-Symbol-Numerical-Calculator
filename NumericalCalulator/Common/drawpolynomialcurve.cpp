#include "drawpolynomialcurve.h"

vector<Point> generatePolynomialPoint(const LinkList &polynomial, int start, int end, int step, int winodwHeight, int windowWidth)
{
    vector<Point> result;
    int stepCurve = (end - start) / windowWidth * step;
    double y;
    std::cout << "start,end,stepCurve: " << start << " "<< end << " " << stepCurve << std::endl;
    for (int x = start; x < end; x += stepCurve) {
        //std::cout << x << " " << polynomial.compute(x) << std::endl;
        result.push_back(Point(x, polynomial.compute(x)));
    }
    //sort(result.begin(), result.end());
    return result;
}
