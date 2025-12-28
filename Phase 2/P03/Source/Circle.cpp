
#include "Circle.h"
#include <cmath>

using namespace std;

namespace emoticon {

Circle::Circle(UJPixel colour) : _colour(colour) {}

void Circle::draw(int centerY, int centerX, int radius, UJPixel** colour) {
    for (int y = 0; y < 100; y++) {
        for (int x = 0; x < 100; x++) {
            if (std::sqrt(std::pow(centerY - y, 2) + std::pow(centerX - x, 2)) <= radius) {
                colour[y][x] = _colour;
            }
        }
    }
}

}
