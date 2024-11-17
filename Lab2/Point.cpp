#include "Point.h"

istream& operator>>(istream& is, Point& point) {
    is >> point.x >> point.y;
    return is;
}

ostream& operator<<(ostream& os, const Point& point) {
    os << "(" << point.x << ", " << point.y << ")";
    return os;
}