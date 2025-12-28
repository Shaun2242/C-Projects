#ifndef EMOTICON_H_INCLUDED
#define EMOTICON_H_INCLUDED

#include <string>
#include "Circle.h"
#include "Rectangle.h"
#include <memory>

using namespace std;

// Forward declarations of the Circle and Rectangle classes
class Circle;
class Rectangle;

namespace emoticon {

enum StatusCode {
    ERROR_RANGE = -1,
    SUCCESS = 0
};

struct UJPixel {
    int red;
    int green;
    int blue;
};

class Emoticon {

private:
    int _rows;
    int _cols;
    UJPixel** _pixelColour;
    Rectangle* _leftEye;
    Rectangle* _rightEye;
    Rectangle* _nose;
    Rectangle* _mouth;
    Circle* _face;

    void _alloc(int intRows, int intCols, UJPixel defaultColour);
    void _clone(const Emoticon& emojObject);
    double _distance(double intY1, double intY2, double intX1, double intX2);
    void _enforceRange(int intArgs, int Min, int Max);
    void _dealloc();


public:

    // Constants
    static const int DEFAULT_ROWS = 100;
    static const int DEFAULT_COLS = 100;
    static const UJPixel DEFAULT_COLOUR;

    // No-args constructor
    Emoticon();
    // Parameterized constructor
    Emoticon(int intRows, int intCols, UJPixel pixelColour, UJPixel circleColour, UJPixel rectangleColour);
    // Copy constructor
    Emoticon(const Emoticon& emojObj);
    // Destructor
    ~Emoticon();

    // Drawing image functions
    std::string toPPM();

  //  void drawImoji(int intCRow, int intCCol, int intRadius, UJPixel pixelColour);
    void drawNeutralFace();

};

}

#endif // EMOTICON_H_INCLUDED
