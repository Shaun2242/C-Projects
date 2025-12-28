#include <iostream>
#include <string>

using namespace std;

int main()
{
    //Variable Declaration
    const char OptionA = 'A' , OptionB = 'B';
    char ChosenOption;
    double Accuracy;
    int CompletedExercises;
    string result;

    //Options Menu Display
        cout << "Choose One Of These Two Options" << '\n'
             << endl;

        cout << "Options" << '\t'
             << "Selection" << endl;

        cout << "OptionA" << '\t'
             << OptionA << endl;

        cout << "OptionB" << '\t'
             << OptionB << '\n'
             << endl;

        //Prompt User To Enter Option
        cout << "Enter Option"  << endl;

        //Take in input
        cin >> ChosenOption;

        //Switch case
        switch (ChosenOption){
            case OptionA:

                //Prompt User To Enter Accuracy Score
                cout <<"Enter the accuracy score of a machine learning model" << endl;
                //Take In Input
                cin >> Accuracy;

                //If Statement
                if ( Accuracy >= 0 && Accuracy < 50){
                    cout << "Low accuracy! Consider retraining the model" << endl;
                } else if (Accuracy >= 50 && Accuracy < 70){
                    cout << "Moderate accuracy. Room for improvement" << endl;
                }else if (Accuracy >= 70 && Accuracy < 90){
                    cout << "Good accuracy. Your model is performing well"<< endl;
                }else if (Accuracy >= 90 && Accuracy <= 100){
                    cout << "Excellent accuracy. Well done!" << endl;
                }else {
                    cout << "Incorrect Input/Out Of Range Input" << endl;
                }

                break;

            case OptionB:

                //Prompt User To Enter VPL exercises
                cout << "Enter the number of VPL exercises you have completed throughout the semester" <<endl;
                ////Take In Input
                cin >> CompletedExercises;

               //Use Of The Condition Operator (?:)
               result = (CompletedExercises < 5) ? "The more VPL exercises you successfully complete, the higher your chances of obtaining a perfect practical mark" : "Keep it up";
               cout << result << endl;

                break;

             default:
                cout << "Incorrect Input" <<endl;
    }

    return 0;
}
