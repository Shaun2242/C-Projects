#include "CCImage.h"

#include <sstream>

CCImage::CCImage() : CCImage(NUM_ROWS, NUM_COLS){}

CCImage::CCImage(unsigned int intRows, unsigned int intCols){
    allocMemory(intRows, intCols);
}

CCImage::CCImage(const CCImage& objOriginal) : CCImage(objOriginal._intRows, objOriginal._intCols){
    // Clone - Deep Copy
    clone(objOriginal);
}

CCImage::~CCImage(){
    deallocMemory();
}

// Accessors / Getters

unsigned int CCImage::getRows() const{
    return _intRows;
}

unsigned int CCImage::getCols() const{
    return _intCols;
}

RGBColour CCImage::getColour(unsigned int intRow, unsigned int intCol) const{
    /**  
	** TODO: Always Check to make sure intRow and intCol are in range
	**/ 
    return _recPixels[intRow][intCol];
}

// Mutators / Setters

void CCImage::setImageColour(RGBColour recColour){
    for(int r = 0; r < _intRows; r++){
        for(int c = 0; c < _intCols; c++){
            _recPixels[r][c] = recColour;
        }
    }
}

void CCImage::setPixelColour(unsigned int intRow, unsigned int intCol, RGBColour recColour){
    // Check to make sure intRow and intCol are in range
    _recPixels[intRow][intCol] = recColour;
}

string CCImage::toPPM() const{
    stringstream ssPPM;
    ssPPM << "P3" << endl
          << _intCols << " " << _intRows << endl
          << "255" << endl;
    for(unsigned int r = 0; r < _intRows; r++){
        for(unsigned int c = 0; c < _intCols; c++){
            ssPPM << _recPixels[r][c].intRed << " "
                  << _recPixels[r][c].intGreen << " "
                  << _recPixels[r][c].intBlue << " ";
        }
        ssPPM << endl;
    }
    return ssPPM.str();
}

// Utility Methods
void CCImage::allocMemory(unsigned int intRows, unsigned int intCols){
    _intRows = intRows;
    _intCols = intCols;
    _recPixels = new RGBColour*[intRows];
    for(unsigned int r = 0; r < intRows; r++){
        _recPixels[r] = new RGBColour[intCols];
        for(unsigned int c = 0; c < intCols; c++){
            _recPixels[r][c] = DEFAULT_COLOUR;
        }
    }
}

void CCImage::deallocMemory(){
    for(unsigned int r = 0; r < _intRows; r++){
        delete [] _recPixels[r];
    }
    delete [] _recPixels;
    _recPixels = nullptr;
}

void CCImage::clone(const CCImage& objOriginal){
    for(unsigned int r = 0; r < _intRows; r++){
        for(unsigned int c = 0; c < _intCols; c++){
            _recPixels[r][c].intRed = objOriginal._recPixels[r][c].intRed;
            _recPixels[r][c].intGreen = objOriginal._recPixels[r][c].intGreen;
            _recPixels[r][c].intBlue = objOriginal._recPixels[r][c].intBlue;
        }
    }
}
