#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#ifndef ES
#define ES
#include "EmptySet.h"

class EmptySet : public setException {
public:
    EmptySet() :setException() {
        text = "intersection with empty string";
    }
    std::string what() { return text; }

};


#endif
