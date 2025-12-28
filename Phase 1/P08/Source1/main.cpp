#include "terrainSpace.h"
#include <iostream>

using namespace std;
using namespace TerrainSpace;

int main(int argc, char* argv[]) {
    if (argc != 6) {
        cerr << "Usage: " << argv[0] << " <rows> <cols> <numObstacles> <numMines> <numEnergy>\n";
        return 1;
    }

    int numRows = atoi(argv[1]);
    int numCols = atoi(argv[2]);
    int numObstacles = atoi(argv[3]);
    int numMines = atoi(argv[4]);
    int numEnergy = atoi(argv[5]);

    //Call function
    playGame(numRows, numCols, numObstacles, numMines, numEnergy);

    return 0;
}
