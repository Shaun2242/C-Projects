#ifndef GAMESPACE_H_INCLUDED
#define GAMESPACE_H_INCLUDED
#include <vector>

//Defining namespace
namespace GameSpace{

    // Function to generate pseudo-random numbers
    void generateRandomNumbers(std::vector<int>& numbers, unsigned int count,unsigned int min,unsigned int max);

    // Function to compute and print out the values at the fifth difficulty level
    void computeFifthDifficultyLevel(const std::vector<int>& numbers);

    // Function to check if the product exists inside the vector
    bool checkWinCondition(const std::vector<int>& numbers, int scalar);

}

#endif // GAMESPACE_H_INCLUDED
