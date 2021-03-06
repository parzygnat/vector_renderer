#ifndef POINT_H
#define POINT_H
#include <cmath>
#include <iostream>
struct Point {
    int x;
    int y;
    Point();
    Point(int x, int y);
    bool operator<(const Point& p2) const;
    bool distance_small(const Point& p2);
    Point operator-(const Point& other);
    Point operator*(const double& mul);
    bool operator<(const Point& other) {
        return x*1000 + y < other.x*1000 + other.y;
    }
};
#endif // POINT_H
