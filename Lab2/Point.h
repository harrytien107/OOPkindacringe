#pragma once
#include <iostream>
#include <cmath>

using namespace std;

class Point {
private:
    double x, y;

public:
    Point(double x = 0, double y = 0) : x(x), y(y) {}

    double getX() const { return x; }
    double getY() const { return y; }

    bool operator<(const Point& other) const {
        return sqrt(x * x + y * y) < sqrt(other.x * other.x + other.y * other.y);
    }

    friend istream& operator>>(istream& is, Point& point);
    friend ostream& operator<<(ostream& os, const Point& point);
};
