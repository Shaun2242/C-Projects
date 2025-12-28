#include "Emoticon.h"
#include "Circle.h"
#include "Rectangle.h"
#include <iostream>

using namespace emoticon;
using namespace std;

int main() {
    UJPixel emoticonColour = {255, 255, 255};
    UJPixel eyeColour = {0, 0, 0};
    UJPixel mouthColour = {255, 255, 255};

    Emoticon emoji(100, 100, emoticonColour, eyeColour, mouthColour);
    emoji.drawNeutralFace();

    // Output the PPM image to standard output
    cout << emoji.toPPM() << endl;

    return SUCCESS;
}
