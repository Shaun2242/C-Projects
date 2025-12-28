#include <iostream>
#include <cstdlib>
#include <cstdlib>
//#include "cellula.cpp"
#include "cellula.h"

using namespace std;
using namespace CellularSpace;

int main(int argc, char* argv[])
{

    //use of command-line
   const int ARRARY_SIZE = 15;
   int* cellArray = new int[ARRARY_SIZE];

    //Variable declaration
    int option = 0;
//      int const DEAD = 0;
//    int const ALIVE = 1;

   //other variables
    int nRounds = 0;
    bool intialised = false;

  do
  {

    //Menu display
    cout << "Options Menu:" <<endl;
    cout << "1. Generate Random Values" << endl;
    cout << "2. Enter Values Manually" << endl;
    cout << "3. Display Rounds" << endl;
    cout << "4. Exit program" << endl;
    cin >> option;

   switch (option){
      case 1:
        {
            //Option 1 logic
            RandomArrayValues(cellArray,ARRARY_SIZE);
            intialised = true;
            system("pause");
                }
        break;

    case 2:
        {
           //Option 2 logic
          ManualArrayValues(cellArray,ARRARY_SIZE);
          intialised = true;
          system("pause");

          }
        break;

    case 3:
        {
        //Option 3 logic
         if (!intialised) {
                    cout << "Please initialize the array first." << endl;
                } else {
                    if (nRounds == 0) {
                        cout << "Enter Number Of Rounds" << endl;
                        cin >> nRounds;
                    }
                    if (nRounds > 0) {
                        DisplayCellRounds(nRounds, ARRARY_SIZE, cellArray);
                    }
                }
        }
        break;

    case 4:
        {
         cout << "Exiting..." << endl;
          system("pause");
          system("cls");
          return 0;
        }
        break;
    default:
        cout << "Invalid choice. Please try again." << endl;
        return 1;
   }

  }while(option != 5);

  //cleanup
    delete[] cellArray;
    cellArray = nullptr;
    system("pause");
    system("cls");
   return 0;

  }
