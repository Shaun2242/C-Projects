#ifndef TERRAINSPACE_H_INCLUDED
#define TERRAINSPACE_H_INCLUDED

namespace TerrainSpace {

//Declarations


//Draw world table function and number of obstacles
    void createWorld(char**& world, int numRows, int numCols, int numObstacles, int numMines, int numEnergy);
    void displayWorld(char** world, int numRows, int numCols);

    //Deciding movements functions
    bool isValidMove(char** world, int numRows, int numCols, int newRow, int newCol);
    void movePlayer(char** world, int& playerRow, int& playerCol, int& energy, char direction, int numRows, int numCols);
    bool isVictory(int playerRow);
    bool isDefeat(char** world, int playerRow, int playerCol, int energy, int numRows, int numCols);
    void cleanWorld(char**& world, int numRows);
    void playGame(int numRows, int numCols, int numObstacles, int numMines, int numEnergy);
}

#endif // TERRAINSPACE_H_INCLUDED
