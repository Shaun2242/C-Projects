#ifndef UJBOARD_H_INCLUDED
#define UJBOARD_H_INCLUDED

#include "UJBoardRow.h"

class UJBoard{
private:

    //1-D array of a generic class UJBoardRow pointers.
    UJBoardRow<int>** _boardRows; //Composition
    int _rows;

public:

    //All the necessary constructors.
    UJBoard();
    UJBoard(int intRows, int rowSize);
    UJBoard(const UJBoard& other);
    ~UJBoard();

    //Set size of rows for the board dynamically
    void setSize(int intRows, int intRowSize);

    //Overload the indexing ([]) operator.
    UJBoardRow<int>& operator[](int index);

    //Overload the () operator
    void operator()(unsigned int seed);

    //Overload the assignment operator (=)
    UJBoard& operator=(const UJBoard& other);

    //Display board
    void displayBoard() const;

    //Overload the stream insertion operator (<<)
    friend std::ostream& operator<<(std::ostream& os, const UJBoard& board);

};

#endif // UJBOARD_H_INCLUDED
