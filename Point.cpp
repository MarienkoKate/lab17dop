#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "Point.h"

Point& Point :: operator=(const Point& b) {
    x = b.x;
    y = b.y;
    z = b.z;
    ind = b.ind;
    return *this;
}
std::ostream& operator<<(std::ostream& out, const Point& p) {
    out << "x = " << p.x << std::endl;
    out << "y = " << p.y << std::endl;
    out << "z = " << p.z << std::endl;
    return out;
}
bool Point :: operator==(const Point& b) {
    if (x == b.x && y == b.y && z == b.z) return true;
    else return false;
}
bool Point :: operator>(const Point& b) {
    if (ind > b.ind) return true;
    else return false;
}
bool Point :: operator<(const Point& b) {
    if (ind < b.ind) return true;
    else return false;
}
