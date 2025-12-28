#include "UJBoardRow.h"

    //A constructor with no parameters.
    template<typename T>
    UJBoardRow<T>::UJBoardRow(){

        //Initialise
        _arraySize = 0;
        _rowData = nullptr;
    }

    //A constructor with parameters.
    template<typename T>
    UJBoardRow<T>::UJBoardRow(int arraySize) : _arraySize(arraySize) {
        _rowData = new T[_arraySize];  // Allocate memory
        for (int i = 0; i < _arraySize; i++) {
            _rowData[i] = 0;
        }
    }


    //A copy constructor.
    template<typename T>
    UJBoardRow<T>::UJBoardRow(const UJBoardRow& other){
        _arraySize = other._arraySize;
        _rowData = new T[_arraySize];
        for(int i = 0; i <_arraySize; i++){
            _rowData[i] = other._rowData[i];
        }
    }

    //An underlying array of a size set by the user.
    template<typename T>
    void UJBoardRow<T>::setArraySize(int arraySize){
        delete[] _rowData;
        _arraySize = arraySize;
        _rowData = new T[_arraySize];
    }

    //Overload the indexing ([]) operator.
    template<typename T>
    T& UJBoardRow<T>::operator[](int index){
        return _rowData[index];
    }

    //Overload the assignment (=) operator.
    template<typename T>
    UJBoardRow<T>& UJBoardRow<T>::operator=(const UJBoardRow& other){
        if(this != &other){
            delete[] _rowData;
            _arraySize = other._arraySize;
            _rowData = new T[_arraySize];
            for(int i = 0; i < _arraySize; i++){
                _rowData[i] = other._rowData[i];
            }
        }
        return *this;
    }

    //Destructor
    template<typename T>
    UJBoardRow<T>::~UJBoardRow(){
        delete[] _rowData;
    }


    // Display function for UJBoardRow
    template<typename T>
    void UJBoardRow<T>::display() const {
        for (int i = 0; i < _arraySize; ++i) {
            std::cout << _rowData[i] << " ";  // Print each element followed by a space
        }
        std::cout << std::endl;  // New line after the row is displayed
    }

