#ifndef UJFILTER_H_INCLUDED
#define UJFILTER_H_INCLUDED

#include "CCImage.h"

class UJFilter
{

public:
    void applyFilter(CCImage &object, int intNumPasses);
protected:
    int _Kernel[3][3];

};

#endif // UJFILTER_H_INCLUDED
