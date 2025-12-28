#ifndef UJFILTER_H_INCLUDED
#define UJFILTER_H_INCLUDED

#include "CCImage.h"

class UJFilter
{
public:
    // applyFilter as a pure virtual function declaration
    virtual void applyFilter(CCImage &object, int intNumPasses) = 0;

protected:
    int _Kernel[3][3];
};

#endif // UJFILTER_H_INCLUDED
