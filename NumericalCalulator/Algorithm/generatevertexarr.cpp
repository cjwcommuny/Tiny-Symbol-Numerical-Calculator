#include "generatevertexarr.h"

std::vector<Point> generateVertexArr(const LinkList &polynomial)
{
    const double xMax = 5000;
    const double yMax = 5000;
    const double segmentNum = 3000;
    double xSegment = xMax / segmentNum;
    double x, y;
    std::vector<Point> vertexArr;
    for (int i = 0; i < segmentNum; ++i) {
        x = i * xSegment;
        y = polynomial.compute(x);
        if (x > DBL_MAX || y > DBL_MAX) {//overflow
            break;
        }
        vertexArr.push_back(Point(x, y));
    }
    return vertexArr;
}
