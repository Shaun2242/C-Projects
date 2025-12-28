#include "Emoticon.h"
#include "Circle.h"
#include "Rectangel.h"
#include <iostream>
#include <fstream>
#include <memory>
using namespace emoticon;

int main() {
    Emoticon emoji;
    emoji.drawNeutralFace();

     // Output the PPM image to a file
    std::ofstream outFile("neutral_face.ppm");
    if (outFile.is_open()) {
        outFile << emoji.toPPM();
        outFile.close();
        std::cout << "Image saved to neutral_face.ppm" << std::endl;
    } else {
        std::cerr << "Unable to open file for writing." << std::endl;
        return ERROR_RANGE;
    }

    // Output the PPM image to the standard output
    std::cout << emoji.toPPM();

    return SUCCESS;
}
