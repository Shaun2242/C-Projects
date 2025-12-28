#include <iostream>
#include <string>
#include <cctype>
#include <cstdlib>

using namespace std;

const int SUCCESSFUL_TERMINATION = 0;

// Function to output geometric sequence of n terms
void outputGeometricSequence() {

    cout << "Enter the number of terms: ";
    int n = 0;
    cin >> n;

    while (cin.fail() || n <= 1) {
        cin.clear();
        cin.ignore(100, '\n');
        cerr << "Error: You must enter an integer greater than 1: ";
        cin >> n;
    }

    cout << "Enter the common difference: ";
    int d = 0;
    cin >> d;

    while (cin.fail() || d <= 1) {
        cin.clear();
        cin.ignore(100, '\n');
        cerr << "Error: You must enter an integer greater than 1: ";
        cin >> d;
    }

    int intPrevTerm = 2;
    cout << intPrevTerm << ", ";

    for (int i = 0; i < n; i++) {
        intPrevTerm *= d;
        cout << intPrevTerm << ", ";
    }
}

// Function to count sequence
void countingSequence(int intStart, int intStop, int intStep) {

    for (int i = intStart; i <= intStop; i += intStep) {
        cout << i << " ";
    }
}

// Function to reverse a string
void reverseString(string& str) {

    string strReverseSeq = "";
    for (char c : str) {
        strReverseSeq = c + strReverseSeq;
    }
    cout << strReverseSeq << endl;
}

int main() {
    bool blnContinue = true;
    char chOption = '\0';
    do {
        system("cls");
        cout << "Option A: Output Geometric Sequence of n Terms." << endl
             << "Option B: Counting Sequence." << endl
             << "Option C: Output a given string in reverse order." << endl
             << "Option X: Exit." << endl;
        cin >> chOption;
        switch (chOption) {
            case 'a':
            case 'A':
                outputGeometricSequence();
                break;
            case 'b':
            case 'B': {

                int intStart = 0, intStop = 0, intStep = 0;

                cout << "Enter a starting value: ";
                cin >> intStart;

                while (cin.fail() || intStart <= 1) {
                    cin.clear();
                    cin.ignore(100, '\n');
                    cerr << "Error: You must enter an integer greater than 1: ";
                    cin >> intStart;
                }

                cout << "Enter a stopping value: ";
                cin >> intStop;

                while (cin.fail() || intStop <= 1) {
                    cin.clear();
                    cin.ignore(100, '\n');
                    cerr << "Error: You must enter an integer greater than 1: ";
                    cin >> intStop;
                }

                cout << "Enter a step value: ";
                cin >> intStep;

                while (cin.fail() || intStep <= 1) {
                    cin.clear();
                    cin.ignore(100, '\n');
                    cerr << "Error: You must enter an integer greater than 1: ";
                    cin >> intStep;
                }

                countingSequence(intStart, intStop, intStep);
                break;
            }
            case 'c':
            case 'C': {

                string strCharSequence = "";
                cout << "Enter a character sequence: ";
                cin.ignore();
                getline(cin, strCharSequence);
                reverseString(strCharSequence);
                break;
            }
            case 'x':
            case 'X': {

                cout << "Bye." << endl;
                blnContinue = false;
                break;
            }
            default:
                cout << "Invalid choice. Please enter a valid option.\n";
                break;
        }
        cout << endl;
        cout << "Press Enter to continue";
        cin.ignore();
        cin.get();
        system("cls");
    } while (blnContinue);
    return SUCCESSFUL_TERMINATION;
}
