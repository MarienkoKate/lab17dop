//#include "EmptySet.h"
#ifndef S_E
#define S_E

class setException
{
protected:
    std::string text;

public:
    virtual std::string what() = 0;
};


#endif