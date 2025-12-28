#ifndef UJBLURFILTER_H_INCLUDED
#define UJBLURFILTER_H_INCLUDED

#include "UJFilter.h"

class UJBlurFilter : public UJFilter{

public:
    UJBlurFilter();

     void applyFilter(CCImage &object, int intNumPasses);

private:


};

#endif // UJBLURFILTER_H_INCLUDED
