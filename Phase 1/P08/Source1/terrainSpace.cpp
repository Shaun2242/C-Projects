#include "terrainSpace.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

namespace TerrainSpace
{


 void createWorld(char**& world, int numRows, int numCols, int numObstacles, int numMines, int numEnergy) {

        // Set up random seed
        srand(time(nullptr));

        // Allocating memory for world
        world = new char*[numRows];
        for (int r = 0; r < numRows; ++r) {
            world[r] = new char[numCols];
            for (int c = 0; c < numCols; ++c) {
                world[r][c] = '.';
            }
        }

        // Placing obstacles randomly
        for (int i = 0; i < numObstacles; ++i) {
            int row = rand() % numRows;
            int col = rand() % numCols;
            if (world[row][col] == '.') {
                world[row][col] = '#';
            } else {
                --i;
            }
        }

        // Place mines randomly
        for (int i = 0; i < numMines; ++i) {
            int row = rand() % numRows;
            int col = rand() % numCols;
            if (world[row][col] == '.') {
                world[row][col] = 'M';
            } else {
                --i;
            }
        }

        // Place energy units randomly
        for (int i = 0; i < numEnergy; ++i) {
            int row = rand() % numRows;
            int col = rand() % numCols;
            if (world[row][col] == '.') {
                world[row][col] = 'T';
            } else {
                --i;
            }
        }
    }

    void displayWorld(char** world, int numRows, int numCols) {
        for (int i = 0; i < numRows; ++i) {
            for (int j = 0; j < numCols; ++j) {
                std::cout << world[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }

    bool isValidMove(char** world, int numRows, int numCols, int newRow, int newCol) {
        if (newRow < 0 || newRow >= numRows || newCol < 0 || newCol >= numCols)
            return false;
        if (world[newRow][newCol] == '#' || world[newRow][newCol] == 'M')
            return false;
        return true;
    }

    void movePlayer(char** world, int& playerRow, int& playerCol, int& energy, char direction, int numRows, int numCols) {
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
        }

        if (isValidMove(world,numRows, numCols, newRow, newCol)) {
            // Move the player
            world[playerRow][playerCol] = '.';
            playerRow = newRow;
            playerCol = newCol;
            world[playerRow][playerCol] = 'P';

            // Decrease energy
            energy--;

            // Check if player moved over energy
            if (world[playerRow][playerCol] == 'T') {
                energy += 5;
                world[playerRow][playerCol] = 'P';
            }
        }
    }

    bool isVictory(int playerRow) {
        return playerRow == 0;
    }

    bool isDefeat(char** world, int playerRow, int playerCol, int energy, int numRows, int numCols) {
        return energy <= 0 || world[playerRow][playerCol] == 'M';
    }

    void cleanWorld(char**& world, int numRows) {
        for (int i = 0; i < numRows; ++i) {
            delete[] world[i];
        }
        delete[] world;
        world = nullptr;
    }

    void playGame(int numRows, int numCols, int numObstacles, int numMines, int numEnergy) {
        char** world;
        createWorld(world, numRows, numCols, numObstacles, numMines, numEnergy);

        int playerRow = numRows - 1;
        int playerCol = rand() % numCols;
        int energy = 7;

        char move;
        while (!isVictory(playerRow) && !isDefeat(world, playerRow, playerCol, energy, numRows, numCols)) {
            displayWorld(world, numRows, numCols);
            std::cout << "Energy: " << energy << std::endl;
            std::cout << "Enter move (W/A/S/D): ";
            std::cin >> move;
            movePlayer(world, playerRow, playerCol, energy, move,numRows,numCols);
        }

        if (isVictory(playerRow)) {
            std::cout << "Congratulations! You made it to the top!" << std::endl;
        } else {
            std::cout << "Game Over!" << std::endl;
        }

        cleanWorld(world, numRows);
    }
}
