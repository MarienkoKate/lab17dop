#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "setException.h"
#include "EmptySet.h"
#include "Point.h"
#include "set.h"


int main() {
    
    Point a(1, 2, 3);
    Point b(2, 3, 4);
    Point c(6, 7, 8);
    Point d(2, 3, 4);
    Point i(d);
    std::cout << i;
    set<Point> ab;
    set<Point> cd;
    set<Point> abcd;
    ab.insert(b);
    ab.insert(a);
    cd.insert(c);
    cd.insert(d);
   // cout << ab;
    try {

       abcd = ab.intersect(cd);

    }
    catch (EmptySet& a)
    {
        std::cout << a.what() <<"\n";
    }
  
    std::cout << abcd;
}