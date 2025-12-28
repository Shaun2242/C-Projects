#include "Rectangle.h"

using namespace std;

// Forward declaration
class Emoticon;

namespace emoticon {

Rectangle::Rectangle(UJPixel colour) : _colour(colour) {}

void Rectangle::draw(int topY, int leftX, int bottomY, int rightX, UJPixel** colour) {
    for (int y = topY; y <= bottomY; y++) {
        for (int x = leftX; x <= rightX; x++) {
            colour[y][x] = _colour;
        }
    }
}

}
