#include "mistSpace.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

namespace MistSpace {

//Function definitions
    void createWorld(char**& world, int numRows, int numCols, double batteryProbability, double wireProbability) {
        srand(time(nullptr));

        world = new char*[numRows];
        for (int i = 0; i < numRows; ++i) {
            world[i] = new char[numCols];
            for (int j = 0; j < numCols; ++j) {
                double randVal = (double)rand() / RAND_MAX;
                if (i == 0 && j == rand() % numCols) {
                    world[i][j] = 'S';
                } else if (i == numRows - 1 && j == rand() % numCols) {
                    world[i][j] = 'O';
                } else if (randVal < batteryProbability) {
                    world[i][j] = 'B';
                } else if (randVal < wireProbability) {
                    world[i][j] = 'W';
                } else {
                    world[i][j] = '.';
                }
            }
        }
    }

    void displayWorld(char** world, int numRows, int numCols, int playerRow, int playerCol) {
        for (int i = 0; i < numRows; ++i) {
            for (int j = 0; j < numCols; ++j) {
                if (i == playerRow && j == playerCol) {
                    std::cout << "O ";
                } else {
                    std::cout << world[i][j] << " ";
                }
            }
            std::cout << std::endl;
        }
    }

    bool isValidMove(int numRows, int numCols, int newRow, int newCol) {
        return newRow >= 0 && newRow < numRows && newCol >= 0 && newCol < numCols;
    }

    bool moveOperator(char** world, int& playerRow, int& playerCol, int& movesLeft, char direction, int numRows, int numCols) {
        int newRow = playerRow;
        int newCol = playerCol;
        switch(direction) {
            case 'W':
                newRow--;
                break;
            case 'S':
                newRow++;
                break;
            case 'A':
                newCol--;
                break;
            case 'D':
                newCol++;
                break;
            case 'Q':
                return false;
        }

        if (!isValidMove(numRows, numCols, newRow, newCol)) {
            return false;
        }

        if (world[newRow][newCol] == 'W') {
            return false;
        }

        playerRow = newRow;
        playerCol = newCol;
        movesLeft--;

        return true;
    }

    void updateMist(char** world, int playerRow, int playerCol, int numRows, int numCols) {
        for (int i = 0; i < numRows; ++i) {
            for (int j = 0; j < numCols; ++j) {
                if (abs(i - playerRow) <= 1 && abs(j - playerCol) <= 1) {
                    world[i][j] = '.';
                } else {
                    world[i][j] = '?';
                }
            }
        }
    }

    bool isVictory(char** world, int playerRow, int playerCol, int numRows) {
        return world[playerRow][playerCol] == 'S';
    }

    bool isDefeat(int movesLeft, char** world, int playerRow, int playerCol) {
        return movesLeft <= 0 || world[playerRow][playerCol] == 'W';
    }

    void cleanWorld(char**& world, int numRows) {
        for (int i = 0; i < numRows; ++i) {
            delete[] world[i];
        }
        delete[] world;
        world = nullptr;
    }
}
