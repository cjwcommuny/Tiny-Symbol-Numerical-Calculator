#include "generatevertexarr.h"
#include <iostream>

std::vector<Point> generateVertexArr(const LinkList &polynomial)
{
    const double xMax = 500;
    const double yMax = 500;
    const double segmentNum = 300;
    double xSegment = xMax / segmentNum;
    double x, y;
    std::vector<Point> vertexArr;
    std::cout << "polynomial: " << std::endl;
    polynomial.print();
    std::cout << "polynomial end " << std::endl;
    for (int i = 0; i < segmentNum; ++i) {
        x = i * xSegment;
        y = polynomial.compute(x);
        std::cout << "x: " << x << " y: " << y << std::endl;
        if (x > DBL_MAX || y > DBL_MAX) {//overflow
            break;
        }
        vertexArr.push_back(Point(x, y));
    }
    std::cout << "=============== generate VertexArr test ===========" << std::endl;
    //polynomial.print();
    for (auto point: vertexArr) {
        std::cout << "X: " << point.getX() << " Y: " << point.getY() << std::endl;
    }
    std::cout << "=============== generate VertexArr test end===========" << std::endl;
    return vertexArr;
}
