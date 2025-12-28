#include "Gamespace.h"
#include <iostream>
#include <cstdlib>

//Defining namespace
namespace GameSpace{
using namespace std;

 //Definition of the function for generating random numbers
    void generateRandomNumbers(vector<int>& numbers, int count, int min, int max) {

        for (int i = 0; i < count; ++i) {
            int randomNum = min + rand() % (max - min + 1);
            numbers.push_back(randomNum);
        }
    }

    //Definition of function for computing the fifth difficulty level
    void computeFifthDifficultyLevel(const std::vector<int>& numbers) {
        vector<int> fifthLevelNumbers;
        for (int num : numbers) {

            // Multiplying each number by 2^5 = 32 for fifth difficulty level
            fifthLevelNumbers.push_back(num * 32);
        }
        cout << "Values at the fifth difficulty level: ";
        for (int num : fifthLevelNumbers) {
            cout << num << " ";
        }
        cout << std::endl;
    }

    //Definition of function for checking if win or loss
   bool checkWinCondition(const vector<int>& numbers, int scalar) {
    int product = 1;
    for (int i = 0; i < 5; ++i) {
        product *= scalar;
    }

    // Check if the product exists in the vector
    for (int num : numbers) {
        if (num == product) {
            cout << "Congratulations! You win!\n";
            return true;
        }
    }

    cout << "Sorry! You lose!\n";
    return false;
         }
    }
