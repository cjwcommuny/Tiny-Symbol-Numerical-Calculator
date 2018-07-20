#ifndef POINT_H
#define POINT_H


class Point
{
public:
    Point();
    Point(double x, double y): _x(x), _y(y) {}
    double getX() const {return _x;}
    double getY() const {return _y;}
    void setX(double x) {_x = x;}
    void setY(double y) {_y = y;}
    bool operator<=(const Point &other) const {return getX() <= other.getX();}
private:
    double _x;
    double _y;
};

#endif // POINT_H
