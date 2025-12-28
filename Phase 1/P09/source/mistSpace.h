#ifndef MISTSPACE_H_INCLUDED
#define MISTSPACE_H_INCLUDED

namespace MistSpace {

    //Function declaration
    void createWorld(char**& world, int numRows, int numCols, double batteryProbability, double wireProbability);
    void displayWorld(char** world, int numRows, int numCols, int playerRow, int playerCol);
    bool isValidMove(int numRows, int numCols, int newRow, int newCol);
    bool moveOperator(char** world, int& playerRow, int& playerCol, int& movesLeft, char direction, int numRows, int numCols);
    void updateMist(char** world, int playerRow, int playerCol, int numRows, int numCols);
    bool isVictory(char** world, int playerRow, int playerCol, int numRows);
    bool isDefeat(int movesLeft, char** world, int playerRow, int playerCol);
    void cleanWorld(char**& world, int numRows);
}

#endif // MISTSPACE_H_INCLUDED
