#include <exception>
#include <iostream>
#include "RankException.h"

using namespace std;

// Constructor
rankException::rankException(const string& errorMessage) : _errorMessage(errorMessage) {}

// What function
const char* rankException::what() const noexcept {
    return _errorMessage.c_str();
}
