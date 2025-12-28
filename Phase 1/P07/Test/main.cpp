#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>
#define NDEBUG
#include <cassert>

using namespace std;

int main()
{
     string Name;
    bool Correct = false;

    cout << "Welcome to the lie detector game  ";
    system("pause");

    cout << "Please enter your special person's name" << endl;
//    cin.ignore(100,'d');
       cin >> Name;


    while (Name != "Deneo" && Name != "deneo")
    {
        Correct = false;
        cout << "FALSE" << ": please try again" << endl;
        cout << "Please enter your special person's name" << endl;
        cin >> Name;
    }

   assert(Correct = true);
   cout << "TRUE , LOVE YOU SWEETIE! GOODNIGHT :)" << endl;


    return 0;
}
