#include <iostream>
#include <cstdlib>
#include "cellula.h"
#include <iomanip>

//namespace
//{
//    //Helper function
//    int RangeFunction(int *val,int index)
//    {
//
//    std::cin >> val[index];
//    if (val[index] != 0 or val[index] != 1)
//       {
//        std::cout << "Value out of bounds. Please enter 1s and 0s only";
//       }
//    }
//}

namespace CellularSpace
{

//Function for option 1
int InputNumberOfRounds(int nRounds)
{
    //Take in number of rounds from user
    std::cin >> nRounds;

    //Return number of rounds
    return nRounds;
}

//Function for option 2
int RandomArrayValues(int *cells,int arraySize)
{
  for (int i = 0; i < arraySize; i++)
  {
      //assign random 0's and 1's
      cells[i] = rand() % 2;

      //display the random values
      std:: cout << std::setw(2) << cells[i];
  }
std::cout << std::endl;
}


//Function for option 3
int ManualArrayValues(int *cells, int arraySize) {

    // Manual input of 0s and 1s
    std::cout << "Please enter " << arraySize << " values of zeros and ones separated by spaces: " << std::endl;

    for (int i = 0; i < arraySize; ++i) {
        std::cin >> cells[i];
        if (cells[i] != 0 && cells[i] != 1) {
            std::cerr << "One or more values out of bounds. Please enter 1s and 0s only" << std::endl;
            }
    }
}

//Function for option 4
int DisplayCellRounds(int nRounds,int arraySize, int *cells)
{
    //round loop
for (int r = 1; r <= nRounds; ++r){
        std::cout << "Round: " << r << "\n" << std::endl;

    //values loop
for(int i = 0; i < arraySize; ++i){

        //For handling the edges
        int leftNeighbor = (i == 0) ? cells[arraySize - 1] : cells[i - 1];
        int rightNeighbor = (i == arraySize - 1) ? cells[0] : cells[i + 1];

        // Pattern conditions
        if (leftNeighbor == 1 && cells[i] == 1 && rightNeighbor == 1) {
            cells[i] = 0;
        } else if (leftNeighbor == 1 && cells[i] == 1 && rightNeighbor == 0) {
            cells[i] = 0;
        } else if (leftNeighbor == 1 && cells[i] == 0 && rightNeighbor == 1) {
            cells[i] = 0;
        } else if (leftNeighbor == 1 && cells[i] == 0 && rightNeighbor == 0) {
            cells[i] = 1;
        } else if (leftNeighbor == 0 && cells[i] == 1 && rightNeighbor == 1) {
            cells[i] = 1;
        } else if (leftNeighbor == 0 && cells[i] == 1 && rightNeighbor == 0) {
            cells[i] = 1;
        } else if (leftNeighbor == 0 && cells[i] == 0 && rightNeighbor == 1) {
            cells[i] = 1;
        } else if (leftNeighbor == 0 && cells[i] == 0 && rightNeighbor == 0) {
            cells[i] = 0;
        }

             std::cout << std::setw(5) << cells[i];
    }

    std::cout << std::endl;
}

}

}
