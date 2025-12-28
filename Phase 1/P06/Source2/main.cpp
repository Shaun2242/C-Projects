#include <iostream>
#include "Gamespace.h"
#include "Gamespace.cpp"
#include <cstdlib>

//Using namespaces
using namespace std;
using namespace GameSpace;

int main()
{
//Variable Declaration
vector<int> numbers;
int number, count, min, max ;
char Option;


 do {
        cout << "Menu:\n";
        cout << "A. Generate pseudo-random numbers\n";
        cout << "B. Compute fifth difficulty level\n";
        cout << "C. Check quests and objectives\n";
        cout << "X. Exit\n";
        cout << "Choose an option: ";
        cin >> Option;

   switch(Option) {
            case 'A':
            case 'a':{
                int count, min, max;

                cout << "Enter count, min, and max: ";
                cin >> count >> min >> max;

               generateRandomNumbers(numbers, count, min, max);


    // Display the generated random numbers
               cout << "Generated random numbers:";
               for (int num : numbers) {
               cout << " " << num;
    }
                cout << endl;

                break;
            }
            case 'B':
            case 'b':
                //Call function for checking if win or loss
                computeFifthDifficultyLevel(numbers);

                break;
            case 'c':
            case 'C': {

                int scalar;

                cout << "Enter scalar: ";
                cin >> scalar;

                if (checkWinCondition(numbers, scalar)) {
                    cout << "Congratulations! You win!\n";
                } else {
                    cout << "Sorry! You lose!\n";
                }
                break;
            }
            case 'X':
            case 'x':

                cout << "Exiting program.\n";
                break;
            default:

                cout << "Invalid option.\n";
        }
    } while (Option != 'X' && Option != 'x');

   return 0;
}
