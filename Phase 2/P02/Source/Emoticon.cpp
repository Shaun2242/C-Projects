#include "Emoticon.h"
#include "Circle.h"
#include "Rectangle"
#include <iostream>
#include <sstream>
#include <cmath>


namespace emoticon {

// Define the static const UJPixel DEFAULT_COLOUR outside the class
const UJPixel Emoticon::DEFAULT_COLOUR = {255, 255, 255};

Emoticon::Emoticon() : Emoticon(DEFAULT_ROWS, DEFAULT_COLS, DEFAULT_COLOUR) {}

Emoticon::Emoticon(int intRows, int intCols, UJPixel pixelColour) {
    _alloc(intRows, intCols, pixelColour);
}

Emoticon::Emoticon(const Emoticon& emojObject) {
    _alloc(emojObject._rows, emojObject._cols, emojObject.DEFAULT_COLOUR);
    _clone(emojObject);
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

void Emoticon::drawImoji(int intCRow, int intCCol, int intRadius, UJPixel pixelColour) {
    for (int r = 0; r < _rows; r++) {
        for (int c = 0; c < _cols; c++) {
            if (_distance(r, intCRow, c, intCCol) <= intRadius) {
                _pixelColour[r][c] = pixelColour;
            }
        }
    }
}

void Emoticon::drawNeutralFace() {
    // Draw face
    drawImoji(_rows / 2, _cols / 2, 40, {255, 255, 0});

    //Draw nose
    for (int c = _cols / 2 - 5; c <= _cols / 2 + 5; ++c) {
    drawImoji(_rows / 2, c, 1, {0, 0, 0});
    }


    // Draw eyes
    drawImoji(_rows / 2 - 15, _cols / 2 - 15, 5, {0, 0, 255});
    drawImoji(_rows / 2 - 15, _cols / 2 + 15, 5, {0, 0, 255});

    // Draw mouth
    for (int r = _rows / 2 + 10; r <= _rows / 2 + 15; r++) {
        for (int c = _cols / 2 - 15; c <= _cols / 2 + 15; c++) {
            _pixelColour[r][c] = {255, 255, 255};
        }
    }
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
    for (int r = 0; r < _rows; r++) {
        delete[] _pixelColour[r];
    }
    delete[] _pixelColour;
    _pixelColour = nullptr;
}

}
