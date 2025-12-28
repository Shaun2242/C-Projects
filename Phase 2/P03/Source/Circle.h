#ifndef CIRCLE_H_INCLUDED
#define CIRCLE_H_INCLUDED

#include "Emoticon.h"
#include "Emoticon.cpp"

// Forward declaration
class Emoticon;

namespace emoticon {

class Circle {
public:
    Circle(UJPixel colour);
    void draw(int centerY, int centerX, int radius, UJPixel** colour);
private:
    UJPixel _colour;
};
}


#endif // CIRCLE_H_INCLUDED
