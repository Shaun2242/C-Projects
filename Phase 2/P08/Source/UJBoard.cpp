#include "UJBoard.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

    //All the necessary constructors.
    UJBoard::UJBoard(){
        _rows = 0;
        _boardRows = nullptr;
    }

UJBoard::UJBoard(int intRows, int rowSize) : _rows(intRows) {
    _boardRows = new UJBoardRow<int>*[_rows];
    for (int i = 0; i < _rows; i++) {
        _boardRows[i] = new UJBoardRow<int>(rowSize);
        for (int j = 0; j < rowSize; j++) {
            (*_boardRows[i])[j] = 0;
        }
    }
}


    UJBoard::UJBoard(const UJBoard& other){
        _boardRows = new UJBoardRow<int>*[_rows];
        for(int i = 0; i < _rows; i++){
            _boardRows[i] = new UJBoardRow<int>(*this->_boardRows[i]);
        }
    }


    //Set size of rows for the board dynamically
    void UJBoard::setSize(int intRows,int intRowSize){

    for (int i = 0; i < _rows; i++){
        delete _boardRows[i];
    }
    delete[] _boardRows;

    _rows = intRows;
    _boardRows = new UJBoardRow<int>*[_rows];
    for(int i = 0;i < _rows; i++){
        _boardRows[i] = new UJBoardRow<int>(intRowSize);
    }

}

    //Overload the indexing ([]) operator.
    UJBoardRow<int>& UJBoard::operator[](int index){
        return *_boardRows[index];
    }

// Overload the () operator
void UJBoard::operator()(unsigned int seed) {
    srand(seed);

    // Randomize values in the 2D array with values from 0 to 9
    for (int r = 0; r < _rows; r++) {
        for (int c = 0; c < _rows; c++) {
            (*_boardRows[r])[c] = rand() % 10;  // Assign a random value between 0 and 9
        }
    }

    // Now, swap values in the 2D array
    for (int r = 0; r < _rows; r++) {
        for (int c = 0; c < _rows; c++) {
            // Random location for swapping
            int rR = rand() % _rows;
            int rC = rand() % _rows;

            // Swapping values
            int temp = (*_boardRows[r])[c];
            (*_boardRows[r])[c] = (*_boardRows[rR])[rC];
            (*_boardRows[rR])[rC] = temp;
        }
    }
}

    //Overload the assignment operator (=)
 UJBoard& UJBoard::operator=(const UJBoard& other) {
        if(this != &other){
            for(int i = 0; i < _rows; i++){
                delete[] _boardRows[i];
            }
            delete[] _boardRows;

            //Copy size
            _rows = other._rows;

            //Copy array data
            _boardRows = new UJBoardRow<int>*[_rows];
            for(int i = 0; i < _rows; i++){
                //deep copy
                _boardRows[i] = new UJBoardRow<int>(*other._boardRows[i]);
            }
        }
        return *this;
    }

    std::ostream& operator<<(std::ostream& os, const UJBoard& board) {
        for (int i = 0; i < board._rows; ++i) {
            os << *(board._boardRows[i]) << std::endl;  // Correctly use the overloaded operator
        }
        return os;
    }

    // Display the entire board (optional, can use operator<<)
    void UJBoard::displayBoard() const {
        std::cout << *this;  // Using the overloaded operator<<
    }

    UJBoard::~UJBoard(){

    for (int i = 0; i < _rows; i++){
        delete _boardRows[i];
    }
    delete[] _boardRows;
    }
