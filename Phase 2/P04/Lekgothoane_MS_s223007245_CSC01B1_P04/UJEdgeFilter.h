#ifndef UJEDGEFILTER_H_INCLUDED
#define UJEDGEFILTER_H_INCLUDED

#include "UJFilter.h"

class UJEdgeFilter : public UJFilter{

public:
    UJEdgeFilter();

     void applyFilter(CCImage &object, int intNumPasses);

private:


};

#endif // UJEDGEFILTER_H_INCLUDED
