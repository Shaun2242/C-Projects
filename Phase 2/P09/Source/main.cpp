#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>

#include "StationList.h"

using namespace std;

int main(int argc, char** argv)
{
    string txtFile = "data/stations.txt";
    string binFile = "data/stations.bin";

    int intRank = atoi(argv[1]);   // Read the argument

    // Create Object
    StationList newList(txtFile);

    // Write Binary File
    newList.exportEvenStationsToBinary(binFile);

    // Count Number of Stations in Binary File
    cout << newList.countStationsFromBinary(binFile) << endl;

    // Use Command Line Argument
    if(intRank == 0){
        cout << newList.calcAveStartCloseFromBinary(binFile) << endl;
    }else{
        cout << newList.fetchByRank(binFile, intRank);
    }

    return 0;
}
