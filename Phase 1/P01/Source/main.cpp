#include <iostream>

using namespace std;

int main()
{
    //Variable Declaration
    const std::string Jan = "January", Feb = "February", Mar = "March", Apr = "April", May = "May", Jun = "June", Jul = "July", Aug = "August", Sep = "September", Oct = "October", Nov = "November", Dec = "December";
    double JanRev = 83, FebRev = 12, MarRev = 33, AprRev = 49, MayRev = 76, JunRev = 52, JulRev = 58, AugRev = 14, SepRev = 29, OctRev = 91, NovRev = 5, DecRev = 100;
    double AverageRev;
    const double ConversionFactor = 0.053;
    double ConvertedAverageRev;

    //Year Average Revenue Calculations
    AverageRev = (JanRev + FebRev + MarRev + AprRev + MayRev + JunRev + JulRev + AugRev + SepRev + OctRev + NovRev + DecRev)/12;

    //Conversion From Rands To Dollars
    ConvertedAverageRev = AverageRev * ConversionFactor;

    //Display Table
    cout << Jan << " "
         << Feb << " "
         << Mar << " "
         << Apr << " "
         << May << " "
         << Jun << " "
         << Jul << " "
         << Aug << " "
         << Sep << " "
         << Oct << " "
         << Nov << " "
         << Dec << endl;

    cout << JanRev << "      "
         << FebRev << "       "
         << MarRev << "    "
         << AprRev << "    "
         << MayRev << "  "
         << JunRev << "   "
         << JulRev << "   "
         << AugRev << "     "
         << SepRev << "        "
         << OctRev << "      "
         << NovRev << "        "
         << DecRev << endl;



    //Display Average Revenues
    cout << "" << endl;
    cout << "Average Revenue In Rands: " << AverageRev << endl;
    cout << "Average Revenue In Dollars: " << ConvertedAverageRev << endl;

    return 0;
}
