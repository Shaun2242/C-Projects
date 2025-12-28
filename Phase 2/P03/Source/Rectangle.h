#ifndef RECTANGLE_H_INCLUDED
#define RECTANGLE_H_INCLUDED

#include "Emoticon.h"
//using namespace emoticon;

namespace emoticon {

class Rectangle {
public:
    Rectangle(UJPixel colour);
    void draw(int topY, int leftX, int bottomY, int rightX, UJPixel** colour);
private:
    UJPixel _colour;
};

}

#endif // RECTANGLE_H_INCLUDED
