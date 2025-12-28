#ifndef EMOTICON_H_INCLUDED
#define EMOTICON_H_INCLUDED

#include <string>

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

//Forwarding declaration of derived class
class Circle;
class Rectangle;

class Emoticon {
public:

    // Constants
    static const int DEFAULT_ROWS = 100;
    static const int DEFAULT_COLS = 100;
    static const UJPixel DEFAULT_COLOUR;


    // No-args constructor
    Emoticon();
    // Parameterized constructor
    Emoticon(int intRows, int intCols, UJPixel pixelColour);
    // Copy constructor
    Emoticon(const Emoticon& emojObj);
    // Destructor
    ~Emoticon();

    // Drawing image functions
    std::string toPPM();
    void drawImoji(int intCRow, int intCCol, int intRadius, UJPixel pixelColour);
    void drawNeutralFace();

private:
    int _rows;
    int _cols;
    UJPixel** _pixelColour;
    void _alloc(int intRows, int intCols, UJPixel defaultColout);
    void _clone(const Emoticon& emojObject);
    double _distance(double intY1, double intY2, double intX1, double intX2);
    void _enforceRange(int intArgs, int Min, int Max);
    void _dealloc();
};

}

#endif // EMOTICON_H_INCLUDED
