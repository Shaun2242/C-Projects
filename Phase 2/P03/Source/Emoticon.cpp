#include "Emoticon.h"
#include "Emoticon.cpp"
#include <iostream>
#include <sstream>
#include <cmath>

using namespace std;

namespace emoticon {

// Define the static const UJPixel DEFAULT_COLOUR outside the class
const UJPixel Emoticon::DEFAULT_COLOUR = {255, 255, 255};

//Deligation
Emoticon::Emoticon() : Emoticon(DEFAULT_ROWS, DEFAULT_COLS, DEFAULT_COLOUR, {255, 255, 0}, {0, 0, 0}) {}

Emoticon::Emoticon(int intRows, int intCols, UJPixel pixelColour, UJPixel circleColour, UJPixel rectangleColour){
    _alloc(intRows, intCols, pixelColour);

    // Dynamically allocate Circle and Rectangle objects
    _leftEye = new Rectangle(rectangleColour);
    _rightEye = new Rectangle(rectangleColour);
    _nose = new Rectangle(rectangleColour);
    _mouth = new Rectangle({255 ,255 ,255});
    _face = new Circle(circleColour);
}

Emoticon::Emoticon(const Emoticon& emojObject) {
    _alloc(emojObject._rows, emojObject._cols, emojObject.DEFAULT_COLOUR);
    _clone(emojObject);

    // Copy the Circle and Rectangle objects (deep copy)
    _leftEye = new Rectangle(*emojObject._leftEye);
    _rightEye = new Rectangle(*emojObject._rightEye);
    _nose = new Rectangle(*emojObject._nose);
    _mouth = new Rectangle(*emojObject._mouth);
    _face = new Circle(*emojObject._face);
}

Emoticon::~Emoticon() {
    _dealloc();
}

std::string Emoticon::toPPM() {
    std::stringstream ssPPM;
    ssPPM << "P3" << std::endl
          << _cols << ' ' << _rows << std::endl
          << 255 << std::endl;
    for (int r = 0; r < _rows; r++) {
        for (int c = 0; c < _cols; c++) {
            ssPPM << _pixelColour[r][c].red << ' '
                  << _pixelColour[r][c].green << ' '
                  << _pixelColour[r][c].blue << ' ';
        }
        ssPPM << std::endl;
    }
    return ssPPM.str();
}

/*void Emoticon::drawImoji(int intCRow, int intCCol, int intRadius, UJPixel pixelColour) {
    for (int r = 0; r < _rows; r++) {
        for (int c = 0; c < _cols; c++) {
            if (_distance(r, intCRow, c, intCCol) <= intRadius) {
                _pixelColour[r][c] = pixelColour;
            }
        }
    }
}*/

void Emoticon::drawNeutralFace() {
    // Draw face using the Circle object
    _face->draw(_rows / 2, _cols / 2, 40, _pixelColour);

    // Draw left eye
    _leftEye->draw(_rows / 2 - 15, _cols / 2 - 20, _rows / 2 - 10, _cols / 2 - 15, _pixelColour);

    // Draw right eye
    _rightEye->draw(_rows / 2 - 15, _cols / 2 + 15, _rows / 2 - 10, _cols / 2 + 20, _pixelColour);

    // Draw nose
    _nose->draw(_rows / 2 - 5, _cols / 2 - 2, _rows / 2 + 5, _cols / 2 + 2, _pixelColour);

    // Draw mouth
    _mouth->draw(_rows / 2 + 20, _cols / 2 - 15, _rows / 2 + 25, _cols / 2 + 15, _pixelColour);
}


void Emoticon::_alloc(int intRows, int intCols, UJPixel defaultColout) {
    _rows = intRows;
    _cols = intCols;

    _pixelColour = new UJPixel*[_rows];
    for (int r = 0; r < _rows; r++) {
        _pixelColour[r] = new UJPixel[_cols];
        for (int c = 0; c < _cols; c++) {
            _pixelColour[r][c] = defaultColout;
        }
    }
}

void Emoticon::_clone(const Emoticon& emojObject) {
    for (int r = 0; r < _rows; r++) {
        for (int c = 0; c < _cols; c++) {
            _pixelColour[r][c] = emojObject._pixelColour[r][c];
        }
    }
}

double Emoticon::_distance(double intY1, double intY2, double intX1, double intX2) {
    return std::sqrt(std::pow(intY2 - intY1, 2) + std::pow(intX2 - intX1, 2));
}

void Emoticon::_enforceRange(int intArgs, int Min, int Max) {
    if (intArgs < Min || intArgs > Max) {
        std::cerr << "Out Of Range" << std::endl;
        exit(ERROR_RANGE);
    }
}

void Emoticon::_dealloc() {
    // Deallocate the Circle and Rectangle objects
    delete _leftEye;
    delete _rightEye;
    delete _nose;
    delete _mouth;
    delete _face;

    for (int r = 0; r < _rows; r++) {
        delete[] _pixelColour[r];
    }
    delete[] _pixelColour;
    _pixelColour = nullptr;
}

}
