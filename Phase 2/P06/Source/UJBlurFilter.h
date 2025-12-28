#ifndef UJBLURFILTER_H_INCLUDED
#define UJBLURFILTER_H_INCLUDED

#include "UJFilter.h"

class UJBlurFilter : public UJFilter
{
public:
    UJBlurFilter();
    ~UJBlurFilter();  // Add destructor

    void applyFilter(CCImage &object, int intNumPasses) override; // Use override keyword

private:
    void initializeKernel();  // Move kernel initialization to a private method
};

#endif // UJBLURFILTER_H_INCLUDED
