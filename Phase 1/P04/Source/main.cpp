#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int main()
{
    //Variable Declaration
    int nTerms = 0;
    double commonDifference = 0;
    bool blnContinue = true;
    char option = '\0';
    int startVal = 0, stopVal = 0, i;
    double stepVal = 0;
    string userWord;

    do
    {
        cout << "Menu:" << endl;
        cout << "A. Print Geometric Sequence" << endl;
        cout << "B. Print Counting Sequence" << endl;
        cout << "C. Print Reverse String" << endl;
        cout << "X. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> option;

        switch(option)
        {
         //Option A logic
         case ('a'):
         case ('A'):{
             cout<<"Enter Number Of Terms"<<endl;
             cin >> nTerms;

             //Input validation
             while (cin.fail() || nTerms <= 0) {
             cin.clear();
             cin.ignore(100, '\n');
             cout << "Invalid input. Please enter a positive integer." << std::endl;
             cin >> nTerms;
        }

             cout<<"Enter Common Difference"<<endl;
             cin >> commonDifference;
             int x = 1;

             cout << "Your Geometric Sequence" << endl;
             while(nTerms != 0){
                cout << x << " ";
                x += commonDifference;
                nTerms = --nTerms;
                }
                cout <<endl;
                system("pause");
               system("cls");
              break;

            }

            //Option B logic
            case ('b'):
            case ('B'):{

                 cout << "Enter Start Value" << endl;
                 cin >> startVal;

                 cout << "Enter Step Value" << endl;
                 cin >> stepVal;

                 cout << "Enter Stop Value" << endl;
                 cin >> stopVal;

                for (int i = startVal; i <= stopVal; i += stepVal){
                cout << i << " ";
                }
                cout << endl;
               system("pause");
               system("cls");

                break;
               }
            //Option C logic
            case ('c'):
            case ('C'):{

            cout << "Enter Your Word" << endl;
            cin >> userWord;

            string newWord [userWord.length()];
            int i = userWord.length() -1;

            for (char a : userWord){
                newWord[i] = a;
                i--;
                }
            for(int c = 0 ; c < userWord.length(); c++){
                      cout << newWord[c];
                      }
                     cout << endl;
               system("pause");
               system("cls");

                break;
            }

           //Option x logic
            case ('x'):
            case ('X'):{
                cout << "Exiting program." << endl;
                 blnContinue = false;
                break;
            }
            default:
                cerr << "Invalid option. Please try again." << endl;
                blnContinue = false;
            }
          }while (blnContinue);

    return 0;
}

