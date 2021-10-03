#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#ifndef P
#define P
class Point {
private:
    int ind;
    int x;
    int y;
    int z;
public:
    Point() {
        ind = 0;
        x = 0;
        y = 0;
        z = 0;
    }
    Point(int x_, int y_, int z_) {
        x = x_;
        y = y_;
        z = z_;
        ind = x * y * z;
    }
    Point(Point& b) {
        x = b.x;
        y = b.y;
        z = b.z;
        ind = b.ind;
    }
    Point& operator=(const Point& b);
    friend std::ostream& operator<<(std::ostream& out, const Point& p);
    bool operator==(const Point& b);
    bool operator>(const Point& b);
    bool operator<(const Point& b);
};
#endif