#ifndef UJBOARDROW_H_INCLUDED
#define UJBOARDROW_H_INCLUDED

#include <iostream>

template<typename T>
class UJBoardRow{
private:

    //An underlying array of a size set by the user.
    T* _rowData;
    int _arraySize;

public:

    //A constructor with no parameters.
    UJBoardRow();

    //A constructor with parameters.
    UJBoardRow(int arraySize);

    //A copy constructor.
    UJBoardRow(const UJBoardRow& other);

    //An underlying array of a size set by the user.
    void setArraySize(int arraySize);

    //Overload the indexing ([]) operator.
    T& operator[](int index);

    //Overload the assignment (=) operator.
    UJBoardRow& operator=(const UJBoardRow& other);

    //Display the board
    void display() const;

    //friend std::ostream& operator<<(std::ostream& os, const UJBoardRow<T>& row)
    friend std::ostream& operator<<(std::ostream& os, const UJBoardRow<int>& row) {
        for (int i = 0; i < row._arraySize; ++i) {
            os << row._rowData[i] << " ";  // Output each element
        }
        return os;  // Return the ostream
    }

    //Destructor
    ~UJBoardRow();

};


#include "UJBoardRow.tpp"
#endif // UJBOARDROW_H_INCLUDED
