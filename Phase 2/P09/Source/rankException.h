#ifndef RANKEXCEPTION_H_INCLUDED
#define RANKEXCEPTION_H_INCLUDED

#include <exception>
#include <string>

using namespace std;

class rankException : public exception {
public:
    // Constructor
    rankException(const string& errorMessage);

    // What function
    const char* what() const noexcept override;

private:
    string _errorMessage;
};

#endif // RANKEXCEPTION_H_INCLUDED
