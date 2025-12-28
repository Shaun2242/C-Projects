#include "mistSpace.h"
#include <iostream>

using namespace std;
using namespace MistSpace;

int main(int argc, char* argv[]) {
    if (argc != 5) {
        cerr << "Usage: " << argv[0] << " <numRows> <numCols> <batteryProbability> <wireProbability>\n";
        return 1;
    }

    // Taking values through command line arguments
    int numRows = atoi(argv[1]);
    int numCols = atoi(argv[2]);
    double batteryProbability = atof(argv[3]);
    double wireProbability = atof(argv[4]);

 cout <<"Enter numRows numCols Battery and wire" << endl;
 cin >> numRows >> numCols >> batteryProbability >> wireProbability;


    char** world;
    createWorld(world, numRows, numCols, batteryProbability, wireProbability);

    int playerRow = numRows - 1;
    int playerCol = rand() % numCols;
    int movesLeft = 15;

    char move;
    while (true) {
        updateMist(world, playerRow, playerCol, numRows, numCols);
        displayWorld(world, numRows, numCols, playerRow, playerCol);

        cout << "Moves Left: " << movesLeft << endl;
        cout << "Enter move (W/A/S/D to move, Q to quit): ";
        cin >> move;

        if (!moveOperator(world, playerRow, playerCol, movesLeft, move, numRows, numCols)) {
            cout << "Invalid move!" << endl;
        }

        if (isVictory(world, playerRow, playerCol, numRows)) {
            cout << "Congratulations! You found the switch!" << endl;
            break;
        }

        if (isDefeat(movesLeft, world, playerRow, playerCol)) {
            std::cout << "Game over!" << std::endl;
            break;
        }
    }

     cleanWorld(world, numRows);

    return 0;
}
