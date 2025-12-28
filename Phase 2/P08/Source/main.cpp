#include <iostream>
#include "UJBoard.h"

using namespace std;

int main()
{
    int rows;
    int cols;

    //Ask user for size of the board
    cout << "Please enter number of rows: ";
    cin >> rows;
    cols = rows;

    //Create UJBoard object using param constructor
    UJBoard board(rows, cols);

    //Randomize board value and swap them
    board(1337);

    //Display the board
    cout << "Randomized Board:\n" << board;

    return 0;
}
