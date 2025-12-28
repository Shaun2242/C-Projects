#include <iostream>
#include <string>

using namespace std;

// Function to validate user input as an integer
int getValidIntegerInput() {
    int input;
    while (!(cin >> input)) {
        // Clear the error flag to allow for new input
        cin.clear();
        // Discard the invalid input using the buffer
        while (cin.get() != '\n') {
            continue;
        }
        cout << "Invalid input. Please enter a valid integer: ";
    }
    return input;
}
// Function to calculate Fibonacci sequence
void generateFibonacci(int n) {
    int a = 0, b = 1;
    cout << "Fibonacci Sequence: ";
    for (int i = 0; i < n; ++i) {
        cout << a << ", ";
        int temp = a;
        a = b;
        b = temp + b;
    }
    cout << endl;
}

// Function to calculate the sum of first n Fibonacci numbers
int sumFibonacci(int n) {
    int sum = 0, a = 0, b = 1;
    for (int i = 0; i < n; ++i) {
        sum += a;
        int temp = a;
        a = b;
        b = temp + b;
    }
    return sum;
}

// Function to create palindrome from a string
string createPalindrome(string input) {
    string palindrome = input;
    for (int i = input.length() - 1; i >= 0; --i) {
        palindrome += input[i];
    }
    return palindrome;
}

int main() {
    char choice;
    do {
        cout << "Menu:\n";
        cout << "A. Generate Fibonacci Sequence\n";
        cout << "B. Calculate Sum of Fibonacci Numbers\n";
        cout << "C. Create Palindrome\n";
        cout << "X. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 'A':
            case 'a': {
                // Get user input for the number of terms in the Fibonacci sequence
                cout << "Enter the number of terms in the Fibonacci sequence: ";
                int terms = getValidIntegerInput();
                // Call the function to generate and output the Fibonacci sequence
                generateFibonacci(terms);
                break;
            }
            case 'B':
            case 'b': {
                // Get user input for the value of n to calculate the sum of Fibonacci numbers
                cout << "Enter the value of n to calculate the sum of first n Fibonacci numbers: ";
                int n = getValidIntegerInput();
                // Call the function to calculate and output the sum of Fibonacci numbers
                cout << "Sum of first " << n << " Fibonaccci numbers: " << sumFibonacci(n) << endl;
                break;
            }
            case 'C':
            case 'c': {
                // Get user input for the string to create a palindrome
                cout << "Enter a string to create a palindrome: ";
                string input;
                cin >> input;
                // Call the function to create and output the palindrome
                cout << "Palindrome: " << createPalindrome(input) << endl;
                break;
            }
            case 'X':
            case 'x':
                cout << "Exiting program. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please enter a valid option.\n";
        }
    } while (choice != 'X' && choice != 'x');

    return 0;
}
