#ifndef UJEDGEFILTER_H_INCLUDED
#define UJEDGEFILTER_H_INCLUDED

#include "UJFilter.h"

class UJEdgeFilter : public UJFilter
{
public:
    UJEdgeFilter();
    ~UJEdgeFilter();

    void applyFilter(CCImage &object, int intNumPasses) override;

private:
    void initializeKernel();  //  kernel initialization is moved to a private
};

#endif // UJEDGEFILTER_H_INCLUDED
