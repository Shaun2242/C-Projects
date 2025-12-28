#include "UJEdgeFilter.h"

UJEdgeFilter::UJEdgeFilter() : UJFilter()
{
    initializeKernel();
}

UJEdgeFilter::~UJEdgeFilter() {}

void UJEdgeFilter::initializeKernel() {
    int tempArray[3][3] = {
        {-1, -1, -1},
        {-1, 10, -1},
        {-1, -1, -1}
    };

    for (int r = 0; r < 3; r++) {
        for (int c = 0; c < 3; c++) {
            _Kernel[r][c] = tempArray[r][c];
        }
    }
}

void UJEdgeFilter::applyFilter(CCImage &object, int intNumPasses)
{
    int intRows = object.getRows();
    int intCols = object.getCols();

    RGBColour** ImageCopy = new RGBColour*[intRows];
    for (int r = 0; r < intRows; r++) {
        ImageCopy[r] = new RGBColour[intCols];
        for (int c = 0; c < intCols; c++) {
            ImageCopy[r][c] = object.getColour(r, c);
        }
    }

    int sumR, sumG, sumB;
    int AveR, AveG, AveB;

    for (int i = 0; i < intNumPasses; i++) {
        for (int r = 1; r < intRows - 1; r++) {
            for (int c = 1; c < intCols - 1; c++) {
                sumR = sumG = sumB = 0;
                for (int rk = -1; rk <= 1; rk++) {
                    for (int ck = -1; ck <= 1; ck++) {
                        sumR += ImageCopy[r + rk][c + ck].intRed * _Kernel[rk + 1][ck + 1];
                        sumG += ImageCopy[r + rk][c + ck].intGreen * _Kernel[rk + 1][ck + 1];
                        sumB += ImageCopy[r + rk][c + ck].intBlue * _Kernel[rk + 1][ck + 1];
                    }
                }
                AveR = sumR / 9;
                AveG = sumG / 9;
                AveB = sumB / 9;

                object.setPixelColour(r, c, {AveR, AveG, AveB});
            }
        }
    }

    // Clean up dynamically allocated memory
    for (int r = 0; r < intRows; r++) {
        delete[] ImageCopy[r];
    }
    delete[] ImageCopy;
}
